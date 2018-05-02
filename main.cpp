#include <iostream>
#include "Exemplo/executaagcaminhografo.h"
using namespace std;

int main()
{
    try
    {
        ExecutaAGCaminhoGrafo executa;
        executa.Executa(true, true, "C:/Fontes/LogsAG");
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
