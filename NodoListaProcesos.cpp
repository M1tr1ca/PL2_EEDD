#include <iostream>
#include "NodoListaProcesos.h"

using namespace std;

NodoListaProcesos::NodoListaProcesos()
{
    siguiente = NULL;
}

NodoListaProcesos::NodoListaProcesos(Proceso p, NodoListaProcesos *sig)
{
    valor = p;
    siguiente = sig;
}

NodoListaProcesos::~NodoListaProcesos()
{
    // Destructor
}