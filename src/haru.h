#ifndef __NODE_HARU_H__
#define __NODE_HARU_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>
#include <node_version.h>

using namespace v8;
using namespace node;

namespace Haru {	
	class Doc: public node::ObjectWrap {
		public:
			static Persistent<FunctionTemplate> constructor;
			static Local<Value> Error(HPDF_STATUS status);
			
			static void Initialize(Handle<Object> target);
			// API functions
			static Handle<Value> New(const Arguments &args);
			static Handle<Value> SaveToFile(const Arguments &args);
			static Handle<Value> SaveToStream(const Arguments &args);
			static Handle<Value> GetStreamSize(const Arguments &args);
			static Handle<Value> ReadFromStream(const Arguments &args);
			static Handle<Value> ResetStream(const Arguments &args);
			static Handle<Value> SetPagesConfiguration(const Arguments &args);
			static Handle<Value> SetPageLayout(const Arguments &args);
			static Handle<Value> GetPageLayout(const Arguments &args);
			static Handle<Value> SetPageMode(const Arguments &args);
			static Handle<Value> GetPageMode(const Arguments &args);
			static Handle<Value> SetOpenAction(const Arguments &args);
			static Handle<Value> GetCurrentPage(const Arguments &args);
			static Handle<Value> AddPage(const Arguments &args);
			static Handle<Value> InsertPage(const Arguments &args);
			static Handle<Value> AddPageLabel(const Arguments &args);
			static Handle<Value> GetFont(const Arguments &args);
			static Handle<Value> LoadType1FontFromFile(const Arguments &args);
			static Handle<Value> LoadTTFontFromFile(const Arguments &args);
			static Handle<Value> LoadTTFontFromFile2(const Arguments &args);
			static Handle<Value> UseJPFonts(const Arguments &args);
			static Handle<Value> UseKRFonts(const Arguments &args);
			static Handle<Value> UseCNSFonts(const Arguments &args);
			static Handle<Value> UseCNTFonts(const Arguments &args);
			static Handle<Value> GetEncoder(const Arguments &args);
			static Handle<Value> GetCurrentEncoder(const Arguments &args);
			static Handle<Value> SetCurrentEncoder(const Arguments &args);
			static Handle<Value> UseJPEncodings(const Arguments &args);
			static Handle<Value> UseKREncodings(const Arguments &args);
			static Handle<Value> UseCNSEncodings(const Arguments &args);
			static Handle<Value> UseCNTEncodings(const Arguments &args);
			static Handle<Value> CreateOutline(const Arguments &args);
			static Handle<Value> LoadPngImageFromFile(const Arguments &args);
			static Handle<Value> LoadPngImageFromFile2(const Arguments &args);
			static Handle<Value> LoadRawImageFromFile(const Arguments &args);
			static Handle<Value> LoadRawImageFromMem(const Arguments &args);
			static Handle<Value> LoadPngImageFromMem(const Arguments &args);
			static Handle<Value> LoadJpegImageFromMem(const Arguments &args);
			static Handle<Value> LoadJpegImageFromFile(const Arguments &args);
			static Handle<Value> SetInfoAttr(const Arguments &args);
			static Handle<Value> GetInfoAttr(const Arguments &args);
			static Handle<Value> SetInfoDateAttr(const Arguments &args);
			static Handle<Value> SetPassword(const Arguments &args);
			static Handle<Value> SetPermission(const Arguments &args);
			static Handle<Value> SetEncryptionMode(const Arguments &args);
			static Handle<Value> SetCompressionMode(const Arguments &args);
			
			PDF();
		
		private:
			~PDF();
	}
	class Page: public node::ObjectWrap {}
	class Pages: public node::ObjectWrap {}
	class Stream: public node::ObjectWrap {}
	class Image: public node::ObjectWrap {}
	class Font: public node::ObjectWrap {}
	class Outline: public node::ObjectWrap {}
	class Encoder: public node::ObjectWrap {}
	class ThreeDMeasure: public ndoe::ObjectWrap {}
	class ExData: public node::ObjectWrap {}
	class Destination: public node::ObjectWrap {}
	class XObject: public node::ObjectWrap {}
	class Annotation: public node::ObjectWrap {}
	class ExtGState: public node::ObjectWrap {}
	class FontDef: public node::ObjectWrap {}
	class U3D: public node::ObjectWrap {}
	class JavaScript: public node::ObjectWrap {}
	class Error: public node::ObjectWrap {}
	class MMgr: public node::ObjectWrap {}
	class Dict: public node::ObjectWrap {}
	class EmbeddedFile: public node::ObjectWrap {}
	class OutputIntent: public node::ObjectWrap {}
	class Xref: public node::ObjectWrap {}
}

#endif