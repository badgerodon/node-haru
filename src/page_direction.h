#ifndef __NODE_PAGE_DIRECTION_H__
#define __NODE_PAGE_DIRECTION_H__

#include "include.h"

namespace Haru {
  class PageDirection {
    public:
      static HPDF_PageDirection Get(const char*);
  };
}

#endif