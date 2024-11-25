#ifndef LISTA_H
#define LISTA_H
#include "NodoListaNucleos.h"
#include "Proceso.h"
#include "Nucleo.h"

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
    void derecha(Nucleo p);
    Nucleo prim();
    Nucleo ult();
    void resto();
    void eult();
    int nucleosLibres();
    int getLongitud();
    
    void mostrarTodo();
    void reducirTiempoVida();
    Nucleo *buscarMenosCola();
    Nucleo *buscarMasCola();
    void eliminarNucleosVacios();
};

#endif // PILA_H