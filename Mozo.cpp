#include <iostream>
#include <cstring>
#include "Mozo.h"
#include "ArchivoTurno.h"
using namespace std;

Mozo::Mozo() {
    idMozo = 0;
    strcpy(nombre, "");
    strcpy(apellido, "");
    idTurno = 0;
    eliminado = false;
}

Mozo::Mozo(int id, const char* nom, const char* ape, int turno) {
    idMozo = id;
    strcpy(nombre, nom);
    strcpy(apellido, ape);
   // fechaIngreso = fecha;
    idTurno = turno;
    eliminado = false;
}

int Mozo::getIdMozo()  { return idMozo; }
const char* Mozo::getNombre()  { return nombre; }
const char* Mozo::getApellido()  { return apellido; }
Fecha Mozo::getFechaIngreso()  { return fechaIngreso; }
int Mozo::getIdTurno()  { return idTurno; }
bool Mozo::getEliminado()  { return eliminado; }

void Mozo::setEliminado(bool e) { eliminado = e; }
void Mozo::setIdMozo(int id) { idMozo = id; }

void Mozo::Cargar() {
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(nombre, 30);
    cout << "Apellido: ";
    cin.getline(apellido, 30);

    cout << "ID del Turno (1=Mediodía, 2=Noche): ";
    cin >> idTurno;

    fechaIngreso = Fecha();
    eliminado = false;
}

void Mozo::Mostrar()  {
    cout<<"ID Mozo: "<<idMozo<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;

    ArchivoTurno archivoTurnos("Turnos.dat");
    Turno turno = archivoTurnos.buscarTurnoPorId(idTurno);

    cout << "Turno: ";
    if (turno.getIdTurno() != 0)
        cout << turno.getNombre() << endl;
    else
        cout << "(sin turno asignado)" << endl;

    cout<<"Eliminado: ";
    if (eliminado){
       cout<<"Sí"<<endl;
    }else {
        cout<<"No"<< endl;
    }
}
