#ifndef ARCHIVOSTOCK_H_INCLUDED
#define ARCHIVOSTOCK_H_INCLUDED

#include "Stock.h"
#include <cstdio>

class ArchivoStock {
private:
    const char* nombreArchivo;

public:
    ArchivoStock(const char* nombre) { nombreArchivo = nombre; }

    bool guardarStock(const Stock& reg);
    Stock leerStock(int pos);
    int contarStock();
    Stock buscarStockPorId(int id);
    int buscarPosPorId(int id);
    bool modificarStock(int pos, const Stock& modificado);
    bool eliminarStock(int id);
    void listarStocks();
    int generarIdStock();
    void alertaStockMinimo();
    void consultarPorCategoria();
    void consultarPorPrecio();
    void consultarPorNivelStock();
};

#endif

