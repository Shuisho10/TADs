#include <iostream>
#include "iotest.cpp"
#include "pila_dinamica.h"

using namespace std;

int main()
{
    PilaD<int> a,b;
    a.push(getValue<int>());
    a.push(getValue<int>());
    a.push(getValue<int>());
    b=a;
    cout << b.pop() << endl;
    cout << b.pop() << endl;
    cout << b.pop() << endl;
    return 0;
}
