#include <iostream>
#include <cstdio>
#include "Mozo.h"


using namespace std;
const char* ARCHIVO_MOZOS = "mozos.dat";

///Funciones Para el Archivo,
bool guardarMozo(Mozo mozo)
{
    FILE* p = fopen(ARCHIVO_MOZOS, "ab");
    if(p == nullptr)return false;
    bool ok = fwrite(&mozo, sizeof(Mozo), 1, p);
    fclose(p);
    return ok;
}                                                 ///SEEK_SET: El desplazamiento se realiza desde el principio del archivo.
                                                  ///SEEK_CUR: El desplazamiento se realiza desde la posición actual del puntero.
bool editarMozo(Mozo mozo, int posicion)          ///SEEK_END: El desplazamiento se realiza desde el final del archivo.
{

    FILE* p = fopen(ARCHIVO_MOZOS, "rb+");
    if (p == nullptr) return false;
    fseek(p, sizeof(Mozo) * posicion, SEEK_SET);
    bool ok = fwrite(&mozo, sizeof(Mozo), 1, p);
    fclose(p);
    return ok;
}
int buscarMozo(int idMozo)
{
    FILE* p = fopen(ARCHIVO_MOZOS, "rb");
    if (p == NULL) return -1;
    Mozo mozo;
    int pos = 0;
    while (fread(&mozo, sizeof(Mozo), 1, p))
    {
        if (mozo.getIdMozo() == idMozo && mozo.getActivo())
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

Mozo leerMozo(int posicion)
{
    Mozo mozo;
    FILE* p = fopen(ARCHIVO_MOZOS, "rb");
    if (p == NULL) return mozo;
    fseek(p, sizeof(Mozo) * posicion, SEEK_SET);
    fread(&mozo, sizeof(Mozo), 1, p);
    fclose(p);
    return mozo;
}

int cantidadRegistrosMozos()
{
    FILE* p = fopen(ARCHIVO_MOZOS, "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Mozo);
}
bool eliminarMozo(int posicion)
{
    Mozo mozo = leerMozo(posicion);
    if (mozo.getIdMozo() == 0) return false;
    mozo.setActivo(false);
    return editarMozo(mozo, posicion);
}
///Principales Funciones

void listarMozos()
{
    int total = cantidadRegistrosMozos();
    cout<<"Lista De Mozos Actuales "<<endl;
    for(int i=0; i<total; i++)
    {

        Mozo mozo =leerMozo(i);
        if(mozo.getActivo())
        {
            mozo.mostrar();
        }
    }
}
void agregarMozo()
{
    Mozo mozo;
    char nombre[30], apellido[30];
    int edad;
    int id=cantidadRegistrosMozos() + 1;
    int idTurno;
    cout<<"ID del Nuevo Mozo: "<<id<<endl;
    cout<<"Ingrese El Nombre: ";
    cin.ignore();
    cin.getline(nombre, 30);
    cout<<"Ingrese El Apellido: ";
    cin.getline(apellido, 30);
    cout<<"Ingrese La Edad: ";
    cin>>edad;
    cout<<"Ingrese El ID del Turno 1=Mediodia, 2=Noche: ";
    cin>>idTurno;


    Mozo nuevoMozo(id, nombre, apellido, edad, idTurno);
    if(guardarMozo(nuevoMozo))
    {
        cout<<"Se Agrego Nuevo Mozo Correctamente!"<<endl;
    }
    else
    {
        cout<<"Error Al Agregar Mozo!"<<endl;
    }
}
void MostrarMenuMozos()
{

    int opcion;
    do
    {
        cout<<"____MENU DE MOZOS____"<<endl;
        cout<<"1.Agregar mozo"<<endl;
        cout<<"2.Listar mozos"<<endl;
        cout<<"3.Eliminar mozo"<<endl;
        cout<<"0.Volver al menu principal"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            agregarMozo();
            break;
        case 2:
            listarMozos();
            break;
        case 3:
        {
            int id;
            cout << "Ingrese ID del mozo a eliminar: ";
            cin >> id;
            int pos = buscarMozo(id);
            if (pos == -1)
            {
                cout << "Mozo no encontrado." << endl;
            }
            else
            {
                eliminarMozo(pos);
                cout << "Mozo eliminado correctamente." << endl;
            }
        }
        break;
        case 0:

        break;
        default:
            cout<<"opcion Invalida!"<<endl;
            break;

        }
        cout<<endl;
    }
    while(opcion !=0);
}
