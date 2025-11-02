#include <iostream>
#include <cstring>
#include "Cliente.h"
#include "Fecha.h"
using namespace std;

Cliente::Cliente() {
    idCliente = 0;
    strcpy(nombre, "");
    strcpy(apellido, "");
    strcpy(telefono, "");
    eliminado = false;
}

Cliente::Cliente(int id, const char* nom, const char* ape, const char* tel, Fecha fAlta) {
    idCliente = id;
    strcpy(nombre, nom);
    strcpy(apellido, ape);
    strcpy(telefono, tel);
    fechaAlta = fAlta;
    eliminado = false;
}

int Cliente::getIdCliente()  { return idCliente; }
const char* Cliente::getNombre()  { return nombre; }
const char* Cliente::getApellido()  { return apellido; }
const char* Cliente::getTelefono()  { return telefono; }
Fecha Cliente::getFechaAlta()  { return fechaAlta; }
bool Cliente::getEliminado()  { return eliminado; }

void Cliente::setEliminado(bool e) { eliminado = e; }

void Cliente::Cargar() {
    cout << "ID Cliente: ";
    cin >> idCliente;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(nombre, 30);
    cout << "Apellido: ";
    cin.getline(apellido, 30);
    cout << "Telefono: ";
    cin.getline(telefono, 20);
    cout << "Fecha de alta: ";
    fechaAlta.Cargar();
    eliminado = false;
}

void Cliente::Mostrar()  {
    cout << "ID Cliente: " << idCliente << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Fecha de alta: ";
    fechaAlta.Mostrar();
    cout << "Eliminado: " << (eliminado ? "S " : "No") << endl;
    cout << "-----------------------------" << endl;
}
