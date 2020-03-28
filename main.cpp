#include <iostream>
#include "ListaCircularDoble.h"
#include "arbol.h"
#include "cola.h"
#include "listadoblementeenlazada.h"
#include "listasimple.h"

using namespace std;

int main()
{


    /*<<<<<<<<<<<<<<<<<<<<<< PRUEBA LISTA DOBLEMENTE ENLAZADA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    /*ListaDoblementeEnlazada<int> *nueva = new ListaDoblementeEnlazada<int>();
    nueva->insertLast(12);
    nueva->insertLast(134);
    nueva->insertLast(23);
    nueva->insertLast(34);

    NodeLD<int> *aux = nueva->head;
    while(aux != 0)
    {
        cout<< aux->data << endl;
        aux = aux->previous;
    }*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA COLA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    /*Cola<int> nuev = Cola<int>();
    nuev.insertar(2);
    nuev.insertar(1);
    nuev.insertar(1);
    nuev.insertar(3);
    nuev.insertar(57);
    nuev.insertar(1213);
    nuev.insertar(11);

    while(!nuev.colaVacia())
    {
        cout<<nuev.quitar()<< endl;
    }*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA ARBOL>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    /*Arbol *nuevo = new Arbol();
    nuevo->insertar(nuevo->raiz, "Pedro");
    nuevo->insertar(nuevo->raiz, "Pito");
    nuevo->insertar(nuevo->raiz, "Pisa");
    nuevo->insertar(nuevo->raiz, "Pocho");
    nuevo->insertar(nuevo->raiz, "Podio");
    nuevo->insertar(nuevo->raiz, "Podor");
    nuevo->insertar(nuevo->raiz, "Pudor");

    nuevo->inOrder(nuevo->raiz);
    cout<<"-------------------------------" << endl;
    nuevo->preOrder(nuevo->raiz);
    cout<<"-------------------------------" << endl;
    nuevo->posOrder(nuevo->raiz);*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA LISTA SIMPLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    /*ListaSimple<int> *nueva = new ListaSimple<int>();
    nueva->insertar(12);
    nueva->insertar(13);
    nueva->insertar(14);
    nueva->insertar(15);
    nueva->insertar(16);
    nueva->insertar(17);
    nueva->insertar(18);
    nueva->insertar(10);

    NodoLS<int> *n = nueva->leerPrimero();
    while (n != 0)
    {
        cout << n->datoNodo() << endl;
        n = n->enlaceNodo();

    }*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA LISTA CIRCULAR DOBLEMENTE ENLAZADA>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    /*ListaCircularDoble<int> listaCircularDoble;
    listaCircularDoble.insertarNodo(3);
    listaCircularDoble.insertarNodo(4);
    listaCircularDoble.insertarNodo(5);
    listaCircularDoble.insertarNodo(6);
    listaCircularDoble.insertarNodo(7);
    listaCircularDoble.insertarNodo(8);
    listaCircularDoble.imprimirLista();*/
    return 0;
}
