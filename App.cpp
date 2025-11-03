#include <iostream>
#include "App.h"

using namespace std;

App::App() :
    menuClientes("Clientes.dat"),
    menuMenus("Menus.dat"),
    menuMesas("Mesas.dat"),
    menuMozos("Mozos.dat"),
    menuStock("stock.dat"),
    menuTurnos("Turnos.dat"),
    menuVentas("Ventas.dat")
{
    _cantidadOpciones = 7;
}

void App::run() {
    int opcion ;
    do {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
        system("pause");
    } while (opcion != 0);
}

void App::mostrarOpciones() {
    cout<< "---- Menu Principal ----" <<endl;
    cout<< "1. Mozos"<<endl;
    cout<< "2. Stock"<<endl;
    cout<< "3. Mesas"<<endl;
    cout<< "4. Ventas"<<endl;
    cout<< "5. Clientes"<<endl;
    cout<< "6. Menus a la Venta"<<endl;
    cout<< "7. Turnos de Atencion"<<endl;
    cout<< "0. Salir"<<endl;
}

int App::seleccionOpcion() {

    int opcion;
    mostrarOpciones();
    cout<< "------------------------" <<endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (opcion < 0 || opcion > _cantidadOpciones) {
        cout << "\nOpcion incorrecta...\n" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    }

    return opcion;
}

void App::ejecutarOpcion(int opcion) {

    switch (opcion) {
        case 1: menuMozos.mostrarMenu(); break;
        case 2: menuStock.mostrarMenu(); break;
        case 3: menuMesas.mostrarMenu(); break;
        case 4: menuVentas.mostrarMenu(); break;
        case 5: menuClientes.mostrarMenu(); break;
        case 6: menuMenus.mostrarMenu(); break;
        case 7: menuTurnos.mostrarMenu(); break;
        case 0: cout << "Saliendo del sistema...\n"; break;
        default: cout << "Opcion invalida. Intente nuevamente.\n"; break;
    }
}
