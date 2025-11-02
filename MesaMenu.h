#ifndef MesaMENU_H_INCLUDED
#define MesaMENU_H_INCLUDED

#include "MesaManager.h"

class MesaMenu{

public:
    MesaMenu(const char* nombreArchivo);

    void mostrarMenu();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    MesaManager _MesaManager;
    int _cantidadOpciones;

};

#endif
