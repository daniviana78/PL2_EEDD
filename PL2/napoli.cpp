#include <iostream>

#include "napoli.h"
#include "listas_dobles.h"
#include "arboles.h"

using namespace std;

void generarCentros(ArbolABB &arb, int ids[])
{

    string localidades[]= {"Mostoles", "Alcala de Henares", "Leganes", "Fuenlabrada", "Getafe", "Alcorcon", "Torrejon de Ardoz", "Parla", "Alcobendas", "Coslada", "Pozuelo", "Rivas", "Valdemoro", "Majadahonda", "Aranjuez", "Arganda", "Boadilla", "Pinto", "Colmenar", "Tres Cantos"};
    int n_localidades= 20;

    for (int i= 0; i<N_CENTROS; i++)
    {
        CentroVenta c;

        c.id_centro = 100 + (rand() % 900);
        while (arb.Buscar(c.id_centro))
        {
            c.id_centro = 100 + rand() % 900;
        }

        int pos_localidad= rand() % n_localidades;
        c.localidad = localidades[pos_localidad];

        localidades[pos_localidad]= localidades[n_localidades-1];
        n_localidades--;

        c.lista_ventas = new Lista();

        arb.Insertar(c);
        ids[i] = c.id_centro;
    }

}

Venta generarVenta(int id_centro, int contador){

    string codigos[] = {"NP01", "NP02", "NP03", "NP04", "NP05", "NP06", "NP07", "NP08"};
    string categorias[] = {"Tradicional", "Tradicional", "Carne", "Carne", "Verduras", "Verduras", "Quesos", "Quesos"};
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Venta v;

    v.id_centro = id_centro;
    v.id_venta = "V" + to_string(10000 + contador);

    int p = rand() % 8;
    v.cod_pizza = codigos[p];
    v.categoria = categorias[p];

    v.unidades = 1+ (rand() % 20);

    v.fecha_venta.mes = 1 + (rand() % 12);
    v.fecha_venta.dia = 1 + (rand() % dias_mes[v.fecha_venta.mes - 1]);
    v.fecha_venta.anio = 2026;

    return v;
}

void mostrarCentro(CentroVenta &c)
{
    int n_ventas = 0;

    c.lista_ventas->esCabeza();
    while (c.lista_ventas->esActual())
    {
        n_ventas++;
        c.lista_ventas->esSiguiente();
    }

    cout << "ID: " << c.id_centro
         << " Localidad: " << setw(18) << c.localidad
         << " Num ventas: " << n_ventas << endl;
}


void mostrarVenta(Venta v)
{
    string fecha = "";
    if (v.fecha_venta.dia < 10)
    {
        fecha = fecha + "0";
    }
    fecha = fecha + to_string(v.fecha_venta.dia) + "-";
    if (v.fecha_venta.mes < 10)
    {
        fecha = fecha + "0";

    }
    fecha = fecha + to_string(v.fecha_venta.mes) + "-" + to_string(v.fecha_venta.anio);

    cout << "|" << setw(10) << v.id_centro << "|"
         << setw(9) << v.id_venta << "|"
         << setw(8) << v.cod_pizza << "|"
         << setw(12) << v.categoria << "|"
         << setw(9) << v.unidades << "|"
         << setw(11) << fecha << "|" << endl;
}

void insertarCentro(ArbolABB &arb)
{
    int id;
    cout << "Introduce el ID: ";
    cin >> id;

    if (arb.Buscar(id) != NULL)
    {
        cout << "Error: Ya existe un centro con ese id " << endl;
        return;
    }

    string localidad;
    cout << "Introduce la localidad del centro: ";
    cin >> localidad;

    CentroVenta nuevo;
    nuevo.id_centro = id;
    nuevo.localidad = localidad;
    arb.Insertar(nuevo);

}
void borrarCentro(ArbolABB &arb)
{
    int id;
    cout << "Introduce el ID del centro que quieres borrar: ";
    cin >> id;

    CentroVenta *c = arb.Buscar(id);
    if (c == NULL)
    {
        cout << "Error: No existe ningun centro con ese id" << endl;
        return;
    }

    while (!c->lista_ventas->listaVacia())
    {
        c->lista_ventas->borrarNodo('p');
    }
    delete c-> lista_ventas;

    arb.Borrar(id);
}
