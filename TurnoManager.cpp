#include <iostream>
#include <cstdio>
#include "TurnoManager.h"

using namespace std;

TurnoManager::TurnoManager(const char* nombreArchivo)
: archivo(nombreArchivo) { }

/// Agregar Turno
bool TurnoManager::agregarTurno() {
    cout << "--- Agregar nuevo turno ---\n";
    Turno t;
    t.Cargar();

    if (archivo.guardarTurno(t)) {
        cout << "Turno agregado con exito.\n";
        return true;
    } else {
        cout << "Error al agregar turno.\n";
        return false;
    }
}

/// Listar Turno
void TurnoManager::listarTurnos() {
    cout << "\n--- Listado de turnos ---\n";
    archivo.listarTurnos();
}

/// Modificar Turno
bool TurnoManager::modificarTurnoPorId() {
    int id;
    cout << "Ingrese ID a modificar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un turno con ese ID.\n";
        return false;
    }

    cout << "\n--- Modificar turno ---\n";
    Turno nuevoTurno;
    nuevoTurno.Cargar();

    if (archivo.modificarTurno(pos, nuevoTurno)) {
        cout << "Turno modificado con exito.\n";
        return true;
    } else {
        cout << "Error al modificar turno.\n";
        return false;
    }
}

/// Eliminar turno
bool TurnoManager::eliminarTurnoPorId() {
    int id;
    cout << "Ingrese ID a eliminar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un turno con ese ID.\n";
        return false;
    }

    if (archivo.eliminarTurno(id)) {
        cout << "Turno eliminado con exito.\n";
        return true;
    } else {
        cout << "Error al eliminar turno.\n";
        return false;
    }
}

