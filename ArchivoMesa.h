#ifndef ARCHIVOMESA_H_INCLUDED
#define ARCHIVOMESA_H_INCLUDED

#include "Mesa.h"
#include <cstdio>

class ArchivoMesa {
private:
    const char* nombreArchivo;

public:
    ArchivoMesa(const char* nombre) { nombreArchivo = nombre; }

    bool guardarMesa(const Mesa& reg);
    int contarMesas();
    Mesa leerMesa(int pos);
    void listarMesas();
    bool eliminarMesa(int id);
    bool modificarMesa(int id, const Mesa& modificado);

    void MenuMesas();
};


#endif
