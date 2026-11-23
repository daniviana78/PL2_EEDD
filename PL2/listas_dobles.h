#ifndef LISTAS_DOBLES_H
#define LISTAS_DOBLES_H

#include <iostream>

#include "napoli.h"

const int ASCENDENTE=0;
const int DESCENDENTE=1;

class Nodo
{
    private:
        Venta valor;
        Nodo *siguiente;
        Nodo *anterior;
    friend class Lista;

    public:
        Nodo(Venta v, Nodo *sig = NULL, Nodo *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
};
typedef Nodo *pnodo;

class Lista
{
    private:
        pnodo cabeza, final, actual;

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
