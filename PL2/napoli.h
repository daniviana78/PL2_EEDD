#ifndef NAPOLI_H_INCLUDED
#define NAPOLI_H_INCLUDED

#define N_CENTROS 10
#define N_VENTAS 30

using namespace std;

class Lista;

struct CentroVenta
{
    int id_centro;
    string localidad;
    Lista *lista_ventas;

};

struct Venta
{

    int id_centro;
    string id_venta;
    string cod_pizza;
    string categoria;
    int unidades;
    string fecha_venta;

};

#endif // NAPOLI_H_INCLUDED
