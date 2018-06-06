#include "NJSWinlose.h"
#include <iostream>
using namespace std;
using namespace v8;
using namespace node;

NAN_METHOD(NJSWinlose::getVersion) {
        cout<<" >>>> Start getVersion"<<endl;
        std::string version = Winlose::getVersion();
        cout<<" >>>> Got version: "<<version<<endl;
        auto njsVersion = Nan::New<String>(version).ToLocalChecked();
        cout<<" >>>> Got njsVersion: "<<endl;
        info.GetReturnValue().Set(njsVersion);
}

NAN_METHOD(NJSWinlose::New) {
        if(!info.IsConstructCall())
        {
            return Nan::ThrowError("NJSWinlose function can only be called as constructor (use New)");
        }
        NJSWinlose *node_instance = new NJSWinlose();
        if(node_instance)
        {
            node_instance->Wrap(info.This());
            node_instance->Ref();
            info.GetReturnValue().Set(info.This());
        }
}

void NJSWinlose::Initialize(Local<Object> target) {
    Nan::HandleScope scope;
    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSWinlose::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);
    func_template->SetClassName(Nan::New<String>("NJSWinlose").ToLocalChecked());
    Nan::SetPrototypeMethod(func_template,"getVersion", getVersion);
    target->Set(Nan::New<String>("NJSWinlose").ToLocalChecked(), func_template->GetFunction());
}