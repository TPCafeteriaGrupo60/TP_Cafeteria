#include "ArchivoMozo.h"
#include <iostream>
using namespace std;

bool ArchivoMozo::guardarMozo(const Mozo& reg) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Mozo), 1, p);
    fclose(p);
    return ok;
}

int ArchivoMozo::contarMozos() {
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Mozo);
}

Mozo ArchivoMozo::leerMozo(int pos) {
    Mozo reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;

    fseek(p, pos * sizeof(Mozo), SEEK_SET);
    fread(&reg, sizeof(Mozo), 1, p);
    fclose(p);
    return reg;
}

void ArchivoMozo::listarMozos() {
    int cant = contarMozos();
    for (int i = 0; i < cant; i++) {
        Mozo reg = leerMozo(i);
        if (!reg.getEliminado()) reg.Mostrar();
        cout << "---------------------"<<endl;
    }
}

bool ArchivoMozo::eliminarMozo(int id) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Mozo reg;
    int pos = 0;
    while (fread(&reg, sizeof(Mozo), 1, p) == 1) {
        if (reg.getIdMozo() == id) {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Mozo), SEEK_SET); ///(puntero al archivo, desplazamiento en bytes, desde donde el desplazamiento).
            fwrite(&reg, sizeof(Mozo), 1, p);      ///SEEK_SET desde el inicio
            fclose(p);                             ///SEK_CUR desde posicion actual
            return true;                           //SEEK_END desde el final
        }
        pos++;
    }

    fclose(p);
    return false;
}

//bool ArchivoMozo::modificarMozo(int id, const Mozo& modificado) {
//    FILE* p = fopen(nombreArchivo, "rb+");
//    if (p == nullptr) return false;
//
//    Mozo reg;
//    int pos = 0;
//    while (fread(&reg, sizeof(Mozo), 1, p) == 1) {
//        if (reg.getIdMozo() == id) {
//            fseek(p, pos * sizeof(Mozo), SEEK_SET);
//            fwrite(&modificado, sizeof(Mozo), 1, p);
//            fclose(p);
//            return true;
//        }
//        pos++;
//    }
//
//    fclose(p);
//    return false;
//}

Mozo ArchivoMozo::cargarDatosMozo(int idExistente) {
    char nombre[30], apellido[30];
    int  idTurno;

    cout << "Ingrese El Nombre: ";
    cin.ignore();
    cin.getline(nombre, 30);
    cout << "Ingrese El Apellido: ";
    cin.getline(apellido, 30);
    cout << "Ingrese El ID del Turno (1=Mediodía, 2=Noche): ";
    cin >> idTurno;

    Mozo mozo(idExistente, nombre, apellido, idTurno);
    return mozo;
}

 void ArchivoMozo::editarMozo() {
    listarMozos();
    int idModificar;
    cout<<endl;
    cout << "Ingrese el ID del mozo a modificar: ";
    cin >> idModificar;

    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    Mozo mozo;
    int pos = 0;
    bool encontrado = false;

    while (fread(&mozo, sizeof(Mozo), 1, p) == 1) {
        if (mozo.getIdMozo() == idModificar) {
            cout << "Datos actuales del mozo" << endl;
            mozo.Mostrar();

            cout << "Ingrese los nuevos datos" << endl;
            Mozo mozoEditado = cargarDatosMozo(idModificar);

            fseek(p, pos * sizeof(Mozo), SEEK_SET);
            fwrite(&mozoEditado, sizeof(Mozo), 1, p);
            encontrado = true;
            cout << "Mozo modificado correctamente." << endl;
            break;
        }
        pos++;
    }

    if (!encontrado)
        cout << "No se encontro un mozo con ese ID." << endl;

    fclose(p);
}



void ArchivoMozo::agregarMozo() {
    int id = contarMozos() + 1;
    cout << "ID del Nuevo Mozo: " << id << endl;

    Mozo nuevoMozo = cargarDatosMozo(id);

    if (guardarMozo(nuevoMozo))
        cout << "Se agrego nuevo mozo correctamente" << endl;
    else
        cout << "Error al agregar mozo." << endl;

}


void ArchivoMozo::MenuMozos(){

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
            system("cls");
            archivo.agregarMozo();

            break;
        }
        case 2:
            system("cls");
            cout<<"Lista de Mozos:"<<endl;
            archivo.listarMozos();

            break;
        case 3:
        {   system("cls");
        cout<<"-----Lista De Mozos-----"<<endl;
            archivo.editarMozo();

            break;
        }
        case 4:
        {   system("cls");
            archivo.listarMozos();
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

