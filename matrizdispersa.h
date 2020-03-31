#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include <iostream>
#include <ficha.h>

using namespace std;

/*Nodo ortogonal perteneciente a la matriz dispersa*/
template <class T>
struct NodoOrtogonal
{
    int x, y;
    T dato;
    NodoOrtogonal* arriba;
    NodoOrtogonal* abajo;
    NodoOrtogonal* izquierda;
    NodoOrtogonal* derecha;
    NodoOrtogonal(){};
    NodoOrtogonal(T dato, int x, int y)
    {
        this->dato = dato;
        this->x = x;
        this->y = y;
        arriba = abajo = izquierda = derecha = NULL;
    }

};

/*Lista vertical la cual servirá para los nodos que llevaran datos.*/
template <class T>
struct ListaVertical
{
    NodoOrtogonal<T>* primero;
    NodoOrtogonal<T>* ultimo;
    ListaVertical()
    {
        primero = ultimo = NULL;
    }

    void insertar(NodoOrtogonal<T>* insertar)
    {
        if(this->estaVacia())
        {
            primero = ultimo = insertar;
        }
        else
        {
          if(insertar->y < primero->y)
          {
              insertarFrente(insertar);
          }
          else if(insertar->y > ultimo->y)
          {
              insertarFin(insertar);
          }
          else
          {
              insertarMedio(insertar);
          }
        }
    }

    bool estaVacia()
    {
        return primero == NULL;
    }

    void insertarFrente(NodoOrtogonal<T>* inserta)
    {
        primero->arriba= inserta;
        inserta->abajo = primero;
        primero = primero->arriba;
    }

    void insertarFin(NodoOrtogonal<T> *inserta)
    {
        ultimo->abajo = inserta;
        inserta->arriba = ultimo;
        ultimo = ultimo->abajo;
    }

    void insertarMedio(NodoOrtogonal<T> *inserta)
    {
        NodoOrtogonal<T>* temp1;
        NodoOrtogonal<T>* temp2;
        temp1 = primero;
        while(temp1->y < inserta->y)
        {
            temp1 = temp1->abajo;
        }
        temp2 = temp1->arriba;
        temp2->abajo = inserta;
        temp1->arriba = inserta;
        inserta->arriba = temp2;
        inserta->abajo = temp1;
    }

    void recorrer()
    {
        if(!estaVacia())
        {
            NodoOrtogonal<T> * temporal = primero;
            while (temporal != NULL)
            {
                cout << "y: " + to_string(temporal->y) << endl;
                temporal = temporal->abajo;
            }
        }
    }
};

/*Lista Horizontal de la matriz*/
template <class T>
struct ListaHorizontal
{
    NodoOrtogonal<T>* primero;
    NodoOrtogonal<T>* ultimo;
    ListaHorizontal()
    {
        primero = ultimo = NULL;
    }

    void insertar(NodoOrtogonal<T>* insertar)
    {
        if(this->estaVacia())
        {
            primero = ultimo = insertar;
        }
        else
        {
          if(insertar->x < primero->x)
          {
              insertarFrente(insertar);
          }
          else if(insertar->x > ultimo->x)
          {
              insertarFin(insertar);
          }
          else
          {
              insertarMedio(insertar);
          }
        }
    }

    bool estaVacia()
    {
        return primero == NULL;
    }

    void insertarFrente(NodoOrtogonal<T>* inserta)
    {
        primero->izquierda= inserta;
        inserta->derecha = primero;
        primero = primero->izquierda;
    }

    void insertarFin(NodoOrtogonal<T> *inserta)
    {
        ultimo->derecha = inserta;
        inserta->izquierda = ultimo;
        ultimo = ultimo->derecha;
    }

    void insertarMedio(NodoOrtogonal<T> *inserta)
    {
        NodoOrtogonal<T>* temp1;
        NodoOrtogonal<T>* temp2;
        temp1 = primero;
        while(temp1->x < inserta->x)
        {
            temp1 = temp1->derecha;
        }
        temp2 = temp1->izquierda;
        temp2->derecha = inserta;
        temp1->izquierda = inserta;
        inserta->izquierda = temp2;
        inserta->derecha = temp1;
    }

    void recorrer()
    {
        if(!estaVacia())
        {
            NodoOrtogonal<T> * temporal = primero;
            while (temporal != NULL)
            {
                cout << "x: " + to_string(temporal->x) << endl;
                temporal = temporal->derecha;
            }
        }
    }


};

/*Nodo que será cabecera, es decir llevará las coordenadas x.*/
template <class T>
struct NodoCabecera
{
    int x;
    NodoCabecera *siguiente;
    NodoCabecera *anterior;
    ListaVertical<T>* columna;

    NodoCabecera(int x)
    {
        this->x = x;
        columna = new ListaVertical<T>();
        siguiente = NULL;
        anterior = NULL;
    }
};

/*Lista que llevará las coordenadas en X.*/
template <class T>
struct Cabeceras
{
    NodoCabecera<T>* primero;
    NodoCabecera<T>* ultimo;

    Cabeceras()
    {
        primero = ultimo = NULL;
    }

    void insertar(NodoCabecera<T>* insertar)
    {
        if(this->estaVacia())
        {
            primero = ultimo = insertar;
        }
        else
        {
          if(insertar->x < primero->x)
          {
              insertarFrente(insertar);
          }
          else if(insertar->x > ultimo->x)
          {
              insertarFin(insertar);
          }
          else
          {
              insertarMedio(insertar);
          }
        }
    }

    bool estaVacia()
    {
        return primero == NULL;
    }

    void insertarFrente(NodoCabecera<T>* inserta)
    {
        primero->anterior= inserta;
        inserta->siguiente = primero;
        primero = primero->anterior;
    }

    void insertarFin(NodoCabecera<T> *inserta)
    {
        ultimo->siguiente= inserta;
        inserta->anterior = ultimo;
        ultimo = ultimo->siguiente;
    }

    void insertarMedio(NodoCabecera<T> *inserta)
    {
        NodoCabecera<T>* temp1;
        NodoCabecera<T>* temp2;
        temp1 = primero;
        while(temp1->x < inserta->x)
        {
            temp1 = temp1->siguiente;
        }
        temp2 = temp1->anterior;
        temp2->siguiente = inserta;
        temp1->anterior = inserta;
        inserta->anterior = temp2;
        inserta->siguiente = temp1;
    }

    void recorrer()
    {
        if(!estaVacia())
        {
            NodoCabecera<T> * temporal = primero;
            while (temporal != NULL)
            {
                cout << "x: " + to_string(temporal->x) << endl;
                temporal = temporal->siguiente;
            }
        }
    }

    bool existe(int x)
    {
        if(estaVacia())
        {
            cout<< "No existe" << endl;
            return false;
        }
        else
        {
            NodoCabecera<T>* temporal = primero;
            while(temporal != NULL)
            {
                if(temporal->x == x)
                {
                    cout<< "Existe" << endl;
                    return true;
                }
                temporal = temporal->siguiente;
            }
            cout<< "No existe" << endl;
            return false;
        }
    }

    NodoCabecera<T>* busqueda(int x)
    {
        if(existe(x))
        {
            NodoCabecera<T>* temporal = primero;
            while (temporal->x != x)
            {
                temporal = temporal->siguiente;
            }
            return temporal;
        }
        else
        {
            cout<< "No existe";
            return (new NodoCabecera<T>(-1));
        }
    }

};

/*Nodo que será en las coordenadas X*/
template <class T>
struct NodoLateral
{
    int y;
    NodoLateral *siguiente;
    NodoLateral *anterior;
    ListaHorizontal<T>* fila;

    NodoLateral(int y)
    {
        this->y = y;
        fila = new ListaHorizontal<T>();
        siguiente = NULL;
        anterior = NULL;
    }
};

/*Lista que llevará a los nodos que representan las coordenadas */
template <class T>
struct Laterales
{
    NodoLateral<T>* primero;
    NodoLateral<T>* ultimo;

    Laterales()
    {
        primero = ultimo = NULL;
    }

    void insertar(NodoLateral<T>* insertar)
    {
        if(this->estaVacia())
        {
            primero = ultimo = insertar;
        }
        else
        {
          if(insertar->y < primero->y)
          {
              insertarFrente(insertar);
          }
          else if(insertar->y > ultimo->y)
          {
              insertarFin(insertar);
          }
          else
          {
              insertarMedio(insertar);
          }
        }
    }

    bool estaVacia()
    {
        return primero == NULL;
    }

    void insertarFrente(NodoLateral<T>* inserta)
    {
        primero->anterior= inserta;
        inserta->siguiente = primero;
        primero = primero->anterior;
    }

    void insertarFin(NodoLateral<T> *inserta)
    {
        ultimo->siguiente= inserta;
        inserta->anterior = ultimo;
        ultimo = ultimo->siguiente;
    }

    void insertarMedio(NodoLateral<T> *inserta)
    {
        NodoLateral<T>* temp1;
        NodoLateral<T>* temp2;
        temp1 = primero;
        while(temp1->y < inserta->y)
        {
            temp1 = temp1->siguiente;
        }
        temp2 = temp1->anterior;
        temp2->siguiente = inserta;
        temp1->anterior = inserta;
        inserta->anterior = temp2;
        inserta->siguiente = temp1;
    }

    void recorrer()
    {
        if(!estaVacia())
        {
            NodoLateral<T> * temporal = primero;
            while (temporal != NULL)
            {
                cout << "y: " + to_string(temporal->y) << endl;
                temporal = temporal->siguiente;
            }
        }
    }

    bool existe(int y)
    {
        if(estaVacia())
        {
            cout<< "No existe" << endl;
            return false;
        }
        else
        {
            NodoLateral<T>* temporal = primero;
            while(temporal != NULL)
            {
                if(temporal->y == y)
                {
                    cout<< "Existe" << endl;
                    return true;
                }
                temporal = temporal->siguiente;
            }
            cout<< "No existe" << endl;
            return false;
        }
    }

    NodoLateral<T>* busqueda(int y)
    {
        if(existe(y))
        {
            NodoLateral<T>* temporal = primero;
            while (temporal->y != y)
            {
                temporal = temporal->siguiente;
            }
            return temporal;
        }
        else
        {
            cout<< "No existe";
            return (new NodoLateral<T>(-1));
        }
    }

};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>MATRIZ<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
template <class T>
struct MatrizDispersa
{
    Cabeceras<T>* c;
    Laterales<T>* l;
    MatrizDispersa()
    {
        c = new Cabeceras<T>();
        l = new Laterales<T>();
    }

    void insertar(int x, int y, T insertar)
    {
        NodoOrtogonal<T>*insercion = new NodoOrtogonal<T>(insertar, x, y);
        if(c->existe(x) == false)
        {
            c->insertar(new NodoCabecera<T>(x));
        }
        if(l->existe(y) == false)
        {
            l->insertar(new NodoLateral<T>(y));
        }
        NodoCabecera<T> * Ctemporal = c->busqueda(x);
        NodoLateral<T> * Ltemporal = l->busqueda(y);
        Ctemporal->columna->insertar(insercion);
        Ltemporal->fila->insertar(insercion);
    }

    T obtener(int x, int y)
    {
        NodoCabecera<T> *s = c->busqueda(x);
        NodoOrtogonal<T> *aux = s->columna->primero;
        while(aux->y < y)
        {
            aux = aux->abajo;
        }
        return aux->dato;
    }

    void eliminar(int x, int y)
    {
        NodoCabecera<T> *s = c->busqueda(x);
        NodoOrtogonal<T> *aux = s->columna->primero;
        while(aux->y < y)
        {
            aux = aux->abajo;
        }
    }

    void llenar(int x, int y)
    {
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                insertar(j, i, 0);
            }
        }
    }
};

#endif // MATRIZDISPERSA_H
