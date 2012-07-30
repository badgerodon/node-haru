#include "page_sizes.h"

using namespace Haru;

HPDF_PageSizes PageSizes::Get(const char* name) {  
  if (strcmp(name, "letter") == 0) {
    return HPDF_PAGE_SIZE_LETTER;
  } else if (strcmp(name, "legal") == 0) {
    return HPDF_PAGE_SIZE_LEGAL;
  } else if (strcmp(name, "a3") == 0) {
    return HPDF_PAGE_SIZE_A3;
  } else if (strcmp(name, "a4") == 0) {
    return HPDF_PAGE_SIZE_A4;
  } else if (strcmp(name, "a5") == 0) {
    return HPDF_PAGE_SIZE_A5;
  } else if (strcmp(name, "b4") == 0) {
    return HPDF_PAGE_SIZE_B4;
  } else if (strcmp(name, "b5") == 0) {
    return HPDF_PAGE_SIZE_B5;
  } else if (strcmp(name, "executive") == 0) {
    return HPDF_PAGE_SIZE_EXECUTIVE;
  } else if (strcmp(name, "us4x6") == 0) {
    return HPDF_PAGE_SIZE_US4x6;
  } else if (strcmp(name, "us4x8") == 0) {
    return HPDF_PAGE_SIZE_US4x8;
  } else if (strcmp(name, "us5x7") == 0) {
    return HPDF_PAGE_SIZE_US5x7;
  } else if (strcmp(name, "comm10") == 0) {
    return HPDF_PAGE_SIZE_COMM10;
  }
  
  return HPDF_PAGE_SIZE_LETTER;
}