#ifndef NJSWINLOSE_H
#define NJSWINLOSE_H

#include "../src/Winlose.h"
#include <nan.h>
#include <node.h>

using namespace v8;
using namespace node;

class NJSWinlose : public Nan::ObjectWrap, public Winlose {
public:
    static void Initialize(Local<Object> target);
    ~NJSWinlose() {};
private:
    static NAN_METHOD(getVersion);
    static NAN_METHOD(New);
};

#endif //NJSWINLOSE_H