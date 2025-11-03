#include <iostream>
#include "VentaMenu.h"
#include "VentaManager.h"

using namespace std;

VentaMenu::VentaMenu(const char* nombreArchivo)
    : _VentaManager(nombreArchivo), _cantidadOpciones(5) {}

void VentaMenu::mostrarMenu() {
    int opcion;
    do {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
    } while (opcion != 0);
}

void VentaMenu::mostrarOpciones() {
    cout << "---- Menu Ventas ----" << endl;
    cout << "1. Cargar venta" << endl;
    cout << "2. Listar todas las ventas" << endl;
    cout << "3. Buscar venta por ID" << endl;
    cout << "4. Modificar venta" << endl;
    cout << "5. Eliminar venta" << endl;
    cout << "0. Volver" << endl;
}

int VentaMenu::seleccionOpcion() {

    int opcion;
    mostrarOpciones();
    cout << "------------------------" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (opcion < 0 || opcion > _cantidadOpciones) {
        cout << "\nOpcion incorrecta...\n" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    }
    return opcion;
}

void VentaMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            _VentaManager.agregarVenta();
            break;
        case 2:
            _VentaManager.listarVentas();
            break;
        case 3:
            _VentaManager.buscarVentaPorId();
            break;
        case 4:
            _VentaManager.modificarVentaPorId();
            break;
        case 5:
            _VentaManager.eliminarVentaPorId();
            break;
        case 0:
            cout << "\nVolviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
    }
}
