#include "ArchivoMesa.h"
#include <iostream>
#include <cstdio>
// o stdlib.h

using namespace std;

bool ArchivoMesa::guardarMesa(const Mesa& reg) {
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Mesa), 1, p);
    fclose(p);
    return ok;
}

int ArchivoMesa::contarMesas() {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Mesa);
}

Mesa ArchivoMesa::leerMesa(int pos) {
    Mesa reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Mesa), SEEK_SET);
    fread(&reg, sizeof(Mesa), 1, p);
    fclose(p);
    return reg;
}

void ArchivoMesa::listarMesas() {
    int cant = contarMesas();
    for (int i = 0; i < cant; i++) {
        Mesa reg = leerMesa(i);
        if (!reg.getEliminado()) reg.Mostrar();
        cout << "---------------------" << endl;
    }
}

bool ArchivoMesa::eliminarMesa(int id) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Mesa reg;
    int pos = 0;
    while (fread(&reg, sizeof(Mesa), 1, p) == 1) {
        if (reg.getIdMesa() == id) {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Mesa), SEEK_SET);
            fwrite(&reg, sizeof(Mesa), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

bool ArchivoMesa::modificarMesa(int id, const Mesa& modificado) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Mesa reg;
    int pos = 0;
    while (fread(&reg, sizeof(Mesa), 1, p) == 1) {
        if (reg.getIdMesa() == id) {
            fseek(p, pos * sizeof(Mesa), SEEK_SET);
            fwrite(&modificado, sizeof(Mesa), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

void ArchivoMesa::MenuMesas() {
    ArchivoMesa archivo("Mesas.dat");
    int opcion;

    do {
        cout << "--- Menu Mesas ---" << endl;
        cout << "1- Agregar mesa" << endl;
        cout << "2- Listar mesas" << endl;
        cout << "3- Modificar mesa" << endl;
        cout << "4- Eliminar mesa" << endl;
        cout << "5- Salir" << endl;
        cout << "------------------"<<endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            Mesa m;
            cout << "Ingrese datos de la mesa:" << endl;
            m.Cargar();
            if (archivo.guardarMesa(m))
                cout << "Mesa agregada con exito." << endl;
            else
                cout << "Error al guardar la mesa." << endl;
            break;
        }
        case 2:
            cout << "Lista de mesas:" << endl;
            archivo.listarMesas();
            break;
        case 3: {
            int idModificar;
            cout << "Ingrese el ID de la mesa a modificar: ";
            cin >> idModificar;

            Mesa modificado;
            cout << "Ingrese los nuevos datos:" << endl;
            modificado.Cargar();

            if (archivo.modificarMesa(idModificar, modificado))
                cout << "Mesa modificada con exito." << endl;
            else
                cout << "No se encontro la mesa con ese ID." << endl;
            break;
        }
        case 4: {
            int idEliminar;
            cout << "Ingrese el ID de la mesa a eliminar: ";
            cin >> idEliminar;

            if (archivo.eliminarMesa(idEliminar))
                cout << "Mesa eliminada con exito." << endl;
            else
                cout << "No se encontro la mesa con ese ID." << endl;
            break;
        }
        case 5:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida, intente nuevamente." << endl;
        }
    } while (opcion != 5);
}
