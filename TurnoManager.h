#ifndef TURNOMANAGER_H_INCLUDED
#define TURNOMANAGER_H_INCLUDED

#include "ArchivoTurno.h"

class TurnoManager {
private:
    ArchivoTurno archivo;

public:
    TurnoManager(const char* nombreArchivo);

    bool agregarTurno(const Turno& t);
    void listarTurnos();
    bool modificarTurnoPorId(int id, const Turno& t);
    bool eliminarTurnoPorId(int id);
};

#endif
