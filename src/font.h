#ifndef __NODE_FONT_H__
#define __NODE_FONT_H__

#include "include.h"

namespace Haru {
  class Font: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);

      HPDF_Font font;

      Font();
    private:
      ~Font();
  };
}

#endif