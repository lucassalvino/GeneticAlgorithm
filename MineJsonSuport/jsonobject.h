#ifndef JSONOBJECT_H
#define JSONOBJECT_H
#include <iostream>
#include <cstdio>
#include <vector>
#include "../utilidades.h"
using namespace std;

class JsonObject
{
public:
    JsonObject(string nameObject);
    string GetJsonObject();
    string GetName();
    void AddIntValue(string name, int value);
    void AddDoubleValue(string name, double value);
    void AddStringValue(string name, string value);
    void AddBooleanValue(string name, bool value);
    void AddObjectJson(JsonObject* object);
    void AddObjectValue(string object);
    void AddVectorInt(string name, vector<int> value);
    void AddVectorDouble(string name, vector<double> value);
    void AddVectorString(string name, vector<string> value);
    string GetNameFormat(string name);
private:
    string json;
    string name;
    void __AddName(string name);
    string __GetFormatStrint(string strvalue);

    template<class T>
    class ConvertVector{
    public:
        static string GetJsonArrayFromVectorNumber( vector<T> value){
            string json = "[";
            for(int i = 0, n = (int)value.size(); i < n; i++){
                json+=UtilidadeConvert<T>::GetNumber(value[i]);
                if(i != (n-1)) json += ",";
            }
            json+="]";
            return json;
        }
    };
};

#endif // JSONOBJECT_H
