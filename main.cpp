#include <iostream>
#include "iotest.cpp"
#include "cola_dinamica.h"

using namespace std;

int main()
{
    ColaD<int> a(5);
    a.push(getValue<int>());
    a.push(getValue<int>());
    a.push(getValue<int>());
    a.push(getValue<int>());
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    return 0;
}
