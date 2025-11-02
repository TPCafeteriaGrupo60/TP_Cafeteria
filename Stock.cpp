/*#include <iostream>
#include <iomanip>
#include <cstring>
#include "Stock.h"

using namespace std;

Stock::Stock()
{
    _idProducto = 0;
    strcpy(_nombre, "");
    strcpy(_categoria, "");
    strcpy(_unidadMedida, "");
    _precioCosto = 0;
    _precioVenta = 0;
    _stockActual = 0;
    _stockMinimo = 0;
    _eliminado = false;
}

Stock::Stock(int id, const char* nombre, const char* categoria, const char* unidadMedida,
             float precioCosto, float precioVenta, int stockActual, int stockMinimo)
{
    _idProducto = id;
    strcpy(_nombre, nombre);
    strcpy(_categoria, categoria);
    strcpy(_unidadMedida, unidadMedida);
    _precioCosto = precioCosto;
    _precioVenta = precioVenta;
    _stockActual = stockActual;
    _stockMinimo = stockMinimo;
    _eliminado = false;
}

// Getters
int Stock::getIdProducto() { return _idProducto; }
const char* Stock::getNombre() { return _nombre; }
const char* Stock::getCategoria() { return _categoria; }
const char* Stock::getUnidadMedida() { return _unidadMedida; }
float Stock::getPrecioCosto() { return _precioCosto; }
float Stock::getPrecioVenta() { return _precioVenta; }
int Stock::getStockActual() { return _stockActual; }
int Stock::getStockMinimo() { return _stockMinimo; }
bool Stock::getEliminado() { return _eliminado; }

// Setters
void Stock::setIdProducto(int id) { _idProducto = id; }
void Stock::setNombre(const char* nombre) { strcpy(_nombre, nombre); }
void Stock::setCategoria(const char* categoria) { strcpy(_categoria, categoria); }
void Stock::setUnidadMedida(const char* unidadMedida) { strcpy(_unidadMedida, unidadMedida); }
void Stock::setPrecioCosto(float precio) { _precioCosto = precio; }
void Stock::setPrecioVenta(float precio) { _precioVenta = precio; }
void Stock::setStockActual(int stock) { _stockActual = stock; }
void Stock::setStockMinimo(int stockMinimo) { _stockMinimo = stockMinimo; }
void Stock::setEliminado(bool eliminado) { _eliminado = eliminado; }

void Stock::Cargar()
{
    //cout << "ID Producto: ";
    //cin >> _idProducto;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(_nombre, 40);
    cout << "Categoria: ";
    cin.getline(_categoria, 20);
    cout << "Unidad de medida: ";
    cin.getline(_unidadMedida, 10);
    cout << "Precio costo: ";
    cin >> _precioCosto;
    cout << "Precio venta: ";
    cin >> _precioVenta;
    cout << "Stock actual: ";
    cin >> _stockActual;
    cout << "Stock minimo: ";
    cin >> _stockMinimo;
    _eliminado = false;
}

void Stock::Mostrar()
{
    cout << _idProducto << "\t| "
         << _nombre << "\t| "
         << _categoria << "\t| "
         << _unidadMedida << "\t| "
         << "$" << _precioCosto << "\t| "
         << "$" << _precioVenta << "\t| "
         << _stockActual << "\t| "
         << _stockMinimo << endl;
}*/


#include <iostream>
#include <iomanip>
#include <cstring>
#include "Stock.h"

using namespace std;

Stock::Stock()
{
    _idProducto = 0;
    strcpy(_nombre, "");
    strcpy(_categoria, "");
    strcpy(_unidadMedida, "");
    _precioCosto = 0;
    _precioVenta = 0;
    _stockActual = 0;
    _stockMinimo = 0;
    _eliminado = false;
}

Stock::Stock(int id, const char* nombre, const char* categoria, const char* unidadMedida,
             float precioCosto, float precioVenta, int stockActual, int stockMinimo)
{
    _idProducto = id;
    strcpy(_nombre, nombre);
    strcpy(_categoria, categoria);
    strcpy(_unidadMedida, unidadMedida);
    _precioCosto = precioCosto;
    _precioVenta = precioVenta;
    _stockActual = stockActual;
    _stockMinimo = stockMinimo;
    _eliminado = false;
}

// Getters
int Stock::getIdProducto() { return _idProducto; }
const char* Stock::getNombre() { return _nombre; }
const char* Stock::getCategoria() { return _categoria; }
const char* Stock::getUnidadMedida() { return _unidadMedida; }
float Stock::getPrecioCosto() { return _precioCosto; }
float Stock::getPrecioVenta() { return _precioVenta; }
int Stock::getStockActual() { return _stockActual; }
int Stock::getStockMinimo() { return _stockMinimo; }
bool Stock::getEliminado() { return _eliminado; }

// Setters
void Stock::setIdProducto(int id) { _idProducto = id; }
void Stock::setNombre(const char* nombre) { strcpy(_nombre, nombre); }
void Stock::setCategoria(const char* categoria) { strcpy(_categoria, categoria); }
void Stock::setUnidadMedida(const char* unidadMedida) { strcpy(_unidadMedida, unidadMedida); }
void Stock::setPrecioCosto(float precio) { _precioCosto = precio; }
void Stock::setPrecioVenta(float precio) { _precioVenta = precio; }
void Stock::setStockActual(int stock) { _stockActual = stock; }
void Stock::setStockMinimo(int stockMinimo) { _stockMinimo = stockMinimo; }
void Stock::setEliminado(bool eliminado) { _eliminado = eliminado; }

void Stock::Cargar()
{
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(_nombre, 40);
    cout << "Categoria: ";
    cin.getline(_categoria, 20);
    cout << "Unidad de medida: ";
    cin.getline(_unidadMedida, 10);
    cout << "Precio costo: ";
    cin >> _precioCosto;
    cout << "Precio venta: ";
    cin >> _precioVenta;
    cout << "Stock actual: ";
    cin >> _stockActual;
    cout << "Stock minimo: ";
    cin >> _stockMinimo;
}

void Stock::Mostrar()
{
    cout << _idProducto << "\t| "
         << _nombre << "\t| "
         << _categoria << "\t| "
         << _unidadMedida << "\t| "
         << "$" << _precioCosto << "\t| "
         << "$" << _precioVenta << "\t| "
         << _stockActual << "\t| "
         << _stockMinimo << endl;
}
