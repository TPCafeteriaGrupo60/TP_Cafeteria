#include <iostream>
#include <cstdio>
#include "VentaManager.h"

using namespace std;

VentaManager::VentaManager(const char* nombreArchivo)
: archivo(nombreArchivo) { }

/// Agregar Venta
bool VentaManager::agregarVenta() {
    cout << "--- Agregar nueva Venta ---\n";

    int id = archivo.generarIdVenta();
    Venta v;
    v.setIdVenta(id);
    cout << "ID generado: " << id << endl;
    v.cargar();

    if (archivo.guardarVenta(v)) {
        cout << "Venta agregada con exito.\n";
        return true;
    } else {
        cout << "Error al agregar Venta.\n";
        return false;
    }
}

/// Listar Venta
void VentaManager::listarVentas() {
    cout << "\n--- Listado de Ventas ---\n";
    archivo.listarVentas();
}

/// Buscar Venta por ID
bool VentaManager::buscarVentaPorId() {
    int id;
    cout << "Ingrese ID a buscar: ";
    cin >> id;

    int pos = archivo.buscarVentaPorId(id);
    if (pos == -1) {
        cout << "No se encontro una Venta con ese ID.\n";
        return false;
    }

    Venta v;
    archivo.leerVenta(v, pos);
    v.mostrar();
    return true;
}

/// Modificar Venta
bool VentaManager::modificarVentaPorId() {
    int id;
    cout << "Ingrese ID a modificar: ";
    cin >> id;

    int pos = archivo.buscarVentaPorId(id);
    if (pos == -1) {
        cout << "No se encontro una Venta con ese ID.\n";
        return false;
    }

    cout << "\n--- Modificar Venta ---\n";
    Venta nuevaVenta;
    nuevaVenta.cargar();
    nuevaVenta.setIdVenta(id);

    if (archivo.modificarVenta(nuevaVenta, pos)) {
        cout << "Venta modificada con exito.\n";
        return true;
    } else {
        cout << "Error al modificar Venta.\n";
        return false;
    }
}

/// Eliminar Venta
bool VentaManager::eliminarVentaPorId() {
    int id;
    cout << "Ingrese ID a eliminar: ";
    cin >> id;

    int pos = archivo.buscarVentaPorId(id);
    if (pos == -1) {
        cout << "No se encontro una Venta con ese ID.\n";
        return false;
    }

    if (archivo.eliminarVenta(id)) {
        cout << "Venta eliminada con exito.\n";
        return true;
    } else {
        cout << "Error al eliminar Venta.\n";
        return false;
    }
}

/*
void VentaManager::menuVentas() {
    int opcion;
    do {
        system("cls");
        cout << "VENTAS" << endl;
        cout << "---" << endl;
        cout << "1 - AGREGAR VENTA" << endl;
        cout << "2 - MODIFICAR VENTA" << endl;
        cout << "3 - ELIMINAR VENTA" << endl;
        cout << "4 - LISTAR VENTAS" << endl;
        cout << "---" << endl;
        cout << "0 - VOLVER" << endl;
        cout << "---" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarVenta();
                system("pause");
                break;
            case 2:
                modificarVentaPorId();
                system("pause");
                break;
            case 3:
                eliminarVentaPorId();
                system("pause");
                break;
            case 4:
                listarVentas();
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
                system("pause");
                break;
        }
    } while (opcion != 0);
}
*/
