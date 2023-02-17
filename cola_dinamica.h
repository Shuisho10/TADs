#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED
#include <cassert>

template <typename T>
class ColaD
{
public:
    explicit ColaD(int s);       //Constructor por defecto
    explicit ColaD(const ColaD<T>& C); //Constructor de copia
    bool vacia() const;             //Observador de cola vacia
    bool llena() const;             //Observador de cola llena
    const T& tope() const;          //Observador del siguiente elemento en la cola

    void push(const T& in);         //Modificador de addición de elemento a la cola
    T pop();                        //Modificador de sacar elemento de la cola
    void copia(const ColaD<T>& C);

    ColaD& operator=(const ColaD<T> C); //Operador de asignación

    ~ColaD();                       //Destructor
private:
    int lmax_;
    int i_, n_;
    T *elementos_;

};

//Constructor (REQUIERE CONSTRUCTOR DE T)
template <typename T>
inline ColaD<T>::ColaD(int s) : lmax_(s), i_(0), n_(0), elementos_(new T[s])
{

}

//Constructor de copia
template <typename T>
inline ColaD<T>::ColaD(const ColaD<T>& C) : lmax_(C.lmax_),  i_(0), n_(0), elementos_(new T[lmax_])
{
    copia(C);
}

//Copia
template <typename T>
void ColaD<T>::copia(const ColaD<T>& C)
{
    assert(C.lmax_<=lmax_);
    if(!C.vacia())
    {
        for (int a=0; a<C.n_; a++)
        {
            elementos_[a]=C.elementos_[(i_+a)%lmax_];
            n_++;
        }
    }
}


//Vacia
template <typename T>
inline bool ColaD<T>::vacia() const
{
    return(n_==0);
}

//Llena
template <typename T>
inline bool ColaD<T>::llena() const
{
    return(n_==lmax_);
}

//Tope
template <typename T>
const T& ColaD<T>::tope() const
{
    assert(!vacia());
    return(elementos_[(i_+n_)%lmax_]);
}

//Push
template <typename T>
void ColaD<T>::push(const T& in)
{
    assert(!llena());
    elementos_[(i_+n_)%lmax_]=in;
    n_++;
}

//Pop
template <typename T>
T ColaD<T>::pop()
{
    assert(!vacia());
    i_=(i_+1)%lmax_;
    return(elementos_[(i_-1)%lmax_]);
}

//Operador =
template <typename T>
ColaD<T>& ColaD<T>::operator=(const ColaD<T> C)
{
    this->~ColaD();
    copia(C);
    return *this;
}

//Destructor
template <typename T>
ColaD<T>::~ColaD()
{
    delete[] elementos_;
}

#endif // COLA_DINAMICA_H_INCLUDED
