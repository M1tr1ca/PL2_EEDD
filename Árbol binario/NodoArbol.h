#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <iostream>
#include "Proceso.h"

class NodoArbol
{
private:
    Proceso valor;
    NodoArbol * izquierda;
    NodoArbol * derecha;
    friend class ArbolBinario;

public:
    NodoArbol();
    NodoArbol(Proceso elemento, NodoArbol *izq = NULL, NodoArbol *der = NULL);
    ~NodoArbol();
};
typedef NodoArbol *anodo;

#endif // NODOCAARBOL_H