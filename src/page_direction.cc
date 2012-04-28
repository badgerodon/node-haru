#include "page_direction.h"

using namespace Haru;

HPDF_PageDirection PageDirection::Get(const char* name) {  
  if (strcmp(name, "portrait") == 0) {
    return HPDF_PAGE_PORTRAIT;
  } else if (strcmp(name, "landscape") == 0) {
    return HPDF_PAGE_LANDSCAPE;
  }
  
  return HPDF_PAGE_PORTRAIT;
}