#ifndef VENTAMENU_H_INCLUDED
#define VENTAMENU_H_INCLUDED

#include "VentaManager.h"

class VentaMenu {
public:
    VentaMenu(const char* nombreArchivo = "Ventas.dat");
    void mostrarMenu();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    VentaManager _VentaManager;
    int _cantidadOpciones;
};

#endif
