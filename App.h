#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "ClienteMenu.h"
#include "MenuMenu.h"
#include "MesaMenu.h"
#include "MozoMenu.h"
#include "TurnoMenu.h"
#include "StockMenu.h"

///#include "ArchivoVenta.h"
#include "VentaMenu.h"

class App
{

public:
    void run();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    int _cantidadOpciones;

};

#endif

