#ifndef NODOLISTANUCLEOS_H
#define NODOLISTANUCLEOS_H
#include "Nucleo.h"
#include <iostream>

class NodoListaNucleos
{
private:
    Nucleo valor;
    NodoListaNucleos *siguiente;
    friend class ListaNucleos;

public:
    NodoListaNucleos(Nucleo valor, NodoListaNucleos *sig = NULL);
    NodoListaNucleos();
    ~NodoListaNucleos();
};
typedef NodoListaNucleos *lnodo;

#endif // NODOLISTANUCLEOS_H