#ifndef LISTAPROCESOS_H
#define LISTAPROCESOS_H
#include "NodoListaProcesos.h"
#include "Proceso.h"
#include "Nucleo.h"

class ListaProcesos
{
private:
    NodoListaProcesos *cima;
    int longitud;

public:
    ListaProcesos();
    ~ListaProcesos();

    bool esVacia();
    void izquierda(Proceso p);
    void derecha(Proceso p);
    Proceso prim();
    Proceso ult();
    void resto();
    void eult();
    int getLongitud();
    
    void mostrarTodo();
    float calcMedia();
};

#endif // LISTAPROCESOS_H