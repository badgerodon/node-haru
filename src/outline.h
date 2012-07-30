#ifndef __NODE_OUTLINE_H__
#define __NODE_OUTLINE_H__

#include "include.h"

namespace Haru {
  class Font: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> SetDestination(const Arguments &args);
      static Handle<Value> SetOpened(const Arguments &args);

      HPDF_Font font;

      Font();
    private:
      ~Font();
  };
}

#endif