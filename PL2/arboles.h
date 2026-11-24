#ifndef ARBOLES_H
#define ARBOLES_H

#include <iostream>

#include "napoli.h"


class NodoArbol
{
    private:
        // Miembros:
        CentroVenta dato;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
        friend class ArbolABB;

    public:
        // Constructor:
        NodoArbol(const CentroVenta dat, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
            dato(dat), izquierdo(izq), derecho(der) {}

};

class ArbolABB
{
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        NodoArbol *raiz;
        NodoArbol *actual;
        int contador;
        int altura;

    public:
        // Constructor y destructor básicos:
        ArbolABB() : raiz(NULL), actual(NULL) {}
        ~ArbolABB();
         // Insertar en árbol ordenado:
        void Insertar(const CentroVenta dat);
        // Borrar un elemento del árbol:
        void Borrar(const int dat);
        // Función de búsqueda:
        CentroVenta* Buscar(const int dat);
        // Comprobar si el árbol está vacío:
        bool Vacio(NodoArbol *r);
        // Comprobar si es un nodo hoja:
        bool EsHoja(NodoArbol *r);
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un CentroVenta:
        int Altura(const int dat);
        // Moverse al nodo raiz:
        void Raiz();
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(CentroVenta&), NodoArbol *nodo=NULL, bool r=true);
        void PreOrden(void (*func)(CentroVenta&), NodoArbol *nodo=NULL, bool r=true);
        void PostOrden(void (*func)(CentroVenta&), NodoArbol *nodo=NULL, bool r=true);

    private:
        // Funciones auxiliares
        void Podar(NodoArbol* &);
        void auxContador(NodoArbol*);
        void auxAltura(NodoArbol*, int);
};

#endif

