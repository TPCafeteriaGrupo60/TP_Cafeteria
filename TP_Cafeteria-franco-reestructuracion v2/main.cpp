#include <iostream>

///#include "ArchivoCliente.h"
#include "ClienteMenu.h"

///#include "ArchivoMenu.h"
#include "MenuMenu.h"

///#include "ArchivoMesa.h"
#include "MesaMenu.h"

///#include "ArchivoMozo.h"
#include "MozoMenu.h"

///#include "ArchivoTurno.h"
#include "TurnoMenu.h"

#include "stock.h"

#include "ArchivoVenta.h"

using namespace std;

int main()
{
    ///ArchivoMenu menuMenus("Menus.dat");
   MenuMenu menuMenus("Menus.dat");
    ///ArchivoCliente menuClientes("Clientes.dat");
    ClienteMenu menuClientes("Clientes.dat");
    ///ArchivoMesa menuMesas("Mesas.dat");
   MesaMenu menuMesas("Mesas.dat");
    ///ArchivoMozo menuMozos("Mozos.dat");
    MozoMenu menuMozos("Mozos.dat");
    ///ArchivoTurno menuTurnos("Turnos.dat");
    TurnoMenu menuTurnos("Turnos.dat");
    ///ArchivoVenta menuVentas("Ventas.dat");
    ArchivoVenta archivoVenta("Ventas.dat");


    Stock Stock;

    int opcion;
    do {
        system("cls");
        cout<< "---- Menu Principal ----" <<endl;
        cout<< "1. Mozos"<<endl;
        cout<< "2. Stock"<<endl;
        cout<< "3. Mesas"<<endl;
        cout<< "4. Ventas"<<endl;
        cout<< "5. Clientes"<<endl;
        cout<< "6. Menus a la Venta"<<endl;
        cout<< "7. Turnos de Atencion"<<endl;
        cout<< "------------------------" <<endl;
        cout<<"Elegir Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                system("cls");
                //menuMozos.MenuMozos();
               menuMozos.mostrarMenu();
                break;
            case 2:
//                system("cls");
               mostrarMenuStock();
               menuStock();
                break;
            case 3:
                system("cls");
                //menuMesas.MenuMesas();
                menuMesas.mostrarMenu();
               break;
            case 4:
                archivoVenta.menuVentas();
                break;
            case 5:
                system("cls");
                //menuClientes.MenuClientes();
               menuClientes.mostrarMenu();
                break;
            case 6:
                system("cls");
                //menuMenus.MenuMenus();
               menuMenus.mostrarMenu();
                break;
            case 7:
                system("cls");
                //menuTurnos.MenuTurnos();
                menuTurnos.mostrar();
                break;
            default:
                cout << "Opcion invalida!" << endl;
        }

    } while(opcion != 8);

    return 0;
}
