#include "page_sizes.h"

using namespace Haru;

PageSizes::PageSizes(): ObjectWrap() {}
PageSizes::~PageSizes() {}

Persistent<FunctionTemplate> PageSizes::constructor;
void PageSizes::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(PageSizes::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("PageSizes"));

  //Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("PageSizes"), constructor->GetFunction());

  map<const char*, HPDF_PageSizes> m;
  m["PAGE_SIZE_LETTER"] = HPDF_PAGE_SIZE_LETTER;
  m["PAGE_SIZE_LEGAL"] = HPDF_PAGE_SIZE_LEGAL;
  m["PAGE_SIZE_A3"] = HPDF_PAGE_SIZE_A3;
  m["PAGE_SIZE_A4"] = HPDF_PAGE_SIZE_A4;
  m["PAGE_SIZE_A5"] = HPDF_PAGE_SIZE_A5;
  m["PAGE_SIZE_B4"] = HPDF_PAGE_SIZE_B4;
  m["PAGE_SIZE_B5"] = HPDF_PAGE_SIZE_B5;
  m["PAGE_SIZE_EXECUTIVE"] = HPDF_PAGE_SIZE_EXECUTIVE;
  m["PAGE_SIZE_US4x6"] = HPDF_PAGE_SIZE_US4x6;
  m["PAGE_SIZE_US4x8"] = HPDF_PAGE_SIZE_US4x8;
  m["PAGE_SIZE_US5x7"] = HPDF_PAGE_SIZE_US5x7;
  m["PAGE_SIZE_COMM10"] = HPDF_PAGE_SIZE_COMM10;

  for (map<const char*, HPDF_PageSizes>::iterator ii=m.begin(); ii != m.end(); ++ii) {
    Local<Object> js = constructor->GetFunction()->NewInstance();
    PageSizes* obj = ObjectWrap::Unwrap<PageSizes>(js);
    obj->page_sizes = (*ii).second;
    target->Set(String::NewSymbol((*ii).first), js);
  }
}
Handle<Value> PageSizes::New(const Arguments &args) {
  HandleScope scope;
  PageSizes* page_sizes = new PageSizes();
  page_sizes->Wrap(args.This());
  return args.This();
}