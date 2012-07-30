#ifndef __NODE_FONT_H__
#define __NODE_FONT_H__

#include "include.h"

namespace Haru {
  class Font: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> GetAscent(const Arguments &args);
      static Handle<Value> GetBBox(const Arguments &args);
      static Handle<Value> GetCapHeight(const Arguments &args);
      static Handle<Value> GetDescent(const Arguments &args);
      static Handle<Value> GetFontName(const Arguments &args);
      static Handle<Value> GetUnicodeWidth(const Arguments &args);
      static Handle<Value> GetXHeight(const Arguments &args);
      static Handle<Value> MeasureText(const Arguments &args);
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> TextWidth(const Arguments &args);

      HPDF_Font font;

      Font();
    private:
      ~Font();
  };
}

#endif