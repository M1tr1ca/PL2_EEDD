#include <iostream>
#include "ListaProcesos.h"
#include "NodoListaProcesos.h"
#include "Proceso.h"

using namespace std;

ListaProcesos::ListaProcesos()
{
    cima = NULL;
    longitud = 0;
}

ListaProcesos::~ListaProcesos()
{
    while (cima)
    {
        lnodop temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

bool ListaProcesos::esVacia()
{
    return cima == NULL;
}

void ListaProcesos::izquierda(Proceso p)
{
    lnodop nuevo = new NodoListaProcesos(p, cima);
    cima = nuevo;
    longitud++;
}

void ListaProcesos::derecha(Proceso p)
{
    lnodop nuevo = new NodoListaProcesos(p, NULL);

    if (esVacia())
    {
        cima = nuevo;
    }
    else
    {
        lnodop actual = cima;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    longitud++;
}

Proceso ListaProcesos::prim()
{
    if (esVacia())
    {
        throw runtime_error("La lista de procesos está vacía");
    }

    return cima->valor;
}

Proceso ListaProcesos::ult()
{
    if (esVacia())
    {
        throw runtime_error("La lista de procesos está vacía");
    }

    lnodop actual = cima;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }

    return actual->valor;
}

void ListaProcesos::resto()
{
    if (esVacia())
    {
        throw runtime_error("La lista de procesos está vacía");
    }

    lnodop temp = cima;
    cima = cima->siguiente;
    delete temp;
    longitud--;
}

void ListaProcesos::mostrarTodo()
{
    if (!esVacia())
    {
        lnodop actual = cima;
        while (actual != NULL)
        {
            cout << "---------------------------------" << endl;
            actual->valor.mostrarInformacion();
            actual = actual->siguiente;
        }
        cout << "---------------------------------" << endl;
        cout << endl;
    }
    else
    {
        cout << "La lista de procesos está vacía" << endl;
    }
}

void ListaProcesos::eult()
{
    if (esVacia())
    {
        throw runtime_error("La lista de procesos está vacía");
    }

    Proceso valor;

    if (cima->siguiente == NULL)
    {
        valor = cima->valor;
        delete cima;
        cima = NULL;
    }
    else
    {
        lnodop actual = cima;
        while (actual->siguiente->siguiente != NULL)
        {
            actual = actual->siguiente;
        }

        delete actual->siguiente;
        actual->siguiente = NULL;
    }

    longitud--;
}

int ListaProcesos::getLongitud()
{
    return longitud;
}

float ListaProcesos::calcMedia()
{
    float suma = 0;
    float contador = 0;

    if (!esVacia())
    {
        lnodop actual = cima;
        while (actual != NULL)
        {
            suma += actual->valor.getTiempoEjecucion();
            contador++;
            actual = actual->siguiente;
        }
        return suma / contador;
    }

    return 0;
}