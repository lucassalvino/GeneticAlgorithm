#ifndef JSONARRAYOBJECT_H
#define JSONARRAYOBJECT_H
#include <iostream>
#include <cstdio>
#include <vector>
#include "../utilidades.h"
using namespace std;


class JsonArrayObject
{
public:
    JsonArrayObject();
    JsonArrayObject(string valueName);
private:
    string name;
    string json;
};

#endif // JSONARRAYOBJECT_H
