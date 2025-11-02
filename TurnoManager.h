#ifndef TURNOMANAGER_H_INCLUDED
#define TURNOMANAGER_H_INCLUDED

#include "ArchivoTurno.h"

class TurnoManager {
private:
    ArchivoTurno archivo;

public:
    TurnoManager(const char* nombreArchivo);

    bool agregarTurno();
    void listarTurnos();
    bool modificarTurnoPorId();
    bool eliminarTurnoPorId();
};

#endif
