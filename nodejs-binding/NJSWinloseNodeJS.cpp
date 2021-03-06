// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from winlose.djinni

#include "NJSWinloseNodeJS.hpp"

using namespace v8;
using namespace node;
using namespace std;

int32_t NJSWinloseNodeJS::add(int32_t lhs1, int32_t lhs2)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<Int32>(lhs1);
    auto arg_1 = Nan::New<Int32>(lhs2);
    Handle<Value> args[2] = {arg_0,arg_1};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSWinloseNodeJS::add fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("add").ToLocalChecked()).ToLocalChecked();
    auto handle = this->handle();
    auto result_add = Nan::CallAsFunction(calling_funtion->ToObject(),handle,2,args);
    if(result_add.IsEmpty())
    {
        Nan::ThrowError("NJSWinloseNodeJS::add call failed");
    }
    auto checkedResult_add = result_add.ToLocalChecked();
    auto fResult_add = Nan::To<int32_t>(checkedResult_add).FromJust();
    return fResult_add;
}

NAN_METHOD(NJSWinloseNodeJS::addRef) {

    NJSWinloseNodeJS *obj = Nan::ObjectWrap::Unwrap<NJSWinloseNodeJS>(info.This());
    obj->Ref();
}

NAN_METHOD(NJSWinloseNodeJS::removeRef) {

    NJSWinloseNodeJS *obj = Nan::ObjectWrap::Unwrap<NJSWinloseNodeJS>(info.This());
    obj->Unref();
}

NAN_METHOD(NJSWinloseNodeJS::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSWinloseNodeJS function can only be called as constructor (use New)");
    }

    NJSWinloseNodeJS *node_instance = nullptr;
    if(info[0]->IsObject())
    {
        node_instance = new NJSWinloseNodeJS(info[0]->ToObject());
    }
    else
    {
        return Nan::ThrowError("NJSWinloseNodeJS::New requires an implementation from node");
    }

    if(node_instance)
    {
        //Wrap and return node instance
        node_instance->Wrap(info.This());
        node_instance->Ref();
        info.GetReturnValue().Set(info.This());
    }
}

void NJSWinloseNodeJS::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSWinloseNodeJS::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSWinloseNodeJS").ToLocalChecked());
    Nan::SetPrototypeMethod(func_template,"addRef", addRef);
    Nan::SetPrototypeMethod(func_template,"removeRef", removeRef);

    //Add template to target
    target->Set(Nan::New<String>("NJSWinloseNodeJS").ToLocalChecked(), func_template->GetFunction());
}
