#ifndef LISTADOBLEMENTEENLAZADA_H
#define LISTADOBLEMENTEENLAZADA_H

#endif // LISTADOBLEMENTEENLAZADA_H
template <class T>
class NodeLD
{

public:
    /*Atributes*/
    T data;
    NodeLD<T> *next;
    NodeLD<T> *previous;
    int position;

    /*Constructor*/
    NodeLD(T data):next(0),previous(0){this->data = data;};

    /*Methods*/

};

template<class T>
class ListaDoblementeEnlazada
{

public:
    /*Atributes*/
    int lenght;
    NodeLD<T> *head;
    NodeLD<T> *tail;

    /*Constructor*/
    ListaDoblementeEnlazada();

    /*Methods*/
    bool isEmpty();
    void insertFirst(T);
    void insertLast(T);
    void insertAt(T,int);
    void deleteFirst();
    void deleteLast();
    T getNode(int);
};


/*Constructor*/
template <class T> ListaDoblementeEnlazada<T>::ListaDoblementeEnlazada()
{
    lenght = 0;
}

/*Verify if list is empty*/
template <class T> bool ListaDoblementeEnlazada<T>::isEmpty()
{
    return this->lenght==0;
}

/*Insert on head of the list*/
template <class T> void ListaDoblementeEnlazada<T>::insertFirst(T value)
{
    NodeLD<T> *newData = new NodeLD<T>(value);
    if(this->isEmpty())
    {
        tail = newData;
        head = newData;
        tail->previous = 0;
        head->next = 0;
    }
    else
    {
        newData->previous = head;
        head->next = newData;
        head = newData;
    }
    lenght++;
}

/*Insert at tail the new node*/
template <class T> void ListaDoblementeEnlazada<T>::insertLast(T value)
{
    NodeLD<T> *newData = new NodeLD<T>(value);
    if(isEmpty())
    {
        head = newData;
    }
    else
    {
        tail->previous = newData;
        newData->next = tail;
    }
    tail = newData;
    lenght++;
    newData->position = lenght;
}

/*Delete a node at the first position*/
template <class T> void ListaDoblementeEnlazada<T>::deleteFirst()
{
    if(!isEmpty())
    {
        NodeLD<T> *tmp = this->head;
        if(head == tail)
        {
            tail = 0;
        }
        else
        {
            head->next->previous = 0;
        }
        head = head->next;
        tmp->next = 0;
        lenght--;
        delete tmp;
    }
}

/*Delete a node at the last position*/
template <class T> void ListaDoblementeEnlazada<T>::deleteLast()
{
    if(!isEmpty())
    {
        NodeLD<T> *tmp = tail;
        if(tail == head)
        {
            head = 0;
        }
        else
        {
            tail->previous->next = 0;
        }
        tail = tail->previous;
        tmp->previous = 0;
        lenght--;
        delete tmp;
    }
}

/*Get a node at n position*/
template <class T> T ListaDoblementeEnlazada<T>::getNode(int n)
{
    if(!isEmpty())
    {
        NodeLD<T> *temp = head;
        for(int i = 0 ; i< n ; i++)
        {
            temp = temp->next;
        }
        return  temp->data;
    }
    return 0;
}

/*Insert a node at n position*/
template <class T> void ListaDoblementeEnlazada<T>::insertAt(T value,int n)
{
    NodeLD<T> *newData = new NodeLD<T>(value);
    NodeLD<T> *aux = getNode(n);
    newData->previous = aux;
    newData->next = aux;
    if(aux->previous == 0)
    {
        head = newData;
    }
    else
    {
        aux->previous->next = newData;
    }
    aux->previous = newData;

}
