#include "doc.h"
#include "page.h"

using namespace Haru;

Persistent<FunctionTemplate> Doc::constructor;
void Doc::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Doc::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Doc"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();
  NODE_SET_PROTOTYPE_METHOD(constructor, "addPage", AddPage);
  NODE_SET_PROTOTYPE_METHOD(constructor, "saveToFile", SaveToFile);

  target->Set(String::NewSymbol("Doc"), constructor->GetFunction());
}
Handle<Value> Doc::New(const Arguments &args) {
  HandleScope scope;
  Doc* doc = new Doc();
  doc->Wrap(args.This());
  return args.This();
}
Handle<Value> Doc::AddPage(const Arguments &args) {
  HandleScope scope;

  Doc* doc = ObjectWrap::Unwrap<Doc>(args.This());
  Local<Object> js_page = Page::constructor->GetFunction()->NewInstance();
  Page* page = ObjectWrap::Unwrap<Page>(js_page);
  page->page = HPDF_AddPage(doc->doc);
  return scope.Close(js_page);
}
Handle<Value> Doc::SaveToFile(const Arguments &args) {
  HandleScope scope;

  Doc* doc = ObjectWrap::Unwrap<Doc>(args.This());
  if (!args[0]->IsString()) {
    return ThrowException(Exception::TypeError(String::New("string expected")));
  }
  String::Utf8Value filename(args[0]->ToString());
  HPDF_SaveToFile(doc->doc, *filename);
  if (doc->hasError()) {
    return doc->error();
  }
  return Boolean::New(true);
}
Doc::Doc(): ObjectWrap() {
  doc = HPDF_New(NULL, NULL);
}
bool Doc::hasError() {
  return HPDF_GetError(doc) != HPDF_OK;
}
Handle<Value> Doc::error() {
  HandleScope scope;
  Local<String> str = Integer::New(HPDF_GetError(doc))->ToString();
  switch(HPDF_GetError(doc)) {
  case 1:
    str = String::New("Internal error. Data consistency was lost.");
    break;
  case 0x1017:
    str = String::New("Unable to open file");
    break;
  }
  return ThrowException(Exception::Error(str));
}
Doc::~Doc() {
  HPDF_Free(doc);
}