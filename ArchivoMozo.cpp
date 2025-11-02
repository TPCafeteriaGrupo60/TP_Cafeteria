#include "ArchivoMozo.h"
#include <iostream>
using namespace std;

bool ArchivoMozo::guardarMozo(const Mozo& reg) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Mozo), 1, p);
    fclose(p);
    return ok;
}

int ArchivoMozo::contarMozos() {
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Mozo);
}

Mozo ArchivoMozo::leerMozo(int pos) {
    Mozo reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;

    fseek(p, pos * sizeof(Mozo), SEEK_SET);
    fread(&reg, sizeof(Mozo), 1, p);
    fclose(p);
    return reg;
}

void ArchivoMozo::listarMozos() {
    int cant = contarMozos();
    for (int i = 0; i < cant; i++) {
        Mozo reg = leerMozo(i);
        if (!reg.getEliminado()) reg.Mostrar();
        cout << "---------------------"<<endl;
    }
}

Mozo ArchivoMozo::buscarMozoPorId(int id) {
    int cant = contarMozos();
    for (int i = 0; i < cant; i++) {
        Mozo reg = leerMozo(i);
        if (reg.getIdMozo() == id && !reg.getEliminado()) {
            return reg;
        }
    }
    return Mozo();
}

int ArchivoMozo::buscarPosPorId(int id) {
    int cant = contarMozos();
    for (int i = 0; i < cant; i++) {
        Mozo reg = leerMozo(i);
        if (reg.getIdMozo() == id && !reg.getEliminado()) {
            return i;
        }
    }
    return -1;
}

bool ArchivoMozo::modificarMozo(int id, const Mozo& modificado) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Mozo reg;
    int pos = 0;
    while (fread(&reg, sizeof(Mozo), 1, p) == 1) {
        if (reg.getIdMozo() == id) {
            fseek(p, pos * sizeof(Mozo), SEEK_SET);
            fwrite(&modificado, sizeof(Mozo), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

bool ArchivoMozo::eliminarMozo(int id) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Mozo reg;
    int pos = 0;
    while (fread(&reg, sizeof(Mozo), 1, p) == 1) {
        if (reg.getIdMozo() == id) {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Mozo), SEEK_SET); ///(puntero al archivo, desplazamiento en bytes, desde donde el desplazamiento).
            fwrite(&reg, sizeof(Mozo), 1, p);      ///SEEK_SET desde el inicio
            fclose(p);                             ///SEK_CUR desde posicion actual
            return true;                           //SEEK_END desde el final
        }
        pos++;
    }

    fclose(p);
    return false;
}

