#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED

//Lista cicular de nodos con doble enlazamiento
template <typename T>
struct ListaCir
{
public:

    struct posicion
    {
        T e;
        posicion* ant,sig;
        posicion(posicion* a,posicion* s,T r): ant(a), sig(s), e(r) {}
    };


    ListaCir(); //Constructor

    bool vacia() const; //Observador de vacio
    const T& inipos() const; //Observador del puntero L
    const T& elemento(posicion p) const; //Obsetvador de elemento en esa posicion
    posicion siguiente(posicion p) const; //Observador a la siguiente posicion
    posicion anterior(posicion p) const; //Observador a la posicion anterior

    void insertar(const T& x, posicion p); //Modificador de insercion
    void eliminar(posicion p); //Modificador de eliminacion

    ~ListaCir(); //Destructor
private:
    posicion* L;
};



#endif // LISTA_DINAMICA_H_INCLUDED
