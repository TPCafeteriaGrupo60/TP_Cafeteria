#include <iostream>
#include <cstdio>
#include "MesaManager.h"

using namespace std;

MesaManager::MesaManager(const char* nombreArchivo)
: archivo(nombreArchivo) { }

/// Agregar Mesa
bool MesaManager::agregarMesa() {
    cout << "--- Agregar nuevo Mesa ---\n";
    Mesa t;
    t.Cargar();

    if (archivo.guardarMesa(t)) {
        cout << "Mesa agregado con exito.\n";
        return true;
    } else {
        cout << "Error al agregar Mesa.\n";
        return false;
    }
}

/// Listar Mesa
void MesaManager::listarMesas() {
    cout << "\n--- Listado de Mesas ---\n";
    archivo.listarMesas();
}

/// Modificar Mesa
bool MesaManager::modificarMesaPorId() {
    int id;
    cout << "Ingrese ID a modificar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un Mesa con ese ID.\n";
        return false;
    }

    cout << "\n--- Modificar Mesa ---\n";
    Mesa nuevoMesa;
    nuevoMesa.Cargar();

    if (archivo.modificarMesa(id, nuevoMesa)) {
        cout << "Mesa modificado con exito.\n";
        return true;
    } else {
        cout << "Error al modificar Mesa.\n";
        return false;
    }
}

/// Eliminar Mesa
bool MesaManager::eliminarMesaPorId() {
    int id;
    cout << "Ingrese ID a eliminar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un Mesa con ese ID.\n";
        return false;
    }

    if (archivo.eliminarMesa(id)) {
        cout << "Mesa eliminado con exito.\n";
        return true;
    } else {
        cout << "Error al eliminar Mesa.\n";
        return false;
    }
}

