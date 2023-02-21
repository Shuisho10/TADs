#include <iostream>
#include "iotest.cpp"
#include "lista_circular.h"

using namespace std;

int main()
{
    ListaCir<int> a;
    a.insertar(2,a.inipos());

    return 0;
}
