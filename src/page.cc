#include "page.h"

using namespace Haru;

// Page
Persistent<FunctionTemplate> Page::constructor;
void Page::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Page::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Page"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("Page"), constructor->GetFunction());
}
Handle<Value> Page::New(const Arguments &args) {
  HandleScope scope;
  Page* page = new Page();
  page->Wrap(args.This());
  return args.This();
}
Page::Page(): ObjectWrap() {
}
Page::~Page() {

}