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

int ABBProcesos::getLongitud()
{
    return listaProcesos.getLongitud();
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
    }
}

void ABBProcesos::mostrarMediaPreorden()
{
    if (!esVacio())
    {
        cout << "Media de procesos de prioridad " << getPrioridad() << ": " << listaProcesos.calcMedia() << endl;
    }
    if (izquierda != nullptr)
    {
        izquierda->mostrarMediaPreorden();
    }
    if (derecha != nullptr)
    {
        derecha->mostrarMediaPreorden();
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

void ABBProcesos::mostrarProcesosPorPrioridad(int prioridad)
{
    ABBProcesos *nodo = buscar(prioridad);
    if (nodo != nullptr)
    {
        nodo->listaProcesos.mostrarTodo();
    }
    else
    {
        cout << "No hay procesos con prioridad " << prioridad << endl;
    }
}

void ABBProcesos::mostrarNivelesInorden(ABBProcesos *nodo, int nivel)
{
    if (nodo != nullptr)
    {
        if (nodo->izq() != nullptr)
        {
            mostrarNivelesInorden(nodo->izq(), nivel + 1);
        }
        if (!nodo->esVacio())
        {
            cout << "Prioridad " << nodo->getPrioridad() << endl;
        }
        if (nodo->der() != nullptr)
        {
            mostrarNivelesInorden(nodo->der(), nivel + 1);
        }
    }
}

float ABBProcesos::calcMediaPrioridad(int prioridad)
{
    ABBProcesos *nodo = buscar(prioridad);
    if (nodo != nullptr)
    {
        return nodo->listaProcesos.calcMedia();
    }
    else
    {
        return 0;
    }
}

ABBProcesos *ABBProcesos::buscar(int prioridad)
{
    if (prioridad < this->prioridad)
    {
        if (izquierda != nullptr)
        {
            return izquierda->buscar(prioridad);
        }
    }
    else if (prioridad > this->prioridad)
    {
        if (derecha != nullptr)
        {
            return derecha->buscar(prioridad);
        }
    }
    else
    {
        if (!esVacio())
        {
            return this;
        }
        else
        {
            return nullptr;
        }
    }
    return nullptr;
}

ABBProcesos *ABBProcesos::maxProcesos()
{
    ABBProcesos *nodo = this;
    if (derecha != nullptr)
    {
        ABBProcesos *der = derecha->maxProcesos();
        if (nodo->esVacio() || nodo->getLongitud() < der->getLongitud())
        {
            nodo = der;
        }
    }
    if (izquierda != nullptr)
    {
        ABBProcesos *izq = izquierda->maxProcesos();
        if (nodo->esVacio() || nodo->getLongitud() < izq->getLongitud())
        {
            nodo = izq;
        }
    }
    return nodo;
}

ABBProcesos *ABBProcesos::minProcesos()
{
    ABBProcesos *nodo = this;
    if (derecha != nullptr)
    {
        ABBProcesos *der = derecha->minProcesos();
        if (nodo->esVacio() || nodo->getLongitud() > der->getLongitud())
        {
            nodo = der;
        }
    }
    if (izquierda != nullptr)
    {
        ABBProcesos *izq = izquierda->minProcesos();
        if (nodo->esVacio() || nodo->getLongitud() > izq->getLongitud())
        {
            nodo = izq;
        }
    }
    return nodo;

}

float ABBProcesos::calcMediaTotal()
{
    return this->tTotal() / this->numProcTotal();
}

int ABBProcesos::numProcTotal()
{
    int total = listaProcesos.getLongitud();

    if (izquierda != nullptr)
    {
        total += izquierda->numProcTotal();
    }

    if (derecha != nullptr)
    {
        total += derecha->numProcTotal();
    }

    return total;
}

float ABBProcesos::tTotal()
{
    float total = 0;

    total += listaProcesos.tTotal();

    if (izquierda != nullptr)
    {
        total += izquierda->tTotal();
    }

    if (derecha != nullptr)
    {
        total += derecha->tTotal();
    }

    return total;
}