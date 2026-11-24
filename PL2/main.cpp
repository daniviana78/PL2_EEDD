#include <iostream>

#include <ctime>
#include <iomanip>

#include "napoli.h"
#include "arboles.h"
#include "listas_dobles.h"

using namespace std;

int main()
{
    srand(time(NULL));

    ArbolABB arbol;
    int ids[N_CENTROS];
    Venta ventas[N_VENTAS];
    int contador = 0;

    cout << "Creando el ABB con " << N_CENTROS << " centros:" << endl;
    generarCentros(arbol, ids);
    cout << "Arbol inicial:" << endl;
    mostrarCentros(arbol);

    cout << endl << "Ventas nuevas:" << endl;
    cout << "|" << setw(10) << "ID Centro" << "|" << setw(9) << "ID Venta" << "|"
         << setw(8) << "Pizza" << "|" << setw(12) << "Categoria" << "|"
         << setw(9) << "Unidades" << "|" << setw(11) << "Fecha" << "|" << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (int i= 0; i < N_VENTAS; i++)
    {
        Venta v= generarVenta(ids[rand() % N_CENTROS], contador);
        ventas[i] = v;
        contador++;
        mostrarVenta(ventas[i]);
    }

    cout << "Pulse Enter para distribuir las ventas";
    cin.get();

    for (int i = 0; i < N_VENTAS; i++)
    {
        CentroVenta *c = arbol.Buscar(ventas[i].id_centro);
        if (c != NULL)
            c->lista_ventas->insertarNodo(ventas[i], 'f');
    }

    cout << endl << "Ventas distribuidas. Estado del arbol:" << endl;
    mostrarCentros(arbol);

int opcion;
    do
    {
        cout << endl << "Menu del programa:" << endl;
        cout << "Opciones disponibles:" << endl;
        cout << "1- Insertar un centro." << endl;
        cout << "2- Borrar un centro." << endl;
        cout << "0- Salir del programa." << endl;
        cout << "Seleccione una opcion del menu: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                insertarCentro(arbol);
                break;
            case 2:
                borrarCentro(arbol);
                break;
            case 0:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;

}
