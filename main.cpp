#include <iostream>
#include "Exemplo/executaagcaminhografo.h"
using namespace std;

int main()
{
    try
    {
        ExecutaAGCaminhoGrafo executa;
        executa.Executa();
    }
    catch(const char * erro)
    {
        printf ("[ERROR] Fail message: [%s]\n\n", erro);
    }
    catch(...)
    {
        printf("[ERROR] Unexpected error");
    }
    return 0;
}
