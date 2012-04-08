#ifndef __NODE_DOC_H__
#define __NODE_DOC_H__

#include "include.h"

namespace Haru {
  class Doc: public node::ObjectWrap {
    public:
      static Persistent<FunctionTemplate> constructor;
      static void Initialize(Handle<Object> target);
      // JS methods
      static Handle<Value> AddPage(const Arguments &args);
      static Handle<Value> AddPageLabel(const Arguments &args);
      static Handle<Value> CreateOutline(const Arguments &args);
      static Handle<Value> GetCurrentEncoder(const Arguments &args);
      static Handle<Value> GetCurrentPage(const Arguments &args);
      static Handle<Value> GetEncoder(const Arguments &args);
      static Handle<Value> GetFont(const Arguments &args);
      static Handle<Value> GetInfoAttr(const Arguments &args);
      static Handle<Value> GetPageLayout(const Arguments &args);
      static Handle<Value> GetPageMode(const Arguments &args);
      static Handle<Value> HasDoc(const Arguments &args);
      static Handle<Value> InsertPage(const Arguments &args);
      static Handle<Value> LoadJpegImageFromFile(const Arguments &args);
      static Handle<Value> LoadJpegImageFromMem(const Arguments &args);
      static Handle<Value> LoadRawImageFromFile(const Arguments &args);
      static Handle<Value> LoadRawImageFromMem(const Arguments &args);
      static Handle<Value> LoadPngImageFromFile(const Arguments &args);
      static Handle<Value> LoadPngImageFromFile2(const Arguments &args);
      static Handle<Value> LoadPngImageFromMem(const Arguments &args);
      static Handle<Value> LoadType1FontFromFile(const Arguments &args);
      static Handle<Value> LoadTTFontFromFile(const Arguments &args);
      static Handle<Value> LoadTTFontFromFile2(const Arguments &args);
      static Handle<Value> New(const Arguments &args);
      static Handle<Value> NewDoc(const Arguments &args);
      static Handle<Value> SaveToFile(const Arguments &args);
      static Handle<Value> SaveToBuffer(const Arguments &args);
      static Handle<Value> SetCompressionMode(const Arguments &args);
      static Handle<Value> SetCurrentEncoder(const Arguments &args);
      static Handle<Value> SetEncryptionMode(const Arguments &args);
      static Handle<Value> SetInfoAttr(const Arguments &args);
      static Handle<Value> SetInfoDateAttr(const Arguments &args);
      static Handle<Value> SetOpenAction(const Arguments &args);
      static Handle<Value> SetPageLayout(const Arguments &args);
      static Handle<Value> SetPageMode(const Arguments &args);
      static Handle<Value> SetPagesConfiguration(const Arguments &args);
      static Handle<Value> SetPassword(const Arguments &args);
      static Handle<Value> SetPermission(const Arguments &args);
      static Handle<Value> UseCNSEncodings(const Arguments &args);
      static Handle<Value> UseCNSFonts(const Arguments &args);
      static Handle<Value> UseCNTEncodings(const Arguments &args);
      static Handle<Value> UseCNTFonts(const Arguments &args);
      static Handle<Value> UseJPEncodings(const Arguments &args);
      static Handle<Value> UseJPFonts(const Arguments &args);
      static Handle<Value> UseKREncodings(const Arguments &args);
      static Handle<Value> UseKRFonts(const Arguments &args);

      HPDF_Doc doc;

      Doc();
      bool hasError();
      Handle<Value> error();
    private:
      ~Doc();
  };
}

#endif