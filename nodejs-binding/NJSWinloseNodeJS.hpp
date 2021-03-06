// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from winlose.djinni

#ifndef DJINNI_GENERATED_NJSWINLOSENODEJS_HPP
#define DJINNI_GENERATED_NJSWINLOSENODEJS_HPP


#include <cstdint>

#include <nan.h>
#include <node.h>
#include "../src/api/WinloseNodeJS.hpp"

using namespace v8;
using namespace node;
using namespace std;
using namespace api;

class NJSWinloseNodeJS: public Nan::ObjectWrap, public api::WinloseNodeJS {
public:

    static void Initialize(Local<Object> target);
    ~NJSWinloseNodeJS()
    {
        persistent().Reset();
        njs_impl.Reset();
        njs_impl.Reset();
    };
    NJSWinloseNodeJS(Local<Object> njs_implementation){njs_impl.Reset(njs_implementation);};

    int32_t add(int32_t lhs1, int32_t lhs2);

private:
    static NAN_METHOD(add);

    static NAN_METHOD(New);

    static NAN_METHOD(addRef);
    static NAN_METHOD(removeRef);
    Nan::Persistent<Object> njs_impl;
};
#endif //DJINNI_GENERATED_NJSWINLOSENODEJS_HPP
