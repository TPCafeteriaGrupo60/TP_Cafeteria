#include <iostream>
#include <cstdio>
#include "ArchivoMenu.h"
using namespace std;


bool ArchivoMenu::guardarMenu(const Menu& reg) {
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Menu), 1, p);
    fclose(p);
    return ok;
}

Menu ArchivoMenu::leerMenu(int pos) {
    Menu reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Menu), SEEK_SET);
    fread(&reg, sizeof(Menu), 1, p);
    fclose(p);
    return reg;
}

int ArchivoMenu::contarMenus() {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Menu);
}

int ArchivoMenu::buscarMenuPorId(int id) {
    Menu reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return -1;
    int pos = 0;
    while (fread(&reg, sizeof(Menu), 1, p)) {
        if (reg.getIdMenu() == id && !reg.getEliminado()) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool ArchivoMenu::modificarMenu(int pos, const Menu& reg) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Menu), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Menu), 1, p);
    fclose(p);
    return ok;
}

bool ArchivoMenu::eliminarMenu(int id) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Menu reg;
    int pos = 0;
    while (fread(&reg, sizeof(Menu), 1, p) == 1) {
        if (reg.getIdMenu() == id) {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Menu), SEEK_SET);
            fwrite(&reg, sizeof(Menu), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

void ArchivoMenu::listarMenus() {
    int cant = contarMenus();
    for (int i = 0; i < cant; i++) {
        Menu reg = leerMenu(i);
        if (!reg.getEliminado()) {
            reg.Mostrar();
            cout << "---------------------" << endl;
        }
    }
}
void ArchivoMenu::MenuMenus() {
    ArchivoMenu archivo("Menus.dat");
    int opcion;

    do {
        cout << "--- MENU DE MENUS ---" << endl;
        cout << "1 - Agregar menu" << endl;
        cout << "2 - Listar menus" << endl;
        cout << "3 - Modificar menu" << endl;
        cout << "4 - Eliminar menu" << endl;
        cout << "5 - Salir" << endl;
        cout << "---------------------" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            Menu m;
            cout << "Ingrese los datos del menu:" << endl;
            m.Cargar();
            if (archivo.guardarMenu(m))
                cout << "Menu agregado con exito." << endl;
            else
                cout << "Error al guardar el menu." << endl;
            break;
        }
        case 2:
            cout << "Lista de menus:" << endl;
            archivo.listarMenus();
            break;
        case 3: {
            int idModificar;
            cout << "Ingrese el ID del menu a modificar: ";
            cin >> idModificar;

            int pos = archivo.buscarMenuPorId(idModificar);
            if (pos == -1) {
                cout << "No se encontro un menu con ese ID." << endl;
                break;
            }

            Menu modificado;
            cout << "Ingrese los nuevos datos del menu:" << endl;
            modificado.Cargar();

            if (archivo.modificarMenu(pos, modificado))
                cout << "Menu modificado con exito." << endl;
            else
                cout << "Error al modificar el menu." << endl;
            break;
        }
        case 4: {
            int idEliminar;
            cout << "Ingrese el ID del menu a eliminar: ";
            cin >> idEliminar;

            if (archivo.eliminarMenu(idEliminar))
                cout << "Menu eliminado con exito." << endl;
            else
                cout << "No se encontro el menu con ese ID." << endl;
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
