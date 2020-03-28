#ifndef COLA_H
#define COLA_H

template <class T>
class Cola
{
protected:
    class NodoCola
    {
    public:
        NodoCola* siguiente;
        T elemento;
        NodoCola(T x)
        {
            elemento = x;
            siguiente = 0;
        }

    };
    NodoCola* frente;
    NodoCola* final;
public:
    Cola()
    {
      frente = final = 0;
    };
    void borrarCola();
    void insertar(T elemento);
    T quitar();
    T frenteCola() const;
    bool colaVacia() const;
    ~Cola()
    {
        Cola<T>::borrarCola();
    }
};

template <class T>
void Cola<T>:: insertar(T elemento)
{
    NodoCola* nuevo;
    nuevo = new NodoCola(elemento);
    if(colaVacia())
    {
        frente = nuevo;
    }
    else
    {
        final->siguiente = nuevo;
    }
    final = nuevo;
}

template <class T>
void Cola<T> :: borrarCola()
{
    for (;frente != 0;)
    {
        NodoCola* a;
        a = frente;
        frente = frente -> siguiente;
        delete a;
    }
    final = 0;
}

template <class T>
T Cola<T> :: quitar()
{
     if (colaVacia())
     throw "Cola vacía, no se puede extraer.";
     T aux = frente -> elemento;
     NodoCola* a = frente;
     frente = frente -> siguiente;
     delete a;
     return aux;
}

template <class T>
T Cola<T> :: frenteCola()const
{
    if (colaVacia())
    throw "Cola vacía";
    return frente -> elemento;
}



template <class T>
bool Cola<T> :: colaVacia() const
{
    return frente == 0;
}

#endif // COLA_H
