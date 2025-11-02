#include <iostream>
#include <cstdio>
#include "MenuManager.h"

using namespace std;

MenuManager::MenuManager(const char* nombreArchivo)
: archivo(nombreArchivo) { }

/// Agregar Menu
bool MenuManager::agregarMenu() {
    cout << "--- Agregar nuevo Menu ---\n";
    Menu t;
    t.Cargar();

    if (archivo.guardarMenu(t)) {
        cout << "Menu agregado con exito.\n";
        return true;
    } else {
        cout << "Error al agregar Menu.\n";
        return false;
    }
}

/// Listar Menu
void MenuManager::listarMenus() {
    cout << "\n--- Listado de Menus ---\n";
    archivo.listarMenus();
}

/// Modificar Menu
bool MenuManager::modificarMenuPorId() {
    int id;
    cout << "Ingrese ID a modificar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un Menu con ese ID.\n";
        return false;
    }

    cout << "\n--- Modificar Menu ---\n";
    Menu nuevoMenu;
    nuevoMenu.Cargar();

    if (archivo.modificarMenu(id, nuevoMenu)) {
        cout << "Menu modificado con exito.\n";
        return true;
    } else {
        cout << "Error al modificar Menu.\n";
        return false;
    }
}

/// Eliminar Menu
bool MenuManager::eliminarMenuPorId() {
    int id;
    cout << "Ingrese ID a eliminar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1) {
        cout << "No se encontro un Menu con ese ID.\n";
        return false;
    }

    if (archivo.eliminarMenu(id)) {
        cout << "Menu eliminado con exito.\n";
        return true;
    } else {
        cout << "Error al eliminar Menu.\n";
        return false;
    }
}

