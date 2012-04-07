#ifndef __NODE_PAGE_H__
#define __NODE_PAGE_H__

#include "include.h"

namespace Haru {
  class Page: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> Arc(const Arguments &args);
      static Handle<Value> BeginText(const Arguments &args);
      static Handle<Value> Circle(const Arguments &args);
      static Handle<Value> Clip(const Arguments &args);
      static Handle<Value> ClosePath(const Arguments &args);
      static Handle<Value> ClosePathStroke(const Arguments &args);
      static Handle<Value> ClosePathEofillStroke(const Arguments &args);
      static Handle<Value> ClosePathFillStroke(const Arguments &args);
      static Handle<Value> Concat(const Arguments &args);
      static Handle<Value> CreateDestination(const Arguments &args);
      static Handle<Value> CreateLinkAnnot(const Arguments &args);
      static Handle<Value> CreateTextAnnot(const Arguments &args);
      static Handle<Value> CreateURILinkAnnot(const Arguments &args);
      static Handle<Value> CurveTo(const Arguments &args);
      static Handle<Value> CurveTo2(const Arguments &args);
      static Handle<Value> CurveTo3(const Arguments &args);
      static Handle<Value> DrawImage(const Arguments &args);
      static Handle<Value> Ellipse(const Arguments &args);
      static Handle<Value> EndPath(const Arguments &args);
      static Handle<Value> EndText(const Arguments &args);
      static Handle<Value> Eoclip(const Arguments &args);
      static Handle<Value> Eofill(const Arguments &args);
      static Handle<Value> EofillStroke(const Arguments &args);
      static Handle<Value> ExecuteXObject(const Arguments &args);
      static Handle<Value> Fill(const Arguments &args);
      static Handle<Value> FillStroke(const Arguments &args);
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
      static Handle<Value> GRestore(const Arguments &args);
      static Handle<Value> GSave(const Arguments &args);
      static Handle<Value> LineTo(const Arguments &args);
      static Handle<Value> MeasureText(const Arguments &args);
      static Handle<Value> MoveTextPos(const Arguments &args);
      static Handle<Value> MoveTextPos2(const Arguments &args);
      static Handle<Value> MoveTo(const Arguments &args);
      static Handle<Value> MoveToNextLine(const Arguments &args);
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> Rectangle(const Arguments &args);
      static Handle<Value> SetCharSpace(const Arguments &args);
      static Handle<Value> SetCMYKFill(const Arguments &args);
      static Handle<Value> SetCMYKStroke(const Arguments &args);
      static Handle<Value> SetDash(const Arguments &args);
      static Handle<Value> SetExtGState(const Arguments &args);
      static Handle<Value> SetFontAndSize(const Arguments &args);
      static Handle<Value> SetGrayFill(const Arguments &args);
      static Handle<Value> SetGrayStroke(const Arguments &args);
      static Handle<Value> SetHeight(const Arguments &args);
      static Handle<Value> SetHorizontalScalling(const Arguments &args);
      static Handle<Value> SetLineCap(const Arguments &args);
      static Handle<Value> SetLineJoin(const Arguments &args);
      static Handle<Value> SetLineWidth(const Arguments &args);
      static Handle<Value> SetMiterLimit(const Arguments &args);
      static Handle<Value> SetRGBFill(const Arguments &args);
      static Handle<Value> SetRGBStroke(const Arguments &args);
      static Handle<Value> SetRotate(const Arguments &args);
      static Handle<Value> SetSize(const Arguments &args);
      static Handle<Value> SetSlideShow(const Arguments &args);
      static Handle<Value> SetTextLeading(const Arguments &args);
      static Handle<Value> SetTextMatrix(const Arguments &args);
      static Handle<Value> SetTextRenderingMode(const Arguments &args);
      static Handle<Value> SetTextRise(const Arguments &args);
      static Handle<Value> SetWidth(const Arguments &args);
      static Handle<Value> SetWordSpace(const Arguments &args);
      static Handle<Value> ShowText(const Arguments &args);
      static Handle<Value> ShowTextNextLine(const Arguments &args);
      static Handle<Value> ShowTextNextLineEx(const Arguments &args);
      static Handle<Value> Stroke(const Arguments &args);
      static Handle<Value> TextOut(const Arguments &args);
      static Handle<Value> TextRect(const Arguments &args);
      static Handle<Value> TextWidth(const Arguments &args);

      HPDF_Page page;

      Page();
    private:
      ~Page();
  };
}

#endif