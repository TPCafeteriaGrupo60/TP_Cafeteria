#include <iostream>
#include "App.h"

using namespace std;

/*
App::App(const char* nombreArchivo)
    : _VentaManager(nombreArchivo), _cantidadOpciones(7) {}

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
    cout<< "------------------------" <<endl;
    cout<<"Elegir Opcion: ";
}

int App::seleccionOpcion() {
    int opcion;
    mostrarOpciones();
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (opcion < 0 || opcion > _cantidadOpciones) {
        cout << "Opcion incorrecta..." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    }
    return opcion;
}

void App::ejecutarOpcion(int opcion) {
    switch(opcion){
        case 1:
            system("cls");
            menuMozos.mostrarMenu();
            break;
        case 2:
            system("cls");
            stockMenu.mostrarMenu();
            break;
        case 3:
            system("cls");
            menuMesas.mostrarMenu();
            break;
        case 4:
            system("cls");
            ///archivoVenta.mostrarMenu();
            menuVentas.mostrarMenu();
            break;
        case 5:
            system("cls");
            menuClientes.mostrarMenu();
            break;
        case 6:
            system("cls");
            menuMenus.mostrarMenu();
            break;
        case 7:
            system("cls");
            menuTurnos.mostrar();
            break;
        default:
            cout << "Opcion invalida!" << endl;
    }
}
*/
