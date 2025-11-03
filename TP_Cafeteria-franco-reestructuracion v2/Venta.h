#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#include <iostream>
#include <cstring>
#include "Fecha.h"
using namespace std;

class Venta{

private:
    int idVenta;
    Fecha fecha;
    char hora[6];
    int idMozo;
    int idMesa;
    int idCliente; /// se usa el 0(cero) para cliente no registrado.
    int metodoPago;
    int estado;
    float total;
    bool eliminado;

public:

    Venta();
    ///gets
    int getIdVenta();
    Fecha getFecha();
    const char* getHora();
    int getIdMozo();
    int getIdMesa();
    int getIdCliente();
    int getMetodoPago();
    int getEstado();
    float getTotal();
    bool getEliminado();

    ///Sets
    void setIdVenta(int v);
    void setFecha(Fecha f);
    void setHora(const char* h);
    void setIdMozo(int m);
    void setIdMesa(int m);
    void setIdCliente(int c);
    void setMetodoPago(int p);
    void setEstado(int e);
    void setTotal(float t);
    void setEliminado(bool e);

    void cargar();
    void mostrar();
};
#endif // VENTA_H_INCLUDED
