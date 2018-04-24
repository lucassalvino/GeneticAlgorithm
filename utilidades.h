#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
using namespace std;
template <class T>
class UtilidadeConvert
{
public:
    static string GetNumber(T number){
        ostringstream Convert;
        Convert << number;
        return Convert.str();
    }
};
#endif // UTILIDADES_H
