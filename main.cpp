#include <iostream>
#include "Exemplo/executaagcaminhografo.h"
using namespace std;

int main()
{
    try
    {
        ExecutaAGCaminhoGrafo executa;
        executa.Executa(true, false, "Logs.log");
    }
    catch(const char * erro)
    {
        printf ("[ERROR] [%s]\n\n", erro);
    }
    catch(...)
    {
        printf("[ERROR] Unexpected error");
    }
    return 0;
}
