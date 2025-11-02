#include <iostream>
#include <cstdio>
#include "ArchivoMesa.h"

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

int ArchivoMesa::buscarPosPorId(int id) {
    int cant = contarMesas();
    for (int i = 0; i < cant; i++) {
        Mesa reg = leerMesa(i);
        if (reg.getIdMesa() == id && !reg.getEliminado()) {
            return i;
        }
    }
    return -1;
}

Mesa ArchivoMesa::buscarMesaPorId(int id) {
    int cant = contarMesas();
    for (int i = 0; i < cant; i++) {
        Mesa reg = leerMesa(i);
        if (reg.getIdMesa() == id && !reg.getEliminado()) {
            return reg;
        }
    }
    return Mesa();
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
