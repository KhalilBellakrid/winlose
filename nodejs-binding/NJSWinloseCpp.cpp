// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from winlose.djinni

#include "NJSWinloseCpp.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSWinlose::getVersion) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSWinlose::getVersion needs 0 arguments");
    }

    //Check if parameters have correct types

    auto result = Winlose::getVersion();

    //Wrap result in node object
    auto arg_0 = Nan::New<String>(result).ToLocalChecked();

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSWinlose::callAdd) {

    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        return Nan::ThrowError("NJSWinlose::callAdd needs 2 arguments");
    }

    //Check if parameters have correct types
    auto arg_0 = Nan::To<int32_t>(info[0]).FromJust();
    auto arg_1 = Nan::To<int32_t>(info[1]).FromJust();

    //Unwrap current object and retrieve its Cpp Implementation
    NJSWinlose* obj = Nan::ObjectWrap::Unwrap<NJSWinlose>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSWinlose::callAdd : implementation of Winlose is not valid");
    }

    auto result = cpp_impl->callAdd(arg_0,arg_1);

    //Wrap result in node object
    auto arg_2 = Nan::New<Int32>(result);

    //Return result
    info.GetReturnValue().Set(arg_2);
}
NAN_METHOD(NJSWinlose::newInstance) {

    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        return Nan::ThrowError("NJSWinlose::newInstance needs 1 arguments");
    }

    //Check if parameters have correct types
    Local<Object> njs_arg_0 = info[0]->ToObject(Nan::GetCurrentContext()).ToLocalChecked();
    NJSWinloseNodeJS *njs_ptr_arg_0 = static_cast<NJSWinloseNodeJS *>(Nan::GetInternalFieldPointer(njs_arg_0,0));
    std::shared_ptr<NJSWinloseNodeJS> arg_0(njs_ptr_arg_0);


    auto result = Winlose::newInstance(arg_0);

    //Wrap result in node object
    auto arg_1_wrap = NJSWinlose::wrap(result);
    auto arg_1 = Nan::ObjectWrap::Unwrap<NJSWinlose>(arg_1_wrap)->handle();


    //Return result
    info.GetReturnValue().Set(arg_1);
}

NAN_METHOD(NJSWinlose::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSWinlose function can only be called as constructor (use New)");
    }

    //Check if NJSWinlose::New called with right number of arguments
    if(info.Length() != 1)
    {
        return Nan::ThrowError("NJSWinlose::New needs same number of arguments as api::Winlose::newInstance method");
    }

    //Unwrap objects to get C++ classes
    Local<Object> njs_arg_0 = info[0]->ToObject(Nan::GetCurrentContext()).ToLocalChecked();
    NJSWinloseNodeJS *njs_ptr_arg_0 = static_cast<NJSWinloseNodeJS *>(Nan::GetInternalFieldPointer(njs_arg_0,0));
    std::shared_ptr<NJSWinloseNodeJS> arg_0(njs_ptr_arg_0);


    //Call factory
    auto cpp_instance = api::Winlose::newInstance(arg_0);
    NJSWinlose *node_instance = new NJSWinlose(cpp_instance);

    if(node_instance)
    {
        //Wrap and return node instance
        node_instance->Wrap(info.This());
        node_instance->Ref();
        info.GetReturnValue().Set(info.This());
    }
}


Nan::Persistent<ObjectTemplate> NJSWinlose::Winlose_prototype;

Handle<Object> NJSWinlose::wrap(const std::shared_ptr<api::Winlose> &object) {
    Nan::HandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(Winlose_prototype);

    Handle<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance();
        NJSWinlose *new_obj = new NJSWinlose(object);
        if(new_obj)
        {
            new_obj->Wrap(obj);
            new_obj->Ref();
        }
    }
    else
    {
        Nan::ThrowError("NJSWinlose::wrap: object template not valid");
    }
    return obj;
}

NAN_METHOD(NJSWinlose::isNull) {
    NJSWinlose* obj = Nan::ObjectWrap::Unwrap<NJSWinlose>(info.This());
    auto cpp_implementation = obj->getCppImpl();
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSWinlose::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSWinlose::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSWinlose").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"getVersion", getVersion);
    Nan::SetPrototypeMethod(func_template,"callAdd", callAdd);
    Nan::SetPrototypeMethod(func_template,"newInstance", newInstance);
    //Set object prototype
    Winlose_prototype.Reset(objectTemplate);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);

    //Add template to target
    target->Set(Nan::New<String>("NJSWinlose").ToLocalChecked(), func_template->GetFunction());
}
