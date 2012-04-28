#ifndef __NODE_PAGE_SIZES_H__
#define __NODE_PAGE_SIZES_H__

#include "include.h"

namespace Haru {
  class PageSizes {
    public:
      static HPDF_PageSizes Get(const char*);
  };
}

#endif