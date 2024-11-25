#ifndef ABBPROCESOS_H
#define ABBPROCESOS_H
#include "ListaProcesos.h"

class ABBProcesos
{
private:
    int prioridad;
    ListaProcesos procesos;
    ABBProcesos *izquierda;
    ABBProcesos *derecha;

public:
    ABBProcesos();
    ~ABBProcesos();

    bool esVacio();
    ABBProcesos *izq();
    ABBProcesos *der();
    ListaProcesos getRaiz();
    int getPrioridad();
    int getAltura();
};

#endif // ABBPROCESOS_H