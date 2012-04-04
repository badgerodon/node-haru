#ifndef __NODE_PAGE_DIRECTION_H__
#define __NODE_PAGE_DIRECTION_H__

#include "include.h"

namespace Haru {
  class PageDirection: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> New(const Arguments &args);

      HPDF_PageDirection page_direction;

      PageDirection();
    private:
      ~PageDirection();
  };
}

#endif