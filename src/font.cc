#include "font.h"

using namespace Haru;

Font::Font(): ObjectWrap() {}
Font::~Font() {}

// Page
Persistent<FunctionTemplate> Font::constructor;
void Font::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Font::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Font"));

  //Local<ObjectTemplate> proto = constructor->PrototypeTemplate();
  
  NODE_SET_PROTOTYPE_METHOD(constructor, "getAscent", GetAscent);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getBBox", GetBBox);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCapHeight", GetCapHeight);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getDescent", GetDescent);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getFontName", GetFontName);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getUnicodeWidth", GetUnicodeWidth);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getXHeight", GetXHeight);
  NODE_SET_PROTOTYPE_METHOD(constructor, "measureText", MeasureText);
  NODE_SET_PROTOTYPE_METHOD(constructor, "textWidth", TextWidth);

  target->Set(String::NewSymbol("Font"), constructor->GetFunction());
}

Handle<Value> Font::GetAscent(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::GetBBox(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::GetCapHeight(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::GetDescent(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::GetFontName(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::GetUnicodeWidth(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::GetXHeight(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::MeasureText(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Font::New(const Arguments &args) {  
  HandleScope scope;

  if (args.Length() > 0) {
    raise("expected 0 arguments");
  }  
  
  Font* font = new Font();
  font->Wrap(args.This());
  return args.This();
}
Handle<Value> Font::TextWidth(const Arguments &args) { HandleScope scope; raise("not implemented"); }