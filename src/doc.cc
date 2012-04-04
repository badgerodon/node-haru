#include "doc.h"
#include "page.h"
#include "font.h"

using namespace Haru;

Persistent<FunctionTemplate> Doc::constructor;
void Doc::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Doc::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Doc"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();
  NODE_SET_PROTOTYPE_METHOD(constructor, "addPage", AddPage);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getFont", GetFont);
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
Handle<Value> Doc::GetFont(const Arguments &args) {
  HandleScope scope;

  if (args.Length() < 1) {
    raise("expected at least 1 arguments");
  }
  if (!args[0]->IsString()) {
    raise("expected string for argument 1");
  }

  String::Utf8Value font_name(args[0]->ToString());
  const char* c_font_name = *font_name;
  const char* c_encoding_name = NULL;
  if (args.Length() > 1 && args[1]->IsString()) {
    String::Utf8Value encoding_name(args[1]->ToString());
    c_encoding_name = *encoding_name;
  }

  Doc* doc = ObjectWrap::Unwrap<Doc>(args.This());
  Local<Object> js_font = Font::constructor->GetFunction()->NewInstance();
  Font* font = ObjectWrap::Unwrap<Font>(js_font);
  font->font = HPDF_GetFont(doc->doc, c_font_name, c_encoding_name);
  if (HPDF_GetError(doc->doc) != HPDF_OK) {
    return handle_error(HPDF_GetError(doc->doc));
  }
  return scope.Close(js_font);
}
Handle<Value> Doc::SaveToFile(const Arguments &args) {
  HandleScope scope;

  Doc* doc = ObjectWrap::Unwrap<Doc>(args.This());
  if (!args[0]->IsString()) {
    return ThrowException(Exception::TypeError(String::New("string expected")));
  }
  String::Utf8Value filename(args[0]->ToString());
  HPDF_STATUS status = HPDF_SaveToFile(doc->doc, *filename);
  return handle_error(status);
}
Doc::Doc(): ObjectWrap() {
  doc = HPDF_New(NULL, NULL);
}
Doc::~Doc() {
  HPDF_Free(doc);
}