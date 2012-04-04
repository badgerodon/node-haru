#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>
#include <node_version.h>
#include <hpdf.h>
#include <map>

using namespace v8;
using namespace node;
using namespace std;

#define raise(str) return ThrowException(Exception::TypeError(String::New(str)));

namespace Haru {
  Handle<Value> handle_error(HPDF_STATUS);
}