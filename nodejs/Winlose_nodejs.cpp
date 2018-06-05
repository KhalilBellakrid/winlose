#include <nan.h>
#include <node.h>
#include "NJSWinlose.h"

using namespace v8;
using namespace node;

static void initAll(Local<Object> target) {
    Nan::HandleScope scope;
    NJSWinlose::Initialize(target);
}

NODE_MODULE(Winlose_nodejs,initAll);