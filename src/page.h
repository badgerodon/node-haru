#ifndef __NODE_PAGE_H__
#define __NODE_PAGE_H__

#include "include.h"

namespace Haru {
  class Page: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> BeginText(const Arguments &args);
      static Handle<Value> CreateDestination(const Arguments &args);
      static Handle<Value> CreateLinkAnnot(const Arguments &args);
      static Handle<Value> CreateTextAnnot(const Arguments &args);
      static Handle<Value> CreateURILinkAnnot(const Arguments &args);
      static Handle<Value> EndText(const Arguments &args);
      static Handle<Value> GetCharSpace(const Arguments &args);
      static Handle<Value> GetCMYKFill(const Arguments &args);
      static Handle<Value> GetCMYKStroke(const Arguments &args);
      static Handle<Value> GetCurrentFont(const Arguments &args);
      static Handle<Value> GetCurrentFontSize(const Arguments &args);
      static Handle<Value> GetCurrentPos(const Arguments &args);
      static Handle<Value> GetCurrentTextPos(const Arguments &args);
      static Handle<Value> GetDash(const Arguments &args);
      static Handle<Value> GetFillingColorSpace(const Arguments &args);
      static Handle<Value> GetFlat(const Arguments &args);
      static Handle<Value> GetGrayFill(const Arguments &args);
      static Handle<Value> GetGrayStroke(const Arguments &args);
      static Handle<Value> GetHeight(const Arguments &args);
      static Handle<Value> GetLineCap(const Arguments &args);
      static Handle<Value> GetLineJoin(const Arguments &args);
      static Handle<Value> GetLineWidth(const Arguments &args);
      static Handle<Value> GetMiterLimit(const Arguments &args);
      static Handle<Value> GetGMode(const Arguments &args);
      static Handle<Value> GetGStateDepth(const Arguments &args);
      static Handle<Value> GetHorizontalScalling(const Arguments &args);
      static Handle<Value> GetRGBFill(const Arguments &args);
      static Handle<Value> GetRGBStroke(const Arguments &args);
      static Handle<Value> GetStrokingColorSpace(const Arguments &args);
      static Handle<Value> GetTextLeading(const Arguments &args);
      static Handle<Value> GetTextMatrix(const Arguments &args);
      static Handle<Value> GetTextRenderingMode(const Arguments &args);
      static Handle<Value> GetTextRise(const Arguments &args);
      static Handle<Value> GetTransMatrix(const Arguments &args);
      static Handle<Value> GetWordSpace(const Arguments &args);
      static Handle<Value> GetWidth(const Arguments &args);
      static Handle<Value> MeasureText(const Arguments &args);
      static Handle<Value> MoveTextPos(const Arguments &args);
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> SetFontAndSize(const Arguments &args);
      static Handle<Value> SetHeight(const Arguments &args);
      static Handle<Value> SetRotate(const Arguments &args);
      static Handle<Value> SetSize(const Arguments &args);
      static Handle<Value> SetSlideShow(const Arguments &args);
      static Handle<Value> SetWidth(const Arguments &args);
      static Handle<Value> ShowText(const Arguments &args);
      static Handle<Value> TextRect(const Arguments &args);
      static Handle<Value> TextWidth(const Arguments &args);

      HPDF_Page page;

      Page();
    private:
      ~Page();
  };
}

#endif