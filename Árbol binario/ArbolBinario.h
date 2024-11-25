#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "NodoArbol.h"
#include "ListaNucleos.h"


class ArbolBinario
{
private:

    //ArbolBinario * raiz;

    int prioridad;
    ListaProcesos valor;
    ArbolBinario * izquierda;
    ArbolBinario * derecha;

public:
    ArbolBinario();
    ArbolBinario(Proceso elemento, ArbolBinario *izq = NULL, ArbolBinario *der = NULL,int altura=0,ArbolBinario *raiz = NULL);
    ~ArbolBinario();

    bool esVacio();
    ArbolBinario* izq();
    ArbolBinario* der();
    Proceso getRaiz();
    int getAltura();

    void eliminarNodos(ArbolBinario* raiz);//No pertenece a la especificación
    void mostrarArbolPreorden(ArbolBinario* nodo);//Puedes recorrerlo desde cualquier raiz
    void mostrarArbolPostorden(ArbolBinario* nodo);//Puedes recorrerlo desde cualquier raiz
    void mostrarArbolInorden(ArbolBinario* nodo);//Puedes recorrerlo desde cualquier raiz



};
typedef NodoArbol *anodo;
#endif 