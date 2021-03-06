#include <iostream>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include <iostream>

#include "ListaCircularDoble.h"
#include "arbol.h"
#include "cola.h"
#include "listadoblementeenlazada.h"
#include "listasimple.h"
#include "MatrizDispersa.h"
#include "ficha.h"

using namespace std;

void jsonExample(QString filename){
    QFile file;//Abro un archivo
    QString val;//Creo un valor
    file.setFileName(filename);//Le asigno la ruta
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject jsonObject = d.object();
    qDebug()<< "Dimension:";
    qDebug()<< jsonObject.value(QStringLiteral("dimension")).toInt();//Leer dimensión.

    QJsonObject casillas = jsonObject["casillas"].toObject();
    QJsonArray jsonArray3 = casillas["dobles"].toArray();
    QJsonArray jsonArray4 = casillas["triples"].toArray();//Leer las casillas

    foreach (const QJsonValue & value, jsonArray3) {
        QJsonObject obj = value.toObject();
        QJsonArray arrayEvento = obj["dobles"].toArray();//Leer cuales son dobles
        qDebug()<< "Coordenada doble x y ";
        qDebug()<< obj.value(QStringLiteral("x")).toInt();
        qDebug()<< obj.value(QStringLiteral("y")).toInt();
    }

    foreach (const QJsonValue & value, jsonArray4) {
        QJsonObject obj = value.toObject();
        QJsonArray arrayEvento = obj["triples"].toArray();//Leer cuales son triples
        qDebug()<< "Coordenada trple x y ";
        qDebug()<< obj.value(QStringLiteral("x")).toInt();
        qDebug()<< obj.value(QStringLiteral("y")).toInt();
    }

    QJsonArray jsonArray5 = jsonObject["diccionario"].toArray();//Leer las palabras en el diccionario
    qDebug()<< "DICCIONARIO";
    foreach (const QJsonValue & value, jsonArray5) {
        QJsonObject obj = value.toObject();//Lo vuelve un objeto
        QJsonObject palabra = obj["palabra"].toObject();//La palabra la vuelve un objeto
        qDebug()<< "Palabra de diccionario";
        qDebug() << obj.value(QStringLiteral("palabra")).toString();//Obtiene la palabra que está en el objeto
    }
}


int main()
{


    /*<<<<<<<<<<<<<<<<<<<<<< PRUEBA LISTA DOBLEMENTE ENLAZADA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

    /*ListaDoblementeEnlazada<ficha> *nueva = new ListaDoblementeEnlazada<ficha>();
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('A',2));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('B', 3));
    nueva->insertLast(*new ficha('D', 6));
    nueva->insertLast(*new ficha('C', 2));
    nueva->insertLast(*new ficha('D', 63));

    cout << nueva->getGraph() << endl;*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA ARBOL>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

    /*Arbol *nuevo = new Arbol();
    nuevo->insertar(nuevo->raiz, "Heidy");
    nuevo->insertar(nuevo->raiz, "Eduardo");
    nuevo->insertar(nuevo->raiz, "Antonio");
    nuevo->insertar(nuevo->raiz, "Rodrigo");
    nuevo->insertar(nuevo->raiz, "Carlos");

    //La gráfica del arbol depende de el orden en que esto sean insertados.
    nuevo->inOrder(nuevo->raiz);
    cout<<"-------------------------------" << endl;
    nuevo->preOrder(nuevo->raiz);
    cout<<"-------------------------------" << endl;
    nuevo->posOrder(nuevo->raiz);
    cout << "--------------------------------" << endl;
    cout << nuevo->graphInOrder(nuevo->raiz) << endl;
    cout << nuevo->graphPreOrder(nuevo->raiz) << endl;
    cout << nuevo->graphPosOrder(nuevo->raiz) << endl;
    cout << nuevo->graphTree(nuevo->raiz) << endl;*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA LISTA SIMPLE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

    /*ListaSimple<Jugador> *nueva = new ListaSimple<Jugador>();
    nueva->insertar(*new Jugador("Juan"));
    nueva->insertar(*new Jugador("Joseph"));
    nueva->insertar(*new Jugador ("Marvin"));
    nueva->insertar(*new Jugador ("Chris"));
    nueva->insertar(*new Jugador("Daniel"));
    cout << nueva->getGraph(' ') << endl;

    ListaSimple<int> *enteros = new ListaSimple<int>();
    enteros->insertar(1);
    enteros->insertar(2);
    enteros->insertar(3);
    enteros->insertar(4);
    enteros->insertar(5);
    enteros->insertar(6);
    cout << enteros->getGraph(2)<< endl;

    //NodoLS<int> *n = nueva->leerPrimero();
    //while (n != 0)
    //{
    //    cout << n->datoNodo() << endl;
    //    n = n->enlaceNodo();
    //}
    */

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA CON LA MATRIZ DISPERSA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

    //-----------------------Prueba de listas para los nodos ortogonales---------------------------------
    /*ListaVertical<ficha> *listaVertical = new ListaVertical<ficha>();

    ficha *n1 = new ficha('a', 1, 3);
    ficha *n2 = new ficha('b', 1, 3);
    ficha *n3 = new ficha('z', 1, 3);

    NodoOrtogonal<ficha> *p1 = new NodoOrtogonal<ficha>(*n1, 1 ,3);
    NodoOrtogonal<ficha> *p2 = new NodoOrtogonal<ficha>(*n2, 1, 2);
    NodoOrtogonal<ficha> *p3 = new NodoOrtogonal<ficha>(*n3, 1, 1);

    listaVertical->insertar(p1);
    listaVertical->insertar(p3);
    listaVertical->insertar(p2);

    listaVertical->recorrer();

    ListaHorizontal<ficha> *lista = new ListaHorizontal<ficha>();

    ficha *f1 = new ficha('a', 1, 3);
    ficha *f2 = new ficha('b', 1, 3);
    ficha *f3 = new ficha('z', 1, 3);

    NodoOrtogonal<ficha> *pd = new NodoOrtogonal<ficha>(*f1, 1 ,3);
    NodoOrtogonal<ficha> *pd2 = new NodoOrtogonal<ficha>(*f2, 3, 3);
    NodoOrtogonal<ficha> *pd3 = new NodoOrtogonal<ficha>(*f3, 4, 1);

    lista->insertar(pd);
    lista->insertar(pd2);
    lista->insertar(pd3);

    lista->recorrer();*/

    //-----------------------Prueba de listas de cabeceras------------------------------
    /*Cabeceras<ficha>* n = new Cabeceras<ficha>();
    n->insertar(new NodoCabecera<ficha>(3));
    n->insertar(new NodoCabecera<ficha>(2));
    n->insertar(new NodoCabecera<ficha>(45));
    n->insertar(new NodoCabecera<ficha>(1));
    n->insertar(new NodoCabecera<ficha>(33));
    n->recorrer();
    n->existe(45);
    n->existe(43);
    NodoCabecera<ficha> *aux = n->busqueda(2);
    if(aux->x == -1)
    {
        cout << "El nodo que estás intentando encontrar no existe" << endl;
    }
    else
    {
        cout << "La coordenada es " + to_string(aux->x) << endl;
    }

    cout << endl;
    Laterales<int> *lateral = new Laterales<int>();
    lateral->insertar(new NodoLateral<int>(3));
    lateral->insertar(new NodoLateral<int>(1));
    lateral->insertar(new NodoLateral<int>(2));
    lateral->insertar(new NodoLateral<int>(98));
    lateral->insertar(new NodoLateral<int>(1100));
    lateral->insertar(new NodoLateral<int>(123));
    lateral->insertar(new NodoLateral<int>(12));
    lateral->recorrer();*/

    //---------------------Prueba de matriz------------------------------------------------
    /*MatrizDispersa<char> *prueba = new MatrizDispersa<char>();
    prueba->insertar(1,1,'A');
    prueba->insertar(2,5,'B');
    prueba->insertar(1,3,'C');
    prueba->insertar(1,4,'D');
    prueba->insertar(1,5,'E');
    prueba->insertar(7,2,'F');
    prueba->insertar(2,1,'G');
    prueba->insertar(2,2,'H');
    prueba->insertar(7,4,'I');
    prueba->graphMatrix();*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA COLA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

    /*Cola<ficha> nuev = Cola<ficha>();
    nuev.insertar(*new ficha('D', 2));
    nuev.insertar(*new ficha('B', 3));
    nuev.insertar(*new ficha('P', 3));
    nuev.insertar(*new ficha('A', 1));
    nuev.insertar(*new ficha('H', 4));
    nuev.insertar(*new ficha('V', 4));
    nuev.insertar(*new ficha('V', 4));
    nuev.insertar(*new ficha('D', 2));
    nuev.insertar(*new ficha('B', 3));
    nuev.insertar(*new ficha('P', 3));
    nuev.insertar(*new ficha('A', 1));
    nuev.insertar(*new ficha('H', 4));
    nuev.insertar(*new ficha('V', 4));
    nuev.insertar(*new ficha('V', 4));
    nuev.insertar(*new ficha('D', 2));
    nuev.insertar(*new ficha('B', 3));
    nuev.insertar(*new ficha('P', 3));
    nuev.insertar(*new ficha('A', 1));
    nuev.insertar(*new ficha('H', 4));
    nuev.insertar(*new ficha('V', 4));
    nuev.insertar(*new ficha('V', 4));
    nuev.insertar(*new ficha('D', 2));
    nuev.insertar(*new ficha('B', 3));
    nuev.insertar(*new ficha('P', 3));
    nuev.insertar(*new ficha('A', 1));
    nuev.insertar(*new ficha('H', 4));
    nuev.insertar(*new ficha('V', 4));
    nuev.insertar(*new ficha('V', 4));
    cout << nuev.graph() << endl;*/

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<PRUEBA LISTA CIRCULAR DOBLEMENTE ENLAZADA>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

    /*ListaCircularDoble<string> listaCircularDoble;
    listaCircularDoble.insertarNodo("HOLA");
    listaCircularDoble.insertarNodo("MUNDO");
    listaCircularDoble.insertarNodo("PRUEBA");
    listaCircularDoble.insertarNodo("DICCIONARIO");
    listaCircularDoble.imprimirLista();
    cout << listaCircularDoble.graph() << endl;*/

    return  0;
}
