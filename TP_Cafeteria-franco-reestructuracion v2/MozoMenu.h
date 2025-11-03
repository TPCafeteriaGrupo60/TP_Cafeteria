#ifndef MozoMENU_H_INCLUDED
#define MozoMENU_H_INCLUDED

#include "MozoManager.h"

class MozoMenu{

public:
    MozoMenu(const char* nombreArchivo);

    void mostrarMenu();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    MozoManager _MozoManager;
    int _cantidadOpciones;

};

#endif
