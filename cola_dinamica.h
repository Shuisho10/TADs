#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED
#include <cassert>

template <typename T>
class ColaD
{
public:
    explicit ColaD(size_t s);
    void vacia();
    const T& tope() const;
    void push();
    T pop();
    ~ColaD();
private:
    T *elementos_;
    size_t lmax_;
    size_t i_, n_;
};

template <typename T>
inline ColaD<T>::ColaD(size_t s) : lmax_(s), elementos_(new T[s]), i_(0), n_(0)
{

}




#endif // COLA_DINAMICA_H_INCLUDED
