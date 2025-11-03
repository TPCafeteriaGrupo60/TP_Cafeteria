#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "ClienteMenu.h"
#include "MenuMenu.h"
#include "MesaMenu.h"
#include "MozoMenu.h"
#include "TurnoMenu.h"
#include "StockMenu.h"
#include "VentaMenu.h"

class App
{

public:
    App();
    void run();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    int _cantidadOpciones;

    ClienteMenu menuClientes;
    MenuMenu menuMenus;
    MesaMenu menuMesas;
    MozoMenu menuMozos;
    StockMenu menuStock;
    TurnoMenu menuTurnos;
    VentaMenu menuVentas;
};

#endif
