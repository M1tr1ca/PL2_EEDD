#include <iostream>
#include "ListaNucleos.h"
#include "NodoListaNucleos.h"
#include "Nucleo.h"

using namespace std;

ListaNucleos::ListaNucleos()
{
    cima = new NodoListaNucleos();
    longitud = 1;
}

ListaNucleos::~ListaNucleos()
{
    while (cima)
    {
        lnodo temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

bool ListaNucleos::esVacia()
{
    return cima == NULL;
}

void ListaNucleos::izquierda(Nucleo p)
{
    lnodo nuevo = new NodoListaNucleos(p, cima);
    cima = nuevo;
    longitud++;
}

void ListaNucleos::derecha(Nucleo p)
{
    lnodo nuevo = new NodoListaNucleos(p, NULL);

    if (esVacia())
    {
        cima = nuevo;
    }
    else
    {
        lnodo actual = cima;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    longitud++;
}

Nucleo ListaNucleos::prim()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    return cima->valor;
}

Nucleo ListaNucleos::ult()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }

    return actual->valor;
}

void ListaNucleos::resto()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo temp = cima;
    cima = cima->siguiente;
    delete temp;
    longitud--;
}

void ListaNucleos::mostrarTodo()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    while (actual != NULL)
    {
        cout << "---------------------------------" << endl;
        actual->valor.mostrarInformacion();
        actual = actual->siguiente;
    }
    cout << "---------------------------------" << endl;
    cout << endl;
}

void ListaNucleos::eult()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    Nucleo valor;

    if (cima->siguiente == NULL)
    {
        valor = cima->valor;
        delete cima;
        cima = NULL;
    }
    else
    {
        lnodo actual = cima;
        while (actual->siguiente->siguiente != NULL)
        {
            actual = actual->siguiente;
        }

        delete actual->siguiente;
        actual->siguiente = NULL;
    }

    longitud--;
}

void ListaNucleos::reducirTiempoVida()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    // Recorrer la lista y reducir el tiempo de vida de cada núcleo
    lnodo actual = cima;
    while (actual != NULL)
    {
        actual->valor.reducirTiempoVida();
        actual = actual->siguiente;
    }

    // Sacar procesos terminados de ejecutar y meter los de la cola de espera
    actual = cima;
    while (actual != NULL)
    {
        if (actual->valor.getPuntProcesoActual() != NULL && actual->valor.getPuntProcesoActual()->getTiempoVida() == 0)
        {
            actual->valor.terminarProcesoActual();
        }
        actual = actual->siguiente;
    }
}

Nucleo *ListaNucleos::buscarMenosCola()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    lnodo menor = cima;
    while (actual != NULL)
    {
        if (actual->valor.numeroProcesosTotales() < menor->valor.numeroProcesosTotales())
        {
            menor = actual;
        }
        actual = actual->siguiente;
    }

    return &menor->valor;
}

Nucleo *ListaNucleos::buscarMasCola()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    lnodo actual = cima;
    lnodo mayor = cima;
    while (actual != NULL)
    {
        if (actual->valor.numeroProcesosTotales() > mayor->valor.numeroProcesosTotales())
        {
            mayor = actual;
        }
        actual = actual->siguiente;
    }

    return &mayor->valor;
}

int ListaNucleos::nucleosLibres()
{
    if (esVacia())
    {
        throw runtime_error("La lista está vacía");
    }

    int libres = 0;
    lnodo actual = cima;
    while (actual != NULL)
    {
        if (!actual->valor.estaOcupado())
        {
            libres++;
        }
        actual = actual->siguiente;
    }

    return libres;
}

void ListaNucleos::eliminarNucleosVacios()
{
    lnodo actual = cima;
    while (!esVacia() && !actual->valor.estaOcupado())
    {
        cout << "Núcleo " << actual->valor.getId() << " eliminado" << endl;
        lnodo temp = actual;
        cima = actual->siguiente;
        actual = actual->siguiente;
        longitud--;
        delete temp;
    }

    if (esVacia())
    {
        cima = new NodoListaNucleos(Nucleo(), NULL);
    }
    else
    {
        actual = cima;
        while (actual->siguiente != NULL)
        {
            if (!actual->siguiente->valor.estaOcupado())
            {
                cout << "Núcleo " << actual->siguiente->valor.getId() << " eliminado" << endl;
                lnodo temp = actual->siguiente;
                actual->siguiente = actual->siguiente->siguiente;
                longitud--;
                delete temp;
            }
            else
            {
                actual = actual->siguiente;
            }
        }
    }
}

int ListaNucleos::getLongitud()
{
    return longitud;
}