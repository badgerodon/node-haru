#ifndef __NODE_PAGE_H__
#define __NODE_PAGE_H__

#include "include.h"

namespace Haru {
  class Page: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);

      HPDF_Page page;

      Page();
    private:
      ~Page();
  };
}

#endif