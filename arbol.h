#ifndef ARBOL_H
#define ARBOL_H

#include <jugador.h>

class Arbol
{
public:
    Arbol();

    struct Nodo
    {
        struct Nodo *izq;
        struct Nodo *der;
        Jugador jugador;
    };

    typedef struct Nodo *ABB;
    ABB raiz;
    string graphviz;


    ABB crearNodo(string nombre)
    {
        Jugador *j = new Jugador();
        j->nombre = nombre;
        ABB nuevoNodo = new(struct Nodo);
        nuevoNodo->jugador = *j;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;

        return nuevoNodo;
    }

    int menorQue(string insertado, string raiz)
    {
        if(insertado == raiz)
        {
            return 3;
        }
        for(int i = 0; i < (int)insertado.length(); i++)
        {
            char a = tolower(insertado.at(i));
            char b = tolower(raiz.at(i));
            if(a<b)
            {
                return 1;
            }
            else if (a>b)
            {
                return 2;
            }
            else
            {

            }
        }
        return 3;
    }

    void insertar(ABB &arbol, string nombre)
    {
        if(arbol == NULL)
        {
            arbol = crearNodo(nombre);
        }
        else if(menorQue(nombre,arbol->jugador.nombre) == 1)
        {
            insertar(arbol->izq, nombre);
        }
        else if(menorQue(nombre,arbol->jugador.nombre) == 2)
        {
            insertar(arbol->der, nombre);
        }
        else
        {
            return;
        }
    }

    void inOrder(ABB arbol)
    {
         if(arbol!=NULL)
         {
              inOrder(arbol->izq);
              cout << arbol->jugador.nombre<< endl;
              inOrder(arbol->der);
         }
    }
    void preOrder(ABB arbol)
    {
        if(arbol != NULL)
        {
            cout << arbol->jugador.nombre<< endl;
            preOrder(arbol->izq);
            preOrder(arbol->der);
        }
    }
    void posOrder(ABB arbol)
    {
        if(arbol!=NULL)
        {
            posOrder(arbol->izq);
            posOrder(arbol->der);
            cout << arbol->jugador.nombre << endl;
        }
    }

};

#endif // ARBOL_H
