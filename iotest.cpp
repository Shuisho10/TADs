#include <iostream>

template <typename T>
T getValue()
{
    std::cout << "Introduce un valor: ";
    T a;
    std::cin >> a;
    return a;
}
