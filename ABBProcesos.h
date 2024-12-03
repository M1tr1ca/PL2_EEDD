#ifndef ABBPROCESOS_H
#define ABBPROCESOS_H
#include "ListaProcesos.h"

class ABBProcesos
{
private:
    int prioridad;
    ListaProcesos listaProcesos;
    ABBProcesos *izquierda;
    ABBProcesos *derecha;

public:
    ABBProcesos();
    ABBProcesos(int prioridad);
    ~ABBProcesos();

    bool esVacio();
    ABBProcesos *izq();
    ABBProcesos *der();
    ListaProcesos getProcesos();
    int getLongitud();
    int getPrioridad();
    int getAltura();

    void insertar(Proceso p);

    void mostrarMediaPreorden();
    void mostrarArbolInorden(ABBProcesos *nodo);
    void mostrarNivelesInorden(ABBProcesos *nodo, int nivel);
    void mostrarProcesosPorPrioridad(int prioridad);
    float calcMediaPrioridad(int prioridad);
    float calcMediaTotal();
    int numProcTotal();
    float tTotal();
    ABBProcesos *buscar(int prioridad);

    ABBProcesos *maxProcesos();
    ABBProcesos *minProcesos();
};

#endif // ABBPROCESOS_H