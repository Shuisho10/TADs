#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED

//Lista cicular de nodos con doble enlazamiento
#define POS_NULA nullptr
template <typename T>
struct ListaCir
{
public:


    struct posicion
    {
        T e;
        posicion* ant,*sig;
        posicion(posicion* a,posicion* s,T r): ant(a), sig(s), e(r) {}
    };


    ListaCir(); //Constructor

    bool vacia() const; //Observador de vacio
    posicion inipos(); //Observador del puntero L
    const T& elemento(posicion p) const; //Obsetvador de elemento en esa posicion
    posicion siguiente(posicion p) const; //Observador a la siguiente posicion
    posicion anterior(posicion p) const; //Observador a la posicion anterior

    void insertar(const T& x, posicion p); //Modificador de insercion
    void eliminar(posicion p); //Modificador de eliminacion

    ~ListaCir(); //Destructor
private:
    posicion* L_;
};

template <typename T>
ListaCir<T>::ListaCir() : L_(POS_NULA)
{

}

template <typename T>
bool ListaCir<T>::vacia() const
{
    return (L_==POS_NULA);
}

template <typename T>
typename ListaCir<T>::posicion ListaCir<T>::inipos()
{
    return(*L_);
}

template <typename T>
const T& ListaCir<T>::elemento(posicion p) const
{
    return(p.e);
}

template <typename T>
typename ListaCir<T>::posicion ListaCir<T>::anterior(posicion p) const
{
    return(p->ant);
}

template <typename T>
typename ListaCir<T>::posicion ListaCir<T>::siguiente(posicion p) const
{
    return(p->sig);
}


template <typename T>
void ListaCir<T>::insertar(const T& x, posicion p)
{

}

template <typename T>
void ListaCir<T>::eliminar(posicion p)
{
    assert(!vacia());
    if(L_==p)
        L_=p.sig();
    p.siguiente().ant=p.anterior();
    p.anterior().sig=p.siguiente();
    delete p;
}

template <typename T>
ListaCir<T>::~ListaCir()
{
    ListaCir<T>::posicion* n=L_;
    while(n->sig!=n)
    {
        L_=n->sig;
        delete n;
    }
    delete n;
}


#endif // LISTA_DINAMICA_H_INCLUDED
