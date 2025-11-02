#ifndef STOCKMENU_H_INCLUDED
#define STOCKMENU_H_INCLUDED

#include "StockManager.h"

class StockMenu
{
public:
    StockMenu(const char* nombreArchivo);
    void mostrarMenu();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    StockManager _StockManager;
    int _cantidadOpciones;
};

#endif
