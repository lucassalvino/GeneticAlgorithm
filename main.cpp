#include <iostream>
#include "Exemplo/executaagcaminhografo.h"
using namespace std;

int main()
{
    try
    {
        ExecutaAGCaminhoGrafo executa;
        executa.Executa(true);
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
