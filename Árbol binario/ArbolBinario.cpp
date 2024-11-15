#include "ArbolBinario.h"
#include "NodoArbol.h"
#include "Proceso.h"

#include <iostream>
using namespace std;


ArbolBinario::ArbolBinario() 
{
    cima = NULL;
    altura = 0;

}

ArbolBinario::~ArbolBinario() 
{
    eliminarNodos(cima);
    cima = nullptr; 
}

void ArbolBinario::eliminarNodos(NodoArbol* cima) 
{
    if (cima != nullptr) 
    {
        eliminarNodos(cima->izquierda);
        eliminarNodos(cima->derecha);

        delete cima;
    }
}


bool ArbolBinario::esVacio() {
    return cima == nullptr;
}

NodoArbol* ArbolBinario::izq() {
    if (cima == nullptr) {
        throw runtime_error("No hay hoja en la parte izquierda.");
    }
    return cima->izquierda;
}


NodoArbol* ArbolBinario::der() {
    if (cima == nullptr) {
        throw runtime_error("No hay hoja en la parte derecha.");
    }
    return cima->derecha;
}


Proceso ArbolBinario::raiz() {
    if (cima == nullptr) {
        throw runtime_error("El árbol está vacío, no hay raíz.");
    }
    return cima->valor;
}


int ArbolBinario::getAltura() {
    altura=getProfundidad(cima);
    return altura;
}

void ArbolBinario::setAltura() {
    altura=getProfundidad(cima);
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
