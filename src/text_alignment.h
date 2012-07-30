#ifndef __NODE_TEXT_ALIGNMENT_H__
#define __NODE_TEXT_ALIGNMENT_H__

#include "include.h"

namespace Haru {
  class TextAlignment: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);

      HPDF_TextAlignment text_alignment;

      TextAlignment();
    private:
      ~TextAlignment();
  };
}

#endif