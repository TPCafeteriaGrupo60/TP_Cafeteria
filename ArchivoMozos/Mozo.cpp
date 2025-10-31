#include <iostream>
#include <cstring>
#include "Mozo.h"
using namespace std;
        ///constructores.
Mozo::Mozo(){

    _idMozo = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _edad = 0;
    _activo = true;
    _idTurno = 0;
}

Mozo::Mozo(int id, const char* nombre, const char* apellido, int edad, int idTurno){

    _idMozo = id;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    _edad = edad;
    _activo = true;
    _idTurno = idTurno;

}
    ///gets
    int Mozo::getIdMozo() { return _idMozo;}
    const char* Mozo::getNombre(){return _nombre;}
    const char* Mozo::getApellido(){return _apellido;}
    int Mozo::getEdad(){return _edad;}
    bool Mozo::getActivo(){return _activo;}
    int Mozo::getIdTurno(){return _idTurno;}

    ///sets
    void Mozo::setIdMozo(int id){_idMozo = id;}
    void Mozo::setNombre(const char* nombre){ strcpy(_nombre, nombre);}
    void Mozo::setApellido(const char* apellido){ strcpy(_apellido, apellido);}
    void Mozo::setEdad(int edad) {_edad = edad;}
    void Mozo::setActivo(bool activo){ _activo = activo;}
    void Mozo::setIdTurno(int idTurno){ _idTurno = idTurno;}


    void  Mozo::mostrar(){
        cout<<"--------------------------------------"<<endl;
        cout<<"ID: "<<_idMozo<<endl;
        cout<<"Nombre Del Mozo: "<<_nombre<<" "<<_apellido<<endl;
        cout<<"Edad: "<<_edad<<endl;
        cout<<"Turno: "<<_idTurno<<endl;
        cout<<"Actividad: ";
        if(_activo){
            cout<<" En Servicio!"<<endl;
        }else {
            cout<<" Fuera de Sevicio!"<<endl<<endl;
        }
        cout<<"--------------------------------------"<<endl;
    }


