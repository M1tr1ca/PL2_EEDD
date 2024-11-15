#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "NodoArbol.h"
#include "Proceso.h"


class ArbolBinario
{
private:
    NodoArbol* cima;
    int altura;

public:
    ArbolBinario();
    ~ArbolBinario();

    bool esVacio();
    ArbolBinario izq();
    ArbolBinario der();
    Proceso raiz();
    int getAltura();
    void setAltura();
    int getProfundidad(NodoArbol* nodo);

    void eliminarNodos(NodoArbol* raiz);//No pertenece a la especificación
    void mostrarArbolPreorden(NodoArbol* nodo);//Puedes recorrerlo desde cualquier raiz
    void mostrarArbolPostorden(NodoArbol* nodo);//Puedes recorrerlo desde cualquier raiz
    void mostrarArbolInorden(NodoArbol* nodo);//Puedes recorrerlo desde cualquier raiz



};

#endif // ARBOLBINARIO_H