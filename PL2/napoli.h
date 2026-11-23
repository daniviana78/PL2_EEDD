#ifndef NAPOLI_H_INCLUDED
#define NAPOLI_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#define N_CENTROS 10
#define N_VENTAS 30

using namespace std;

class Lista;
class ArbolABB;

struct CentroVenta
{
    int id_centro;
    string localidad;
    Lista *lista_ventas;

};

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Venta
{

    int id_centro;
    string id_venta;
    string cod_pizza;
    string categoria;
    int unidades;
    Fecha fecha_venta;

};

void generarCentros(ArbolABB &arb, int ids[]);
Venta generarVenta(int id_centro, int contador);
void mostrarCentro(CentroVenta &c);
void mostrarCentros(ArbolABB &a);
void mostrarVenta(Venta v);


#endif // NAPOLI_H_INCLUDED
