#ifndef MenuMANAGER_H_INCLUDED
#define MenuMANAGER_H_INCLUDED

#include "ArchivoMenu.h"

class MenuManager {
private:
    ArchivoMenu archivo;

public:
    MenuManager(const char* nombreArchivo);

    bool agregarMenu();
    void listarMenus();
    bool modificarMenuPorId();
    bool eliminarMenuPorId();
};

#endif
