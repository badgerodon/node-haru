#include "page_direction.h"

using namespace Haru;

PageDirection::PageDirection(): ObjectWrap() {}
PageDirection::~PageDirection() {}

Persistent<FunctionTemplate> PageDirection::constructor;
void PageDirection::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(PageDirection::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("PageDirection"));

  //Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("PageDirection"), constructor->GetFunction());

  map<const char*, HPDF_PageDirection> m;
  m["PAGE_PORTRAIT"] = HPDF_PAGE_PORTRAIT;
  m["PAGE_LANDSCAPE"] = HPDF_PAGE_LANDSCAPE;

  for (map<const char*, HPDF_PageDirection>::iterator ii=m.begin(); ii != m.end(); ++ii) {
    Local<Object> js = constructor->GetFunction()->NewInstance();
    PageDirection* obj = ObjectWrap::Unwrap<PageDirection>(js);
    obj->page_direction = (*ii).second;
    target->Set(String::NewSymbol((*ii).first), js);
  }
}
Handle<Value> PageDirection::New(const Arguments &args) {
  HandleScope scope;
  PageDirection* page_direction = new PageDirection();
  page_direction->Wrap(args.This());
  return args.This();
}