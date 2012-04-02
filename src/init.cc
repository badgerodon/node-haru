#include "init.h"
#include "doc.h"
#include "page.h"

using namespace Haru;

extern "C" void init(Handle<Object> target) {
  HandleScope scope;

  Doc::Initialize(target);
  Page::Initialize(target);
}