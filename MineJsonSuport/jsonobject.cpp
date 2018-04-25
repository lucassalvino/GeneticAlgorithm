#include "jsonobject.h"

JsonObject::JsonObject()
{
    name = json = "";
}

JsonObject::JsonObject(string nameObject)
{
    name = nameObject;
    json = "";
}

string JsonObject::GetName(){
    return name;
}

void JsonObject::SetName(string value)
{
    name = value;
}

string JsonObject::GetJsonObject(){
    string ret = "\""+name+"\":{"+json+"}";
    return ret;
}

string JsonObject::GetJsonObjectNoName()
{
    return string("{"+json+"}");
}

string JsonObject::__GetFormatStrint(string strvalue){
    return ("\""+strvalue+"\"");
}

string JsonObject::GetNameFormat(string name){
    return (__GetFormatStrint(name)+string(":"));
}

void JsonObject::AddObjectValue(string object){
    if(json != "") json += ",";
    json += object;
}

void JsonObject::AddIntValue(string name, int value){
    __AddName(name);
    json += UtilidadeConvert<int>::GetNumber(value);
}

void JsonObject::AddDoubleValue(string name, double value){
    __AddName(name);
    json += UtilidadeConvert<double>::GetNumber(value);
}

void JsonObject::AddStringValue(string name, string value){
    __AddName(name);
    json += __GetFormatStrint(value);
}

void JsonObject::AddBooleanValue(string name, bool value){
    __AddName(name);
    json += value ? string("true"):string("false");
}

void JsonObject::AddVectorInt(string name, vector<int> value){
    __AddName(name);
    json+=ConvertVector<int>::GetJsonArrayFromVectorNumber(value);
}

void JsonObject::AddVectorDouble(string name, vector<double> value){
    __AddName(name);
    json+=ConvertVector<double>::GetJsonArrayFromVectorNumber(value);
}

void JsonObject::AddVectorString(string name, vector<string> value){
    __AddName(name);
    json += "[";
    for(int i = 0, n = value.size(); i<n;i++){
        json += __GetFormatStrint(value[i]);
        if(i != (n-1)) json+=",";
    }
    json += "]";
}

void JsonObject::__AddName(string name){
    if(json != "") json += ",";
    json += GetNameFormat(name);
}
