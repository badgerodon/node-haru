#ifndef __NODE_PAGE_SIZES_H__
#define __NODE_PAGE_SIZES_H__

#include "include.h"

namespace Haru {
  class PageSizes: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);

      HPDF_PageSizes page_sizes;

      PageSizes();
    private:
      ~PageSizes();
  };
}

#endif