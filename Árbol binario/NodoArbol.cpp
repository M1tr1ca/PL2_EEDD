#include <iostream>
#include "NodoArbol.h"

using namespace std;

NodoArbol::NodoArbol()
{
    izquierda = NULL;
    derecha = NULL;
}

NodoArbol::NodoArbol(Proceso p, NodoArbol *izq, NodoArbol *der)
{
    valor = p;
    izquierda = izq;
    derecha = der;
}

NodoArbol::~NodoArbol()
{
    // Destructor
}