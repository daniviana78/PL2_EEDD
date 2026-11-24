#ifndef LISTAS_DOBLES_H
#define LISTAS_DOBLES_H

#include <iostream>

#include "napoli.h"

const int ASCENDENTE=0;
const int DESCENDENTE=1;

class NodoLista
{
    private:
        Venta valor;
        NodoLista *siguiente;
        NodoLista *anterior;
    friend class Lista;

    public:
        NodoLista(Venta v, NodoLista *sig = NULL, NodoLista *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
};
typedef NodoLista *pnodo_lista;

class Lista
{
    private:
        pnodo_lista cabeza, final, actual;

    public:
        Lista() {cabeza=actual=final=NULL; }
        ~Lista();
        void insertarNodo(Venta v, char c);
        void borrarNodo(char c);
        bool listaVacia();
        void esCabeza();
        void esFinal();
        void esSiguiente();
        void esAnterior();
        bool esActual();
        Venta valorActual();
        void recorrerLista(int);
};

#endif
