#include <iostream>
#include "ArchivoMozo.h"
#include "ArchivoMesa.h"
#include "ArchivoCliente.h"
#include "ArchivoMenu.h"
#include "ArchivoTurno.h"

#include <cstdlib>
using namespace std;
int main()
{
    ArchivoMozo mozo("Mozos.dat");
    ArchivoMesa mesa("Mesas.dat");
    ArchivoCliente cliente("Clientes.dat");
    ArchivoMenu menu("Menu.dat");
    ArchivoTurno turno("Turno.dat");

    int opcion;
    do {
        system("cls");
        cout<< "--- Menu Principal ---" <<endl;
        cout<< "1 - Mozos"<<endl;
        cout<< "2 - Stock"<<endl;
        cout<< "3 - Mesas"<<endl;
        cout<< "4 - Ventas"<<endl;
        cout<< "5 - Clientes"<<endl;
        cout<< "5 - Clientes"<<endl;
        cout<< "6 - Menus"<<endl;
        cout<< "7 - Turnos"<<endl;
        cout<< "----------------------"<<endl;
        cout<<"Elegir Opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                system("cls");
                mozo.MenuMozos();
                break;
            case 2:
                system("cls");
                cout << "Funcionalidad de Stock aún no implementada." << endl;
                cout << endl; system("pause");
                break;
            case 3:
                system("cls");
                //mesa.MenuMesas();
                break;
            case 4:
                system("cls");
                cout << "Funcionalidad de Ventas aun no implementada." << endl;
                cout << endl; system("pause");
                break;
            case 5:
                system("cls");
                cliente.MenuClientes();
                break;
            case 6:
                system("cls");
                menu.MenuMenus();
                break;
            case 7:
                system("cls");
                turno.MenuTurnos();
                break;
            default:
                cout << "\nOpción inválida. Intente nuevamente." << endl;
                cout << endl; system("pause");
                break;
            }

     } while (opcion != 0);

return 0;
}
