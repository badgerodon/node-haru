#include "init.h"
#include "doc.h"
#include "page.h"
#include "font.h"
#include "text_alignment.h"
#include "page_sizes.h"
#include "page_direction.h"

using namespace Haru;

Handle<Value> Haru::handle_error(HPDF_STATUS status) {
  HandleScope scope;
  if (status == HPDF_OK) {
    return scope.Close(Boolean::New(true));
  }

  Local<String> str = Integer::New(status)->ToString();
  switch(status) {
  case 0x1001:
    str = String::New("HPDF_ARRAY_COUNT_ERR");
    break;

  case 0x1002:
    str = String::New("HPDF_ARRAY_ITEM_NOT_FOUND");
    break;

  case 0x1003:
    str = String::New("HPDF_ARRAY_ITEM_UNEXPECTED_TYPE");
    break;

  case 0x1004:
    str = String::New("HPDF_BINARY_LENGTH_ERR");
    break;

  case 0x1005:
    str = String::New("HPDF_CANNOT_GET_PALLET");
    break;

  case 0x1007:
    str = String::New("HPDF_DICT_COUNT_ERR");
    break;

  case 0x1008:
    str = String::New("HPDF_DICT_ITEM_NOT_FOUND");
    break;

  case 0x1009:
    str = String::New("HPDF_DICT_ITEM_UNEXPECTED_TYPE");
    break;

  case 0x100A:
    str = String::New("HPDF_DICT_STREAM_LENGTH_NOT_FOUND");
    break;

  case 0x100B:
    str = String::New("HPDF_DOC_ENCRYPTDICT_NOT_FOUND");
    break;

  case 0x100C:
    str = String::New("HPDF_DOC_INVALID_OBJECT");
    break;

  case 0x100E:
    str = String::New("HPDF_DUPLICATE_REGISTRATION");
    break;

  case 0x100F:
    str = String::New("HPDF_EXCEED_JWW_CODE_NUM_LIMIT");
    break;

  case 0x1011:
    str = String::New("HPDF_ENCRYPT_INVALID_PASSWORD");
    break;

  case 0x1013:
    str = String::New("HPDF_ERR_UNKNOWN_CLASS");
    break;

  case 0x1014:
    str = String::New("HPDF_EXCEED_GSTATE_LIMIT");
    break;

  case 0x1015:
    str = String::New("HPDF_FAILD_TO_ALLOC_MEM");
    break;

  case 0x1016:
    str = String::New("HPDF_FILE_IO_ERROR");
    break;

  case 0x1017:
    str = String::New("HPDF_FILE_OPEN_ERROR");
    break;

  case 0x1019:
    str = String::New("HPDF_FONT_EXISTS");
    break;

  case 0x101A:
    str = String::New("HPDF_FONT_INVALID_WIDTHS_TABLE");
    break;

  case 0x101B:
    str = String::New("HPDF_INVALID_AFM_HEADER");
    break;

  case 0x101C:
    str = String::New("HPDF_INVALID_ANNOTATION");
    break;

  case 0x101E:
    str = String::New("HPDF_INVALID_BIT_PER_COMPONENT");
    break;

  case 0x101F:
    str = String::New("HPDF_INVALID_CHAR_MATRICS_DATA");
    break;

  case 0x1020:
    str = String::New("HPDF_INVALID_COLOR_SPACE");
    break;

  case 0x1021:
    str = String::New("HPDF_INVALID_COMPRESSION_MODE");
    break;

  case 0x1022:
    str = String::New("HPDF_INVALID_DATE_TIME");
    break;

  case 0x1023:
    str = String::New("HPDF_INVALID_DESTINATION");
    break;

  case 0x1025:
    str = String::New("HPDF_INVALID_DOCUMENT");
    break;

  case 0x1026:
    str = String::New("HPDF_INVALID_DOCUMENT_STATE");
    break;

  case 0x1027:
    str = String::New("HPDF_INVALID_ENCODER");
    break;

  case 0x1028:
    str = String::New("HPDF_INVALID_ENCODER_TYPE");
    break;

  case 0x102B:
    str = String::New("HPDF_INVALID_ENCODING_NAME");
    break;

  case 0x102C:
    str = String::New("HPDF_INVALID_ENCRYPT_KEY_LEN");
    break;

  case 0x102D:
    str = String::New("HPDF_INVALID_FONTDEF_DATA");
    break;

  case 0x102E:
    str = String::New("HPDF_INVALID_FONTDEF_TYPE");
    break;

  case 0x102F:
    str = String::New("HPDF_INVALID_FONT_NAME");
    break;

  case 0x1030:
    str = String::New("HPDF_INVALID_IMAGE");
    break;

  case 0x1031:
    str = String::New("HPDF_INVALID_JPEG_DATA");
    break;

  case 0x1032:
    str = String::New("HPDF_INVALID_N_DATA");
    break;

  case 0x1033:
    str = String::New("HPDF_INVALID_OBJECT");
    break;

  case 0x1034:
    str = String::New("HPDF_INVALID_OBJ_ID");
    break;

  case 0x1035:
    str = String::New("HPDF_INVALID_OPERATION");
    break;

  case 0x1036:
    str = String::New("HPDF_INVALID_OUTLINE");
    break;

  case 0x1037:
    str = String::New("HPDF_INVALID_PAGE");
    break;

  case 0x1038:
    str = String::New("HPDF_INVALID_PAGES");
    break;

  case 0x1039:
    str = String::New("HPDF_INVALID_PARAMETER");
    break;

  case 0x103B:
    str = String::New("HPDF_INVALID_PNG_IMAGE");
    break;

  case 0x103C:
    str = String::New("HPDF_INVALID_STREAM");
    break;

  case 0x103D:
    str = String::New("HPDF_MISSING_FILE_NAME_ENTRY");
    break;

  case 0x103F:
    str = String::New("HPDF_INVALID_TTC_FILE");
    break;

  case 0x1040:
    str = String::New("HPDF_INVALID_TTC_INDEX");
    break;

  case 0x1041:
    str = String::New("HPDF_INVALID_WX_DATA");
    break;

  case 0x1042:
    str = String::New("HPDF_ITEM_NOT_FOUND");
    break;

  case 0x1043:
    str = String::New("HPDF_LIBPNG_ERROR");
    break;

  case 0x1044:
    str = String::New("HPDF_NAME_INVALID_VALUE");
    break;

  case 0x1045:
    str = String::New("HPDF_NAME_OUT_OF_RANGE");
    break;

  case 0x1048:
    str = String::New("HPDF_PAGE_INVALID_PARAM_COUNT");
    break;

  case 0x1049:
    str = String::New("HPDF_PAGES_MISSING_KIDS_ENTRY");
    break;

  case 0x104A:
    str = String::New("HPDF_PAGE_CANNOT_FIND_OBJECT");
    break;

  case 0x104B:
    str = String::New("HPDF_PAGE_CANNOT_GET_ROOT_PAGES");
    break;

  case 0x104C:
    str = String::New("HPDF_PAGE_CANNOT_RESTORE_GSTATE");
    break;

  case 0x104D:
    str = String::New("HPDF_PAGE_CANNOT_SET_PARENT");
    break;

  case 0x104E:
    str = String::New("HPDF_PAGE_FONT_NOT_FOUND");
    break;

  case 0x104F:
    str = String::New("HPDF_PAGE_INVALID_FONT");
    break;

  case 0x1050:
    str = String::New("HPDF_PAGE_INVALID_FONT_SIZE");
    break;

  case 0x1051:
    str = String::New("HPDF_PAGE_INVALID_GMODE");
    break;

  case 0x1052:
    str = String::New("HPDF_PAGE_INVALID_INDEX");
    break;

  case 0x1053:
    str = String::New("HPDF_PAGE_INVALID_ROTATE_VALUE");
    break;

  case 0x1054:
    str = String::New("HPDF_PAGE_INVALID_SIZE");
    break;

  case 0x1055:
    str = String::New("HPDF_PAGE_INVALID_XOBJECT");
    break;

  case 0x1056:
    str = String::New("HPDF_PAGE_OUT_OF_RANGE");
    break;

  case 0x1057:
    str = String::New("HPDF_REAL_OUT_OF_RANGE");
    break;

  case 0x1058:
    str = String::New("HPDF_STREAM_EOF");
    break;

  case 0x1059:
    str = String::New("HPDF_STREAM_READLN_CONTINUE");
    break;

  case 0x105B:
    str = String::New("HPDF_STRING_OUT_OF_RANGE");
    break;

  case 0x105C:
    str = String::New("HPDF_THIS_FUNC_WAS_SKIPPED");
    break;

  case 0x105D:
    str = String::New("HPDF_TTF_CANNOT_EMBEDDING_FONT");
    break;

  case 0x105E:
    str = String::New("HPDF_TTF_INVALID_CMAP");
    break;

  case 0x105F:
    str = String::New("HPDF_TTF_INVALID_FOMAT");
    break;

  case 0x1060:
    str = String::New("HPDF_TTF_MISSING_TABLE");
    break;

  case 0x1061:
    str = String::New("HPDF_UNSUPPORTED_FONT_TYPE");
    break;

  case 0x1062:
    str = String::New("HPDF_UNSUPPORTED_FUNC");
    break;

  case 0x1063:
    str = String::New("HPDF_UNSUPPORTED_JPEG_FORMAT");
    break;

  case 0x1064:
    str = String::New("HPDF_UNSUPPORTED_TYPE1_FONT");
    break;

  case 0x1065:
    str = String::New("HPDF_XREF_COUNT_ERR");
    break;

  case 0x1066:
    str = String::New("HPDF_ZLIB_ERROR");
    break;

  case 0x1067:
    str = String::New("HPDF_INVALID_PAGE_INDEX");
    break;

  case 0x1068:
    str = String::New("HPDF_INVALID_URI");
    break;

  case 0x1069:
    str = String::New("HPDF_PAGE_LAYOUT_OUT_OF_RANGE");
    break;

  case 0x1070:
    str = String::New("HPDF_PAGE_MODE_OUT_OF_RANGE");
    break;

  case 0x1071:
    str = String::New("HPDF_PAGE_NUM_STYLE_OUT_OF_RANGE");
    break;

  case 0x1072:
    str = String::New("HPDF_ANNOT_INVALID_ICON");
    break;

  case 0x1073:
    str = String::New("HPDF_ANNOT_INVALID_BORDER_STYLE");
    break;

  case 0x1074:
    str = String::New("HPDF_PAGE_INVALID_DIRECTION");
    break;

  case 0x1075:
    str = String::New("HPDF_INVALID_FONT");
    break;

  case 0x1076:
    str = String::New("HPDF_PAGE_INSUFFICIENT_SPACE");
    break;

  case 0x1077:
    str = String::New("HPDF_PAGE_INVALID_DISPLAY_TIME");
    break;

  case 0x1078:
    str = String::New("HPDF_PAGE_INVALID_TRANSITION_TIME");
    break;

  case 0x1079:
    str = String::New("HPDF_INVALID_PAGE_SLIDESHOW_TYPE");
    break;

  case 0x1080:
    str = String::New("HPDF_EXT_GSTATE_OUT_OF_RANGE");
    break;

  case 0x1081:
    str = String::New("HPDF_INVALID_EXT_GSTATE");
    break;

  case 0x1082:
    str = String::New("HPDF_EXT_GSTATE_READ_ONLY");
    break;

  case 0x1083:
    str = String::New("HPDF_INVALID_U3D_DATA");
    break;

  case 0x1084:
    str = String::New("HPDF_NAME_CANNOT_GET_NAMES");
    break;

  case 0x1085:
    str = String::New("HPDF_INVALID_ICC_COMPONENT_NUM");
    break;
  }
  return ThrowException(Exception::Error(str));
}

extern "C" void init(Handle<Object> target) {
  HandleScope scope;

  Doc::Initialize(target);
  Page::Initialize(target);
  Font::Initialize(target);
  TextAlignment::Initialize(target);
  PageSizes::Initialize(target);
  PageDirection::Initialize(target);
}