#ifndef STOCKMANAGER_H_INCLUDED
#define STOCKMANAGER_H_INCLUDED

#include "ArchivoStock.h"

class StockManager {
private:
    ArchivoStock archivo;

public:
    StockManager(const char* nombreArchivo);

    bool agregarStock();
    void listarStocks();
    bool modificarStockPorId();
    bool eliminarStockPorId();
    void consultarStockPorId();
    void alertaStockMinimo();
    void menuConsultas();
    void mostrarMenuStock();
    void menuStock();
};

#endif
