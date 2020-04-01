#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#endif // LISTACIRCULARDOBLE_H
#include <iostream>
#include <utility>

template <typename T>
class ListaCircularDoble
{
    struct NodoLCD
    {
        T dato;
        NodoLCD * sig;
        NodoLCD * prev;
        NodoLCD(T value) : dato(std::move(value)),
                        sig(nullptr),
                        prev(nullptr)
                        {}
    };
    NodoLCD *head, *tail;

public:
    ListaCircularDoble() : head(nullptr),
                                    tail(nullptr)
                                    {}
    //Copia del constructor
    ListaCircularDoble(const ListaCircularDoble &);

    //copy assignment
    ListaCircularDoble& operator=(const ListaCircularDoble& cdll)
    {
        ListaCircularDoble  temp(cdll);
        temp.swap(*this);
        return *this;
    }
    //move constructor
    ListaCircularDoble(ListaCircularDoble&&) noexcept;
    //move assignment
    ListaCircularDoble& operator=(ListaCircularDoble&& cdll) noexcept
    {
        cdll.swap(*this);
        return *this;
    }
    ~ListaCircularDoble();

    void insertarNodo(T);
    void borrarNodo(T);

    template <typename U>
    friend std::ostream & operator<<(std::ostream & os, const ListaCircularDoble<U> & cdll)
    {
        cdll.imprimirLista(os);
        return os;
    }

    void imprimirLista() const
    {
        NodoLCD *tmp = head;
        while(tmp->sig != head)
        {
            std::cout << tmp->dato << ' ';
            tmp = tmp->sig;
        }
        std::cout << tmp->dato << '\n';
    }

    std::string graph()
    {
        std::string graphviz = "digraph{\n\tnode[shape=box];\n\tsplines=ortho\n";
        graphviz.append("\t\n\tcolor= green;\n\tgraph[bgcolor = black];node[style = dashed color = yellow fontcolor = white]edge[color = red fontcolor = white]");
        NodoLCD *tmp = head;
        while(tmp->sig != head)
        {
            graphviz.append( "\n\t\"" + tmp->dato + "\"->\"" + tmp->sig->dato + "\"[dir=both");
            graphviz.append("];");
            tmp = tmp->sig;
        }
        graphviz.append("\n\t\"" + tmp->dato + "\" -> \"" + tmp->sig->dato + "\" [dir=both constraint=false];");
        graphviz.append("\n}");
        return graphviz;
    }

private:

    struct NodoLCD *buscar(T value)
    {
        NodoLCD *nodo = head;
        while(nodo->sig != head)
        {
            if(nodo->dato == value)
            {
                return nodo;
            }
            nodo = nodo->sig;
        }
        if(nodo->dato == value)
        {
            return nodo;
        }
        return nullptr;
    }


};

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble(const ListaCircularDoble & cdll)
{
    if(cdll.head == nullptr)
    {
        head = tail = nullptr;
    }
    else
    {
        head = new NodoLCD(cdll.head->dato);
        NodoLCD *curr = head;
        NodoLCD *tmp = head;
        NodoLCD *obj_curr = cdll.head;

        while(obj_curr->sig != cdll.head)
        {
            curr->sig = new NodoLCD(obj_curr->sig->dato);
            obj_curr = obj_curr->sig;
            curr = curr->sig;
            curr->prev = tmp;
            tmp = tmp->sig;
        }
        tail = curr;
        curr->sig = head;
        head->prev = curr;
    }
}

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble(ListaCircularDoble&& cdll) noexcept
{
    head = tail = nullptr;
    unir(*this, cdll);
}

template <typename T>
void ListaCircularDoble<T>::insertarNodo(T value)
{
    NodoLCD *node = new NodoLCD(std::move(value));

    if(head == nullptr)
    {
        node->sig = node;
        node->prev = node;
        head = node;
        tail = node;
    }

    tail = head->prev;
    tail->sig = node;
    node->prev = tail;
    node->sig = head;
    head->prev = node;
    tail = node;
}

template <typename T>
void ListaCircularDoble<T>::borrarNodo(T value)
{
    NodoLCD *node = buscar(value);
    if(node == nullptr)
    {
        std::cerr << "No such value in the list\n";
        return;
    }
    else
    {
        NodoLCD *tmp = head;
        NodoLCD *tail = head->prev;
        if(tmp == node)
        {
            tail->sig = tmp->sig;
            tmp->prev->sig->prev = tail;
            head = tail->prev;
            delete tmp;
            return;
        }
        else if(tail == node)
        {
            NodoLCD *curr = tail;
            tmp = tail->prev;
            tmp->sig = curr->sig;
            head->prev = tmp;
            tail = tmp;
            delete curr;
            return;
        }
        else
        {
            while(tmp->sig != head)
            {
                if(tmp == node)
                {
                    tmp->prev->sig = tmp->sig;
                    tmp->prev->sig->prev = tmp->prev;
                    delete tmp;
                    return;
                }
                tmp = tmp->sig;
            }
        }
    }
}

template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble()
{
    if(head)
    {
        NodoLCD *tmp = head;
        while(tmp->sig != head)
        {
            NodoLCD *t = tmp;
            tmp = tmp->sig;
            delete t;
        }
        delete tmp;
        head = nullptr;
    }
}
