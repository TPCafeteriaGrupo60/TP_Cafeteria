#include <iostream>
#include <cstring>
#include "menu.h"
using namespace std;

Menu::Menu() {
    idMenu = 0;
    idProducto = 0;
    strcpy(nombre, "");
    strcpy(descripcion, "");
    precioVenta = 0.0f;
    strcpy(categoria, "");
    activo = true;
    eliminado = false;
}

Menu::Menu(int idM, int idProd, const char* nom, const char* desc, float precio, const char* cat, bool act) {
    idMenu = idM;
    idProducto = idProd;
    strncpy(nombre, nom, sizeof(nombre)-1); nombre[sizeof(nombre)-1] = '\0';
    strncpy(descripcion, desc, sizeof(descripcion)-1); descripcion[sizeof(descripcion)-1] = '\0';
    precioVenta = precio;
    strncpy(categoria, cat, sizeof(categoria)-1); categoria[sizeof(categoria)-1] = '\0';
    activo = act;
    eliminado = false;
}

int Menu::getIdMenu() const { return idMenu; }
int Menu::getIdProducto() const { return idProducto; }
const char* Menu::getNombre() const { return nombre; }
const char* Menu::getDescripcion() const { return descripcion; }
float Menu::getPrecioVenta() const { return precioVenta; }
const char* Menu::getCategoria() const { return categoria; }
bool Menu::getActivo() const { return activo; }
bool Menu::getEliminado() const { return eliminado; }

void Menu::setIdMenu(int id) { idMenu = id; }
void Menu::setIdProducto(int id) { idProducto = id; }
void Menu::setNombre(const char* n) { strncpy(nombre, n, sizeof(nombre)-1); nombre[sizeof(nombre)-1] = '\0'; }
void Menu::setDescripcion(const char* d) { strncpy(descripcion, d, sizeof(descripcion)-1); descripcion[sizeof(descripcion)-1] = '\0'; }
void Menu::setPrecioVenta(float p) { precioVenta = p; }
void Menu::setCategoria(const char* c) { strncpy(categoria, c, sizeof(categoria)-1); categoria[sizeof(categoria)-1] = '\0'; }
void Menu::setActivo(bool a) { activo = a; }
void Menu::setEliminado(bool e) { eliminado = e; }

void Menu::Cargar() {
    cout << "ID Menu: ";
    cin >> idMenu;
    cout << "ID Producto: ";
    cin >> idProducto;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(nombre, sizeof(nombre));
    cout << "Descripcion: ";
    cin.getline(descripcion, sizeof(descripcion));
    cout << "Precio de venta: ";
    cin >> precioVenta;
    cin.ignore();
    cout << "Categoria: ";
    cin.getline(categoria, sizeof(categoria));
    activo = true;
    eliminado = false;
}

void Menu::Mostrar() const {
    cout << "ID Menu: " << idMenu << endl;
    cout << "ID Producto: " << idProducto << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Precio de venta: " << precioVenta << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Activo: " << (activo ? "Sí" : "No") << endl;
    cout << "Eliminado: " << (eliminado ? "Sí" : "No") << endl;
}
