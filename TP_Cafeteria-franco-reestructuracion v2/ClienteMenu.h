#ifndef ClienteMENU_H_INCLUDED
#define ClienteMENU_H_INCLUDED

#include "ClienteManager.h"

class ClienteMenu{

public:
    ClienteMenu(const char* nombreArchivo);

    void mostrarMenu();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    ClienteManager _ClienteManager;
    int _cantidadOpciones;

};

#endif
