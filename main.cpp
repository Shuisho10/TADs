#include <iostream>
#include "iotest.cpp"
#include "pila_dinamica.h"

using namespace std;

int main()
{
    PilaD<int> a;
    a.push(getValue<int>());
    a.push(getValue<int>());
    a.push(getValue<int>());
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    return 0;
}
