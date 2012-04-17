#include "text_alignment.h"

using namespace Haru;

// Page
Persistent<FunctionTemplate> TextAlignment::constructor;
void TextAlignment::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(TextAlignment::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("TextAlignment"));

  //Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("TextAlignment"), constructor->GetFunction());

  Local<Object> js_left = constructor->GetFunction()->NewInstance();
  TextAlignment* left = ObjectWrap::Unwrap<TextAlignment>(js_left);
  left->text_alignment = HPDF_TALIGN_LEFT;
  target->Set(String::NewSymbol("TALIGN_LEFT"), js_left);

  Local<Object> js_right = constructor->GetFunction()->NewInstance();
  TextAlignment* right = ObjectWrap::Unwrap<TextAlignment>(js_right);
  right->text_alignment = HPDF_TALIGN_RIGHT;
  target->Set(String::NewSymbol("TALIGN_RIGHT"), js_right);

  Local<Object> js_center = constructor->GetFunction()->NewInstance();
  TextAlignment* center = ObjectWrap::Unwrap<TextAlignment>(js_center);
  center->text_alignment = HPDF_TALIGN_CENTER;
  target->Set(String::NewSymbol("TALIGN_CENTER"), js_center);

  Local<Object> js_justify = constructor->GetFunction()->NewInstance();
  TextAlignment* justify = ObjectWrap::Unwrap<TextAlignment>(js_justify);
  justify->text_alignment = HPDF_TALIGN_JUSTIFY;
  target->Set(String::NewSymbol("TALIGN_JUSTIFY"), js_justify);
}
Handle<Value> TextAlignment::New(const Arguments &args) {
  HandleScope scope;
  TextAlignment* text_alignment = new TextAlignment();
  text_alignment->Wrap(args.This());
  return args.This();
}
TextAlignment::TextAlignment(): ObjectWrap() {}
TextAlignment::~TextAlignment() {}