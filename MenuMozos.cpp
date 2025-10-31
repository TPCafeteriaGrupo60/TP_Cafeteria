#include "Mozo.h"
#include "ArchivoMozo.h"
#include <iostream>
using namespace std;

//void ArchivoMozo::MenuMozos(const char* n){
//    nombreArchivo = n;
//}
/*void ArchivoMozo::MenuMozos(){

    ArchivoMozo archivo("Mozos.dat");
    int opcion;

    do
    {
        cout<<"--- MENU MOZOS ---"<<endl;
        cout<<"1- Agregar mozo"<<endl;
        cout<<"2- Listar mozos"<<endl;
        cout<<"3- Modificar mozo"<<endl;
        cout<<"4- Eliminar mozo"<<endl;
        cout<<"5- Salir"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
        {
            Mozo m;
            cout<<"Ingrese datos del mozo:"<<endl;
            m.Cargar();
            if (archivo.guardarMozo(m))
                cout<<"Mozo agregado con exito."<<endl;
            else
                cout<<"Error al guardar el mozo."<<endl;

            break;
        }
        case 2:
            cout<<"Lista de Mozos:"<<endl;
            archivo.listarMozos();

            break;
        case 3:
        {
            int idModificar;
            cout<<"Ingrese el ID del mozo a modificar: ";
            cin>>idModificar;

            Mozo modificado;
            cout << "Ingrese nuevos datos del mozo:"<<endl;
            modificado.Cargar();

            if (archivo.modificarMozo(idModificar, modificado))
                cout<<"Mozo modificado con exito."<<endl;
            else
                cout<<"No se encontró el mozo con ese ID."<<endl;

            break;
        }
        case 4:
        {
            int idEliminar;
            cout<<"Ingrese el ID del mozo a eliminar: ";
            cin>>idEliminar;

            if(archivo.eliminarMozo(idEliminar))
                cout<<"Mozo eliminado con exito."<<endl;
            else
                cout<<"No se encontro el mozo con ese ID."<<endl;

            break;
        }
        case 5:
            cout<<"Volviendo al Meni principal.."<<endl;;
            break;
        default:
            cout<<"Opción invalida, intente nuevamente."<<endl;;
        }



    }
    while(opcion != 5);


}
   */
