#include "page.h"
#include "font.h"
#include "text_alignment.h"
#include "page_sizes.h"
#include "page_direction.h"

using namespace Haru;

Page::Page(): ObjectWrap() {}
Page::~Page() {}

Persistent<FunctionTemplate> Page::constructor;
void Page::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Page::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Page"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();
  NODE_SET_PROTOTYPE_METHOD(constructor, "beginText", BeginText);
  NODE_SET_PROTOTYPE_METHOD(constructor, "createDestination", CreateDestination);
  NODE_SET_PROTOTYPE_METHOD(constructor, "createLinkAnnot", CreateLinkAnnot);
  NODE_SET_PROTOTYPE_METHOD(constructor, "createTextAnnot", CreateTextAnnot);
  NODE_SET_PROTOTYPE_METHOD(constructor, "createURILinkAnnot", CreateURILinkAnnot);
  NODE_SET_PROTOTYPE_METHOD(constructor, "endText", EndText);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCharSpace", GetCharSpace);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCMYKFill", GetCMYKFill);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCMYKStroke", GetCMYKStroke);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCurrentFont", GetCurrentFont);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCurrentFontSize", GetCurrentFontSize);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCurrentPos", GetCurrentPos);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getCurrentTextPos", GetCurrentTextPos);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getDash", GetDash);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getFillingColorSpace", GetFillingColorSpace);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getFlat", GetFlat);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getGrayFill", GetGrayFill);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getGrayStroke", GetGrayStroke);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getLineCap", GetLineCap);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getLineJoin", GetLineJoin);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getLineWidth", GetLineWidth);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getMiterLimit", GetMiterLimit);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getGMode", GetGMode);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getGStateDepth", GetGStateDepth);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getHeight", GetHeight);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getHorizontalScalling", GetHorizontalScalling);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getRGBFill", GetRGBFill);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getRGBStroke", GetRGBStroke);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getStrokingColorSpace", GetStrokingColorSpace);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getTextLeading", GetTextLeading);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getTextMatrix", GetTextMatrix);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getTextRenderingMode", GetTextRenderingMode);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getTextRise", GetTextRise);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getTransMatrix", GetTransMatrix);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getWidth", GetWidth);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getWordSpace", GetWordSpace);
  NODE_SET_PROTOTYPE_METHOD(constructor, "measureText", MeasureText);
  NODE_SET_PROTOTYPE_METHOD(constructor, "moveTextPos", MoveTextPos);
  NODE_SET_PROTOTYPE_METHOD(constructor, "setFontAndSize", SetFontAndSize);
  NODE_SET_PROTOTYPE_METHOD(constructor, "setHeight", SetHeight);
  NODE_SET_PROTOTYPE_METHOD(constructor, "setRotate", SetRotate);
  NODE_SET_PROTOTYPE_METHOD(constructor, "setSize", SetSize);
  NODE_SET_PROTOTYPE_METHOD(constructor, "setSlideShow", SetSlideShow);
  NODE_SET_PROTOTYPE_METHOD(constructor, "setWidth", SetWidth);
  NODE_SET_PROTOTYPE_METHOD(constructor, "showText", ShowText);
  NODE_SET_PROTOTYPE_METHOD(constructor, "textRect", TextRect);
  NODE_SET_PROTOTYPE_METHOD(constructor, "textWidth", TextWidth);

  target->Set(String::NewSymbol("Page"), constructor->GetFunction());
}

Handle<Value> Page::BeginText(const Arguments &args) {
  HandleScope scope;

  Page* page = ObjectWrap::Unwrap<Page>(args.This());
  return handle_error(
    HPDF_Page_BeginText(page->page)
  );
}
Handle<Value> Page::CreateDestination(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::CreateLinkAnnot(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::CreateTextAnnot(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::CreateURILinkAnnot(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::EndText(const Arguments &args) {
  HandleScope scope;

  Page* page = ObjectWrap::Unwrap<Page>(args.This());
  return handle_error(
    HPDF_Page_EndText(page->page)
  );
}
Handle<Value> Page::GetCharSpace(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetCMYKFill(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetCMYKStroke(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetCurrentFont(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetCurrentFontSize(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetCurrentPos(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetCurrentTextPos(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetDash(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetFillingColorSpace(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetFlat(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetGrayFill(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetGrayStroke(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetHeight(const Arguments &args) {
  HandleScope scope;

  Page* page = ObjectWrap::Unwrap<Page>(args.This());
  HPDF_REAL height = HPDF_Page_GetHeight(page->page);
  return scope.Close(Number::New(height));
}
Handle<Value> Page::GetLineCap(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetLineJoin(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetLineWidth(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetMiterLimit(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetGMode(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetGStateDepth(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetHorizontalScalling(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetRGBFill(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetRGBStroke(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetStrokingColorSpace(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetTextLeading(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetTextMatrix(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetTextRenderingMode(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetTextRise(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetTransMatrix(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::GetWidth(const Arguments &args) {
  HandleScope scope;

  Page* page = ObjectWrap::Unwrap<Page>(args.This());
  HPDF_REAL width = HPDF_Page_GetWidth(page->page);
  return scope.Close(Number::New(width));
}
Handle<Value> Page::GetWordSpace(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::MeasureText(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::MoveTextPos(const Arguments &args) {
  HandleScope scope;

  if (args.Length() != 2) {
    return ThrowException(Exception::TypeError(String::New("expected two arguments")));
  }
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    return ThrowException(Exception::TypeError(String::New("expected two numbers")));
  }

  HPDF_REAL x = args[0]->NumberValue();
  HPDF_REAL y = args[1]->NumberValue();

  Page* page = ObjectWrap::Unwrap<Page>(args.This());
  return handle_error(
    HPDF_Page_MoveTextPos(page->page, x, y)
  );
}
Handle<Value> Page::New(const Arguments &args) {
  HandleScope scope;
  Page* page = new Page();
  page->Wrap(args.This());
  return args.This();
}
Handle<Value> Page::SetFontAndSize(const Arguments &args) {
  HandleScope scope;

  if (args.Length() != 2) {
    raise("expected 2 arguments");
  }
  Local<Object> obj = args[0]->ToObject();
  if (!Font::constructor->HasInstance(obj)) {
    raise("expected Font for argument 1");
  }
  if (!args[1]->IsNumber()) {
    raise("expected number for argument 2");
  }

  HPDF_Page page = ObjectWrap::Unwrap<Page>(args.This())->page;
  HPDF_Font font = ObjectWrap::Unwrap<Font>(obj)->font;
  HPDF_REAL size = args[1]->NumberValue();

  return handle_error(
    HPDF_Page_SetFontAndSize(page, font, size)
  );
}
Handle<Value> Page::SetHeight(const Arguments &args) {
  HandleScope scope;

  if (args.Length() != 1) {
    raise("expected 1 argument");
  }
  if (!args[0]->IsNumber()) {
    raise("expected number for argument 1");
  }

  HPDF_Page page = ObjectWrap::Unwrap<Page>(args.This())->page;
  HPDF_REAL value = args[0]->NumberValue();

  return handle_error(
    HPDF_Page_SetHeight(page, value)
  );
}
Handle<Value> Page::SetRotate(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::SetSize(const Arguments &args) {
  HandleScope scope;

  if (args.Length() != 2) {
    raise("expected 2 arguments");
  }
  if (!PageSizes::constructor->HasInstance(args[0]->ToObject())) {
    raise("expected PageSizes for argument 1");
  }
  if (!PageDirection::constructor->HasInstance(args[1]->ToObject())) {
    raise("expected PageDirection for argument 2");
  }

  HPDF_Page page = ObjectWrap::Unwrap<Page>(args.This())->page;
  HPDF_PageSizes size = ObjectWrap::Unwrap<PageSizes>(args.This())->page_sizes;
  HPDF_PageDirection direction = ObjectWrap::Unwrap<PageDirection>(args.This())->page_direction;

  return handle_error(
    HPDF_Page_SetSize(page, size, direction)
  );
}
Handle<Value> Page::SetSlideShow(const Arguments &args) { HandleScope scope; raise("not implemented"); }
Handle<Value> Page::SetWidth(const Arguments &args) {
  HandleScope scope;
  if (args.Length() != 1) {
    raise("expected 1 argument");
  }
  if (!args[0]->IsNumber()) {
    raise("expected number for argument 1");
  }

  HPDF_Page page = ObjectWrap::Unwrap<Page>(args.This())->page;
  HPDF_REAL value = args[0]->NumberValue();

  return handle_error(
    HPDF_Page_SetWidth(page, value)
  );
}
Handle<Value> Page::ShowText(const Arguments &args) {
  HandleScope scope;

  if (args.Length() != 1) {
    return ThrowException(Exception::TypeError(String::New("expected one argument")));
  }
  if (!args[0]->IsString()) {
    return ThrowException(Exception::TypeError(String::New("expected string")));
  }

  String::Utf8Value text(args[0]->ToString());

  Page* page = ObjectWrap::Unwrap<Page>(args.This());
  return handle_error(
    HPDF_Page_ShowText(page->page, *text)
  );
}
Handle<Value> Page::TextRect(const Arguments &args) {
  HandleScope scope;

  if (args.Length() != 6) {
    raise("expected 6 arguments");
  }
  if (!args[0]->IsNumber()) {
    raise("expected number for argument 1");
  }
  if (!args[1]->IsNumber()) {
    raise("expected number for argument 2");
  }
  if (!args[2]->IsNumber()) {
    raise("expected number for argument 3");
  }
  if (!args[3]->IsNumber()) {
    raise("expected number for argument 4");
  }
  if (!args[4]->IsString()) {
    raise("expected string for argument 5");
  }
  if (!TextAlignment::constructor->HasInstance(args[5]->ToObject())) {
    raise("expected TextAlignment for argument 6");
  }

  HPDF_Page page = ObjectWrap::Unwrap<Page>(args.This())->page;
  HPDF_REAL left = args[0]->NumberValue();
  HPDF_REAL top = args[1]->NumberValue();
  HPDF_REAL right = args[2]->NumberValue();
  HPDF_REAL bottom = args[3]->NumberValue();
  String::Utf8Value text(args[4]->ToString());
  HPDF_TextAlignment align = ObjectWrap::Unwrap<TextAlignment>(args[5]->ToObject())->text_alignment;

  return handle_error(
    HPDF_Page_TextRect(page, left, top, right, bottom, *text, align, NULL)
  );
}
Handle<Value> Page::TextWidth(const Arguments &args) { HandleScope scope; raise("not implemented"); }