#ifndef __NODE_DOC_H__
#define __NODE_DOC_H__

#include "include.h"

namespace Haru {
  class Doc: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> AddPage(const Arguments &args);
      static Handle<Value> SaveToFile(const Arguments &args);

      HPDF_Doc doc;

      Doc();
      bool hasError();
      Handle<Value> error();
    private:
      ~Doc();
  };
}

#endif