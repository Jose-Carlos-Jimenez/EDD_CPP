#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <string>
#include "jugador.h"

using namespace std;

template <class T> class NodoLS
{
protected:
    T dato;
public:
    NodoLS <T>* enlace;
    NodoLS (T t)
    {
        dato = t;
        enlace = 0;
    }

    NodoLS (T p, NodoLS<T>* n)
    {
        dato = p;
        enlace = n;
    }

    T datoNodo()
    {
        return dato;
    }

    NodoLS<T>* enlaceNodo()
    {
        return enlace;
    }
    void ponerEnlace(NodoLS<T>* sgte)
    {
       enlace = sgte;
    }
};

template <class T> class ListaSimple
{
protected:
    NodoLS<T>* primero;
public:
    ListaSimple(){ primero = 0;}
    NodoLS<T>* leerPrimero() const { return primero;}
    void insertarCabezaLista(T entrada);
    void insertarUltimo(T entrada);
    void insertar(T entrada);
    void insertarLista(NodoLS<T>* anterior, T entrada);
    NodoLS<T>* ultimo();
    void eliminar(T entrada);
    NodoLS<T>* buscarLista(T destino);
    string getGraph(char l);
    string getGraph(int c);
};

template <class T>
string ListaSimple<T>::getGraph(char l)
{
    cout << l << endl;
    string graph = "digraph D{\n\tnode[shape=box]\n\trankdir=LR\n";
    graph.append("color= green;graph[bgcolor = black];node[style = dashed color = yellow fontcolor = white]edge[color = red fontcolor = white]");
    NodoLS<T> *aux = primero;
    while(aux != 0)
    {
        if(aux->enlaceNodo()!= NULL)
        {
            graph+="\t\"";
            graph+= aux->datoNodo().nombre;
            graph+=", ";
            graph+=to_string(aux->datoNodo().puntos);
            graph += "\" -> \"";
            graph += aux->enlaceNodo()->datoNodo().nombre;
            graph+=", ";
            graph+=to_string(aux->enlaceNodo()->datoNodo().puntos);
            graph += "\";\n";
        }
        aux = aux->enlaceNodo();
    }
    graph+= "}";
    return  graph;
};

template <class T>
string ListaSimple<T>::getGraph(int opc)
{
    cout << opc << endl;
    string graph = "digraph D{\n\tnode[shape=box]\n\trankdir=LR\n";
    graph.append("color= green;graph[bgcolor = black];node[style = dashed color = yellow fontcolor = white]edge[color = red fontcolor = white]");
    NodoLS<T> *aux = primero;
    while(aux != 0)
    {
        if(aux->enlaceNodo()!= NULL)
        {
            graph+="\t\"";
            graph+= to_string((int)aux->datoNodo());
            graph += "\" -> \"";
            graph += to_string((int)aux->enlaceNodo()->datoNodo());
            graph += "\";\n";
        }
        aux = aux->enlaceNodo();
    }
    graph+= "}";
    return  graph;
};

// inserción por la cabeza de la lista
template <class T>
void ListaSimple<T>::insertarCabezaLista(T entrada)
{
    NodoLS<T>* nuevo;
    nuevo = new NodoLS<T>(entrada);
    nuevo -> ponerEnlace(primero);// enlaza nuevo con primero
    primero = nuevo; // mueve primero y apunta al nuevo nodo
}

// inserción por la cola de la lista
template <class T>
void ListaSimple<T>::insertarUltimo(T entrada)
{
    NodoLS<T>* ultimo = this->ultimo();
    NodoLS<T> *nuevo = new NodoLS<T>(entrada);
    ultimo -> ponerEnlace(nuevo);
    ultimo = nuevo;
}

// recorre hasta el último nodo la lista
template <class T>
NodoLS<T>* ListaSimple<T>::ultimo()
{
    NodoLS<T>* p = primero;
    if (p == 0 ) throw "Error, lista vacía";
    while (p -> enlaceNodo()!= 0) p = p -> enlaceNodo();
    return p;
}

template <class T>
void ListaSimple<T>::insertar(T entrada)
{
    NodoLS<T> * aux = this->leerPrimero();
    if(aux == 0)
    {
        insertarCabezaLista(entrada);
    }
    else
    {
        insertarUltimo(entrada);
    }
}

// inserción entre dos nodos de la lista
template <class T> void
ListaSimple<T>::insertarLista(NodoLS<T>* ant, T entrada)
{
    NodoLS<T>* nuevo = new NodoLS<T>(entrada);
    nuevo -> ponerEnlace(ant -> enlaceNodo());
    ant -> ponerEnlace(nuevo);
}

// búsqueda, si el elemento correspondiente a T es una clase
// debe redefinir el operador de comparación ==
template <class T>
NodoLS<T>* ListaSimple<T>::buscarLista(T destino)
{
    NodoLS<T>* indice;
    for (indice = primero; indice!= 0; indice = indice->enlaceNodo())
        if (destino == indice -> datoNodo())
            return indice;
    return 0;
}

// borra el primer nodo encontrado con dato
template <class T>
void ListaSimple<T>:: eliminar(T entrada)
{
    NodoLS<T> *actual, *anterior;
    bool encontrado;
    actual = primero;
    anterior = 0;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != 0) && !encontrado)
    {
        encontrado = (actual -> datoNodo() == entrada);
        if (!encontrado)
        {
            anterior = actual;
            actual = actual -> enlaceNodo();
        }
    }
    // enlace del nodo anterior con el siguiente
    if (actual != 0)
    {
        // Distingue entre cabecera y resto de la lista
        if (actual == primero)
        {
        primero = actual -> enlaceNodo();
        }
        else
        anterior -> ponerEnlace(actual -> enlaceNodo());
        delete actual;
    }
}

#endif // LISTASIMPLE_H
