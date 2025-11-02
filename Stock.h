#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <iostream>
#include <cstring>

class Stock
{
private:
    int _idProducto;
    char _nombre[40];
    char _categoria[20];
    char _unidadMedida[10];
    float _precioCosto;
    float _precioVenta;
    int _stockActual;
    int _stockMinimo;
    bool _eliminado;

public:
    Stock();
    Stock(int id, const char* nombre, const char* categoria, const char* unidadMedida,
          float precioCosto, float precioVenta, int stockActual, int stockMinimo);

    // Getters
    int getIdProducto();
    const char* getNombre();
    const char* getCategoria();
    const char* getUnidadMedida();
    float getPrecioCosto();
    float getPrecioVenta();
    int getStockActual();
    int getStockMinimo();
    bool getEliminado();

    // Setters
    void setIdProducto(int id);
    void setNombre(const char* nombre);
    void setCategoria(const char* categoria);
    void setUnidadMedida(const char* unidadMedida);
    void setPrecioCosto(float precio);
    void setPrecioVenta(float precio);
    void setStockActual(int stock);
    void setStockMinimo(int stockMinimo);
    void setEliminado(bool eliminado);

    void Cargar();
    void Mostrar();
};

#endif
