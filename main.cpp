#include <iostream>
#include "Base/include/population.hpp"
#include "Base/include/managergeneticalgorithm.hpp"
using namespace std;

int main()
{
    try
    {
        Population<int> population;
        population.InitilizePopulation(10,3);
        cout << "Hello World!" << endl;
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
