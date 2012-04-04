#include "font.h"

using namespace Haru;

// Page
Persistent<FunctionTemplate> Font::constructor;
void Font::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Font::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Font"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("Font"), constructor->GetFunction());
}
Handle<Value> Font::New(const Arguments &args) {
  HandleScope scope;
  Font* font = new Font();
  font->Wrap(args.This());
  return args.This();
}
Font::Font(): ObjectWrap() {}
Font::~Font() {}