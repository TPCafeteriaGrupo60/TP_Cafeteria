#include <iostream>
#include <cstdio>
#include "ArchivoTurno.h"
using namespace std;

bool ArchivoTurno::guardarTurno(const Turno& reg) {
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return ok;
}

Turno ArchivoTurno::leerTurno(int pos) {
    Turno reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Turno), SEEK_SET);
    fread(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return reg;
}
int ArchivoTurno::buscarPosPorId(int id) {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return -1;

    Turno reg;
    int pos = 0;
    while (fread(&reg, sizeof(Turno), 1, p) == 1) {
        if (reg.getIdTurno() == id) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

int ArchivoTurno::contarTurnos() {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Turno);
}

Turno ArchivoTurno::buscarTurnoPorId(int id) {
    Turno reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return reg;

    while (fread(&reg, sizeof(Turno), 1, p)) {
        if (reg.getIdTurno() == id) {
            fclose(p);
            return reg;
        }
    }
    fclose(p);
    return Turno(); // devuelve uno vacío si no lo encuentra
}

bool ArchivoTurno::modificarTurno(int pos, const Turno& reg) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Turno), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return ok;
}

bool ArchivoTurno::eliminarTurno(int id) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Turno reg;
    int pos = 0;
    while (fread(&reg, sizeof(Turno), 1, p) == 1) {
        if (reg.getIdTurno() == id) {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Turno), SEEK_SET);
            fwrite(&reg, sizeof(Turno), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

void ArchivoTurno::listarTurnos() {
    int cant = contarTurnos();
    for (int i = 0; i < cant; i++) {
        Turno reg = leerTurno(i);
        if (!reg.getEliminado()) {
            reg.Mostrar();
            cout << "---------------------" << endl;
        }
    }
}

void ArchivoTurno::MenuTurnos() {
    ArchivoTurno archivo("Turnos.dat");
    int opcion;

    do {
        cout << "--- MENU TURNOS ---" << endl;
        cout << "1 - Agregar turno" << endl;
        cout << "2 - Listar turnos" << endl;
        cout << "3 - Modificar turno" << endl;
        cout << "4 - Eliminar turno" << endl;
        cout << "5 - Salir" << endl;
        cout << "-------------------" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            Turno t;
            cout << "Ingrese los datos del turno:" << endl;
            t.Cargar();
            if (archivo.guardarTurno(t))
                cout << "Turno agregado con exito." << endl;
            else
                cout << "Error al guardar el turno." << endl;
            break;
        }
        case 2:
            cout << "Lista de turnos:" << endl;
            archivo.listarTurnos();
            break;
        case 3: {
            int idModificar;
            cout << "Ingrese el ID del turno a modificar: ";
            cin >> idModificar;

            int pos = archivo.buscarPosPorId(idModificar);

            if (pos == -1) {
                cout << "No se encontro turno con ese ID." << endl;
                break;
            }

            Turno modificado;
            cout << "Ingrese los nuevos datos del turno:" << endl;
            modificado.Cargar();

            if (archivo.modificarTurno(pos, modificado))
                cout << "Turno modificado con exito." << endl;
            else
                cout << "Error al modificar el turno." << endl;
            break;
        }
        case 4: {
            int idEliminar;
            cout << "Ingrese el ID del turno a eliminar: ";
            cin >> idEliminar;

            if (archivo.eliminarTurno(idEliminar))
                cout << "Turno eliminado con exito." << endl;
            else
                cout << "No se encontro el turno con ese ID." << endl;
            break;
        }
        case 5:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }

        system("pause");
        system("cls");

    } while (opcion != 5);
}
