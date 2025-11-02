#ifndef MenuMENU_H_INCLUDED
#define MenuMENU_H_INCLUDED

#include "MenuManager.h"

class MenuMenu{

public:
    MenuMenu(const char* nombreArchivo);

    void mostrarMenu();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    MenuManager _MenuManager;
    int _cantidadOpciones;

};

#endif
