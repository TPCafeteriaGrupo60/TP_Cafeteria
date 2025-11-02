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
    Mozo leerMozo(int pos);
    int contarMozos();
    Mozo buscarMozoPorId(int id);
    int buscarPosPorId(int id);
    void listarMozos();
    bool modificarMozo(int id, const Mozo& modificado);
    bool eliminarMozo(int id);
};

#endif
