#include "ABBProcesos.h"
#include "ListaProcesos.h"

#include <iostream>
using namespace std;

ABBProcesos::ABBProcesos()
{
    prioridad = 4;
    izquierda = nullptr;
    derecha = nullptr;
}

ABBProcesos::ABBProcesos(int prioridad)
{
    this->prioridad = prioridad;
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
    return listaProcesos.esVacia();
}

ABBProcesos *ABBProcesos::izq()
{
    return izquierda;
}

ABBProcesos *ABBProcesos::der()
{
    return derecha;
}

ListaProcesos ABBProcesos::getProcesos()
{
    return listaProcesos;
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

void ABBProcesos::insertar(Proceso p)
{
    if (p.getPrioridad() < prioridad)
    {
        if (izquierda == nullptr)
        {
            izquierda = new ABBProcesos(p.getPrioridad());
        }
        izquierda->insertar(p);
    }
    else if (p.getPrioridad() > prioridad)
    {
        if (derecha == nullptr)
        {
            derecha = new ABBProcesos(p.getPrioridad());
        }
        derecha->insertar(p);
    }
    else
    {
        listaProcesos.izquierda(p);
        cout << "Proceso insertado correctamente" << p.getPID() << endl;
        listaProcesos.mostrarTodo();
    }
}

void ABBProcesos::mostrarArbolPreorden(ABBProcesos *nodo)
{
    if (nodo != nullptr)
    {
        if (nodo->esVacio())
        {
            cout << "Prioridad: " << nodo->getPrioridad() << endl;
            cout << "No hay procesos" << endl;
        }
        else
        {
            nodo->getProcesos().mostrarTodo();
        }
        mostrarArbolPreorden(nodo->izq());
        mostrarArbolPreorden(nodo->der());
    }
}

void ABBProcesos::mostrarArbolInorden(ABBProcesos *nodo)
{
    if (nodo != nullptr)
    {
        if (nodo->izq() != nullptr)
        {
            mostrarArbolInorden(nodo->izq());
        }
        if (!nodo->esVacio())
        {
            cout << "Prioridad: " << nodo->getPrioridad() << endl;
            nodo->listaProcesos.mostrarTodo();
        }
        if (nodo->der() != nullptr)
        {
            mostrarArbolInorden(nodo->der());
        }
    }
}

void ABBProcesos::mostrarArbolPostorden(ABBProcesos *nodo)
{
    if (nodo != nullptr)
    {
        mostrarArbolPostorden(nodo->izq());
        mostrarArbolPostorden(nodo->der());
        nodo->listaProcesos.mostrarTodo();
    }
}