#ifndef ARCHIVOMOZO_H
#define ARCHIVOMOZO_H

#include "Mozo.h"
#include <cstdio>

class ArchivoMozo {
private:
    const char* nombreArchivo;

public:
    ArchivoMozo(const char* nombre) { nombreArchivo = nombre; }

    bool guardarMozo(const Mozo& reg);
    int contarMozos();
    Mozo leerMozo(int pos);
    void listarMozos();
    bool eliminarMozo(int id);
    bool modificarMozo(int id, const Mozo& modificado);
    void MenuMozos();
    void agregarMozo();
    Mozo cargarDatosMozo(int idExistente);
    void editarMozo();
};

#endif
