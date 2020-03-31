#ifndef ARBOL_H
#define ARBOL_H

#include <jugador.h>

class Arbol
{
public:
    Arbol()
    {
        raiz = NULL;
        graphviz = "";
    }

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

    void inOrderG(ABB arbol)
    {
        if(arbol != NULL)
        {
            inOrderG(arbol->izq);
            graphviz += arbol->jugador.nombre;
            graphviz += "->";
            inOrderG(arbol->der);
        }
    }

    string graphInOrder(ABB arbol)
    {
        graphviz = "";
        graphviz += "digraph INORDER{\n\t";
        graphviz += "node[shape=box]\n\trankdir=LR\n\t";
        inOrderG(arbol);
        graphviz[graphviz.length()-1] = ' ';
        graphviz[graphviz.length()-2] = ' ';
        graphviz +="\n}";
        return  graphviz;
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

    void preOrderG(ABB arbol)
    {
        if(arbol != NULL)
        {
            graphviz += arbol->jugador.nombre;
            graphviz += "->";
            preOrderG(arbol->izq);
            preOrderG(arbol->der);
        }
    }

    string graphPreOrder(ABB arbol)
    {
        graphviz = "";
        graphviz += "digraph PREORDER{\n\t";
        graphviz += "node[shape=box]\n\trankdir=LR\n\t";
        preOrderG(arbol);
        graphviz[graphviz.length()-1] = ' ';
        graphviz[graphviz.length()-2] = ' ';
        graphviz +="\n}";
        return  graphviz;
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

    void posOrderG(ABB arbol)
    {
        if(arbol != NULL)
        {
            posOrderG(arbol->izq);
            posOrderG(arbol->der);
            graphviz += arbol->jugador.nombre;
            graphviz += "->";
        }
    }

    string graphPosOrder(ABB arbol)
    {
        graphviz = "";
        graphviz += "digraph PREORDER{\n\t";
        graphviz += "node[shape=box]\n\trankdir=LR\n\t";
        posOrderG(arbol);
        graphviz[graphviz.length()-1] = ' ';
        graphviz[graphviz.length()-2] = ' ';
        graphviz +="\n}";
        return  graphviz;
    }

    string graphTree(ABB arbol)
    {
       graphviz = "digraph TREE{\n\t";
       graph(arbol);
       graphviz += "}";
       return  graphviz;
    }

    void graph(ABB arbol)
    {
        if(arbol)
        {
            if(arbol->izq)
            {
                graphviz += arbol->jugador.nombre;
                graphviz += "->";
                graphviz += arbol->izq->jugador.nombre;
                graphviz += "\n\t";
            }
            if(arbol->der)
            {
                graphviz += arbol->jugador.nombre;
                graphviz += "->";
                graphviz += arbol->der->jugador.nombre;
                graphviz += "\n\t";
            }
            graph(arbol->izq);
            graph(arbol->der);
        }
    }

};

#endif // ARBOL_H
