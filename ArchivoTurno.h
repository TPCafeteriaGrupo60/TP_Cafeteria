#ifndef ARCHIVOTURNO_H_INCLUDED
#define ARCHIVOTURNO_H_INCLUDED

#include "Turno.h"

class ArchivoTurno {
private:
    const char* nombreArchivo;

public:
    ArchivoTurno(const char* nombre) { nombreArchivo = nombre; }

    bool guardarTurno(const Turno& reg);
    Turno leerTurno(int pos);
    int contarTurnos();
    Turno buscarTurnoPorId(int id);
    int buscarPosPorId(int id);
    void listarTurnos();
    bool modificarTurno(int pos, const Turno& reg);
    bool eliminarTurno(int id);
};

#endif
