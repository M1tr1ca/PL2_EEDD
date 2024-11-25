#include "ABBProcesos.h"
#include "ListaProcesos.h"

#include <iostream>
using namespace std;

ABBProcesos::ABBProcesos()
{
    prioridad = 0;
    izquierda = nullptr;
    derecha = nullptr;
}

ABBProcesos::~ABBProcesos()
{
    delete izquierda;
    delete derecha;
}

bool ABBProcesos::esVacio()
{
    return procesos.esVacia();
}

ABBProcesos *ABBProcesos::izq()
{
    return izquierda;
}

ABBProcesos *ABBProcesos::der()
{
    return derecha;
}

ListaProcesos ABBProcesos::getRaiz()
{
    return procesos;
}

int ABBProcesos::getPrioridad()
{
    return prioridad;
}

int ABBProcesos::getAltura()
{
    if (esVacio() && izquierda == nullptr && derecha == nullptr)
    {
        return 0;
    }

    int alturaIzq = izquierda->getAltura();
    int alturaDer = derecha->getAltura();

    return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
}