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
    Mesa leerMesa(int pos);
    int contarMesas();
    Mesa buscarMesaPorId(int id);
    int buscarPosPorId(int id);
    void listarMesas();
    bool eliminarMesa(int id);
    bool modificarMesa(int id, const Mesa& modificado);
};


#endif
