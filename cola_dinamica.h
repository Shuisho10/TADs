#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED


template <typename T>
class ColaD
{
public:
    ColaD();
    void vacia();
    const T& tope() const;
    void push();
    T pop();
    ~ColaD();
private:
};


#endif // COLA_DINAMICA_H_INCLUDED
