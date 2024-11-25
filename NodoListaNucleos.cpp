#include <iostream>
#include "NodoListaNucleos.h"

using namespace std;

NodoListaNucleos::NodoListaNucleos()
{
    // valor = Nucleo();
    siguiente = NULL;
}

NodoListaNucleos::NodoListaNucleos(Nucleo p, NodoListaNucleos *sig)
{
    valor = p;
    siguiente = sig;
}

NodoListaNucleos::~NodoListaNucleos()
{
    // Destructor
}