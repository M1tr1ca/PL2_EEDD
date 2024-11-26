#ifndef LISTANUCLEOS_H
#define LISTANUCLEOS_H
#include "NodoListaNucleos.h"
#include "Proceso.h"
#include "Nucleo.h"
#include "ListaProcesos.h"

class ListaNucleos
{
private:
    NodoListaNucleos *cima;
    int longitud;

public:
    ListaNucleos();
    ~ListaNucleos();

    bool esVacia();
    void izquierda(Nucleo p);
    void izqProceso(Proceso *p);
    void derecha(Nucleo p);
    Nucleo prim();
    Nucleo ult();
    void resto();
    void eult();
    int nucleosLibres();
    int getLongitud();
    
    void mostrarTodo();
    ListaProcesos reducirTiempoVida();
    Nucleo *buscarMenosCola();
    Nucleo *buscarMasCola();
    void eliminarNucleosVacios();
};

#endif // PILA_H