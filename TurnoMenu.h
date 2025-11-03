#ifndef TURNOMENU_H_INCLUDED
#define TURNOMENU_H_INCLUDED

#include "TurnoManager.h"

class TurnoMenu{

public:
    TurnoMenu(const char* nombreArchivo);

    void mostrarMenu();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    TurnoManager _turnoManager;
    int _cantidadOpciones;

};

#endif
