#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include "hpdf.h"

#include <v8.h>
#include <node.h>

jmp_buf env;
error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data) {
	printf("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no, (HPDF_UINT)detail_no);
	longjmp(env, 1);
}

using namespace v8;
using namespace node;

class PDF {
private:
	HPDF_Doc pdf;
	
public:
	PDF() {
		pdf = HPDF_New();
	}
	~PDF() {
		HPDF_Free(pdf);
	}
	
	void newDoc() {
		HPDF_STATUS status = 
		if (HPDF_NewDoc(pdf) != HPDF_OK) {
			throw 
		}
	}
};

extern "C" void init(Handle<Object> target) {
  HandleScope scope;
  NODE_SET_METHOD(target, "solve", Solve);
}