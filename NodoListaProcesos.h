#ifndef NODOLISTAPROCESOS_H
#define NODOLISTAPROCESOS_H
#include "Proceso.h"
#include <iostream>

class NodoListaProcesos
{
private:
    Proceso valor;
    NodoListaProcesos *siguiente;
    friend class ListaProcesos;

public:
    NodoListaProcesos(Proceso valor, NodoListaProcesos *sig = NULL);
    NodoListaProcesos();
    ~NodoListaProcesos();
};
typedef NodoListaProcesos *lnodop;

#endif // NodoListaProcesos_H