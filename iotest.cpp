#include <iostream>

template <typename T>
T getValue()
{
    std::cout << "Introduce un valor: " << std::endl;
    T a;
    std::cin >> a;
    return a;
}
