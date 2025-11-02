#include <iostream>
#include <cstdio>
#include "ClienteManager.h"

using namespace std;

ClienteManager::ClienteManager(const char* nombreArchivo)
: archivo(nombreArchivo) { }

/// Agregar Cliente
bool ClienteManager::agregarCliente() {
    cout << "--- Agregar nuevo Cliente ---\n";
    Cliente c;
    c.Cargar();

    if (archivo.guardarCliente(c)) {
        cout << "Cliente agregado con exito.\n";
        return true;
    } else {
        cout << "Error al agregar Cliente.\n";
        return false;
    }
}

/// Listar Cliente
void ClienteManager::listarClientes() {
    cout << "\n--- Listado de Clientes ---\n";
    archivo.listarClientes();
}

/// Modificar Cliente
bool ClienteManager::modificarClientePorId() {
    int id;
    cout << "Ingrese ID a modificar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un Cliente con ese ID.\n";
        return false;
    }

    cout << "\n--- Modificar Cliente ---\n";
    Cliente nuevoCliente;
    nuevoCliente.Cargar();

    if (archivo.modificarCliente(id, nuevoCliente)) {
        cout << "Cliente modificado con exito.\n";
        return true;
    } else {
        cout << "Error al modificar Cliente.\n";
        return false;
    }
}

/// Eliminar Cliente
bool ClienteManager::eliminarClientePorId() {
    int id;
    cout << "Ingrese ID a eliminar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un Cliente con ese ID.\n";
        return false;
    }

    if (archivo.eliminarCliente(id)) {
        cout << "Cliente eliminado con exito.\n";
        return true;
    } else {
        cout << "Error al eliminar Cliente.\n";
        return false;
    }
}

