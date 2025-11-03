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
    return Turno();
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
