#include <iostream>
#include <string>

using namespace std;

template <typename T>
T getValue(string text="un valor")
{
    cout << "Introduce " << text << ": ";
    T a;
    cin >> a;
    return a;
}
