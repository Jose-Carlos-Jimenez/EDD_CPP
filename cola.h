#ifndef COLA_H
#define COLA_H

#include <string>

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
    std::string graph();
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

template <class T>
std::string Cola<T>::graph()
{
    std::string graphviz = "digraph{\n\tnode[shape=box]\n";
    graphviz.append("\t\n\tcolor= green;\n\tgraph[bgcolor = black];node[style = dashed color = yellow fontcolor = white]edge[color = red fontcolor = white]");
    NodoCola *tmp = frente;
    int cont= 0;
    while(tmp != NULL)
    {
        graphviz +="\n\t\"";
        graphviz +=tmp->elemento.letra;
        graphviz +=std::to_string(cont);
        graphviz +="\"[label=\"" ;
        graphviz+=tmp->elemento.getDatos();
        graphviz +="\"];";
        tmp = tmp->siguiente;
        cont++;
    }

    tmp = frente;
    cont = 0;
    while(tmp->siguiente != NULL)
    {
        graphviz +="\n\t\"";
        graphviz +=tmp->elemento.letra ;
        graphviz +=std::to_string(cont);
        graphviz +="\" -> \"";
        graphviz +=tmp->siguiente->elemento.letra;
        graphviz +=std::to_string(cont+1);
        graphviz +="\"";
        tmp = tmp->siguiente;
        cont++;
    }
    graphviz.append("\n}");
    return graphviz;
}

#endif // COLA_H
