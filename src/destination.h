#ifndef __NODE_DESTINATION_H__
#define __NODE_DESTINATION_H__

#include "include.h"

namespace Haru {
  class Font: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> SetFit(const Arguments &args);
      static Handle<Value> SetFitB(const Arguments &args);
      static Handle<Value> SetFitBH(const Arguments &args);
      static Handle<Value> SetFitBV(const Arguments &args);
      static Handle<Value> SetFitH(const Arguments &args);
      static Handle<Value> SetFitR(const Arguments &args);
      static Handle<Value> SetFitV(const Arguments &args);
      static Handle<Value> SetXYZ(const Arguments &args);

      HPDF_Font font;

      Font();
    private:
      ~Font();
  };
}

#endif