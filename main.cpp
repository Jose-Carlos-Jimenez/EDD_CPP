#include <iostream>
#include "arbol.h"

using namespace std;

int main()
{
    Arbol  *nuevo = new Arbol();
    nuevo->insertar(nuevo->raiz, "Heidy");
    nuevo->insertar(nuevo->raiz, "Carlos");
    nuevo->insertar(nuevo->raiz, "Antonio");
    nuevo->insertar(nuevo->raiz, "Rodrigo");
    nuevo->insertar(nuevo->raiz, "Eduardo");
    nuevo->preOrder(nuevo->raiz);
    cout<<"-----------------------" << endl;
    nuevo->inOrder(nuevo->raiz);
    cout <<"----------------------" << endl;
    nuevo->posOrder(nuevo->raiz);
    return 0;
}
