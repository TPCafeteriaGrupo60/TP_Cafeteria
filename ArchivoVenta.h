#ifndef ARCHIVOVENTA_H_INCLUDED
#define ARCHIVOVENTA_H_INCLUDED

#include "Venta.h"

class ArchivoVenta{

private:
    const char* nombreArchivo;

public:
    ArchivoVenta(const char* n ="Ventas.dat");

    bool guardarVenta(Venta& reg);
    bool leerVenta(Venta&, int pos);
    int contarVentas();
    int buscarVentaPorId(int id);
    void listarVentas();
    void cargarVenta();
    bool modificarVenta(Venta &venta, int pos);
    int generarIdVenta();

    bool eliminarVenta(int pos); /// agregado


    ///void menuVentas();
} ;


#endif // ARCHIVOVENTA_H_INCLUDED
