#include "ArbolBinario.h"
#include "NodoArbol.h"
#include "Proceso.h"

#include <iostream>
using namespace std;


ArbolBinario::ArbolBinario() 
{
    cima = NULL;
    longitud = 0;

}

ArbolBinario::~ArbolBinario() 
{
    eliminarNodos(cima);
    cima = nullptr; 
}

void ArbolBinario::eliminarNodos(NodoArbol* raiz) 
{
    if (raiz != nullptr) 
    {
        eliminarNodos(raiz->izquierda);
        eliminarNodos(raiz->derecha);

        delete raiz;
    }
}


bool ArbolBinario::esVacio() {
    return raiz == nullptr;
}

ArbolBinario ArbolBinario::izq() {
    ArbolBinario subArbol;
    if (cima != nullptr) {
        subArbol.cima = cima->izquierda;
    }
    return subArbol;
}


ArbolBinario ArbolBinario::der() {
    ArbolBinario subArbol;
    if (cima != nullptr) {
        subArbol.cima = cima->derecha;
    }
    return subArbol;
}


Proceso ArbolBinario::raiz() {
    if (cima == nullptr) {
        throw std::runtime_error("El árbol está vacío, no hay raíz.");
    }
    return cima->valor;
}


int ArbolBinario::getAltura() {
    return getProfundidad(cima);
}


int ArbolBinario::getProfundidad(NodoArbol* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    int alturaIzq = getProfundidad(nodo->izquierda);
    int alturaDer = getProfundidad(nodo->derecha);
    return 1 + max(alturaIzq, alturaDer);
}


void ArbolBinario::mostrarArbolPreorden(NodoArbol* nodo) {
    if (nodo == nullptr) {
        return;
    }
    nodo->valor.mostrarInformacion();
    mostrarArbolPreorden(nodo->izquierda);
    mostrarArbolPreorden(nodo->derecha);
}

void ArbolBinario::mostrarArbolPostorden(NodoArbol* nodo){
    if (nodo == nullptr) {
        return;
    }
    mostrarArbolPostorden(nodo->izquierda);
    mostrarArbolPostorden(nodo->derecha);
    nodo->valor.mostrarInformacion();
}

void ArbolBinario::mostrarArbolInorden(NodoArbol* nodo){
    if (nodo == nullptr) {
        return;
    }
    mostrarArbolInorden(nodo->izquierda);
    nodo->valor.mostrarInformacion();
    mostrarArbolInorden(nodo->derecha);
}   
