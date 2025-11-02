#include <iostream>
#include <cstdio>
#include "MozoManager.h"

using namespace std;

MozoManager::MozoManager(const char* nombreArchivo)
: archivo(nombreArchivo) { }

/// Agregar Mozo
bool MozoManager::agregarMozo() {
    cout << "--- Agregar nuevo Mozo ---\n";

    int id = archivo.contarMozos() + 1;

    Mozo m;
    m.Cargar();
    m.setIdMozo(id);

    if (archivo.guardarMozo(m)) {
        cout << "Mozo agregado con exito.\n";
        return true;
    } else {
        cout << "Error al agregar Mozo.\n";
        return false;
    }
}

/// Listar Mozo
void MozoManager::listarMozos() {
    cout << "\n--- Listado de Mozos ---\n";
    archivo.listarMozos();
}

/// Modificar Mozo
bool MozoManager::modificarMozoPorId() {
    int id;
    cout << "Ingrese ID del mozo a modificar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontró un mozo con ese ID.\n";
        return false;
    }

    cout << "\n--- Modificar Mozo ---\n";
    Mozo m;
    m.Cargar();

    if (archivo.modificarMozo(id, m)) {
        cout << "Mozo modificado con éxito.\n";
        return true;
    } else {
        cout << "Error al modificar mozo.\n";
        return false;
    }
}

/// Eliminar Mozo
bool MozoManager::eliminarMozoPorId() {
    int id;
    cout << "Ingrese ID a eliminar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un Mozo con ese ID.\n";
        return false;
    }

    if (archivo.eliminarMozo(id)) {
        cout << "Mozo eliminado con exito.\n";
        return true;
    } else {
        cout << "Error al eliminar Mozo.\n";
        return false;
    }
}


/*
Mozo ArchivoMozo::cargarDatosMozo(int idExistente) {
    char nombre[30], apellido[30];
    int  idTurno;

    cout << "Ingrese El Nombre: ";
    cin.ignore();
    cin.getline(nombre, 30);
    cout << "Ingrese El Apellido: ";
    cin.getline(apellido, 30);
    cout << "Ingrese El ID del Turno (1=Mediodía, 2=Noche): ";
    cin >> idTurno;

    Mozo mozo(idExistente, nombre, apellido, idTurno);
    return mozo;
}

 void ArchivoMozo::editarMozo() {
    listarMozos();
    int idModificar;
    cout<<endl;
    cout << "Ingrese el ID del mozo a modificar: ";
    cin >> idModificar;

    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    Mozo mozo;
    int pos = 0;
    bool encontrado = false;

    while (fread(&mozo, sizeof(Mozo), 1, p) == 1) {
        if (mozo.getIdMozo() == idModificar) {
            cout << "Datos actuales del mozo" << endl;
            mozo.Mostrar();

            cout << "Ingrese los nuevos datos" << endl;
            Mozo mozoEditado = cargarDatosMozo(idModificar);

            fseek(p, pos * sizeof(Mozo), SEEK_SET);
            fwrite(&mozoEditado, sizeof(Mozo), 1, p);
            encontrado = true;
            cout << "Mozo modificado correctamente." << endl;
            break;
        }
        pos++;
    }

    if (!encontrado)
        cout << "No se encontro un mozo con ese ID." << endl;

    fclose(p);
}


void ArchivoMozo::agregarMozo() {
    int id = contarMozos() + 1;
    cout << "ID del Nuevo Mozo: " << id << endl;

    Mozo nuevoMozo = cargarDatosMozo(id);

    if (guardarMozo(nuevoMozo))
        cout << "Se agrego nuevo mozo correctamente" << endl;
    else
        cout << "Error al agregar mozo." << endl;

}

*/

