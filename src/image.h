#ifndef __NODE_IMAGE_H__
#define __NODE_IMAGE_H__

#include "include.h"

namespace Haru {
  class Font: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> GetBitsPerComponent(const Arguments &args);
      static Handle<Value> GetColorSpace(const Arguments &args);
      static Handle<Value> GetHeight(const Arguments &args);
      static Handle<Value> GetSize(const Arguments &args);
      static Handle<Value> GetWidth(const Arguments &args);
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> SetColorMask(const Arguments &args);
      static Handle<Value> SetFitB(const Arguments &args);
      static Handle<Value> SetFitBH(const Arguments &args);
      static Handle<Value> SetFitBV(const Arguments &args);
      static Handle<Value> SetFitH(const Arguments &args);
      static Handle<Value> SetFitR(const Arguments &args);
      static Handle<Value> SetFitV(const Arguments &args);
      static Handle<Value> SetMaskImage(const Arguments &args);
      static Handle<Value> SetXYZ(const Arguments &args);

      HPDF_Font font;

      Font();
    private:
      ~Font();
  };
}

#endif