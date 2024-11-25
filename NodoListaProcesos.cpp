#include <iostream>
#include "NodoListaProcesos.h"

using namespace std;

NodoListaProcesos::NodoListaProcesos()
{
    // valor = Nucleo();
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