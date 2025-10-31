#ifndef ARCHIVOMENU_H_INCLUDED
#define ARCHIVOMENU_H_INCLUDED

#include "menu.h"

class ArchivoMenu {
private:
    const char* nombreArchivo;

public:
    ArchivoMenu(const char* nombre) { nombreArchivo = nombre; }

    bool guardarMenu(const Menu& reg);
    Menu leerMenu(int pos);
    int contarMenus();
    int buscarMenuPorId(int id);
    bool modificarMenu(int pos, const Menu& reg);
    bool eliminarMenu(int id);
    void listarMenus();

    void MenuMenus();
};

#endif
