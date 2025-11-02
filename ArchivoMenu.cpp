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

Menu ArchivoMenu::buscarMenuPorId(int id) {
    int cant = contarMenus();
    for (int i = 0; i < cant; i++) {
        Menu reg = leerMenu(i);
        if (reg.getIdMenu() == id && !reg.getEliminado()) {
            return reg;
        }
    }
    return Menu();
}

int ArchivoMenu::buscarPosPorId(int id) {
    int cant = contarMenus();
    for (int i = 0; i < cant; i++) {
        Menu reg = leerMenu(i);
        if (reg.getIdMenu() == id && !reg.getEliminado()) {
            return i;
        }
    }
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
