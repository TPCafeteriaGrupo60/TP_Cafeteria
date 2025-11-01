#include <iostream>
#include "ArchivoMozo.h"
#include "ArchivoCliente.h"
#include "ArchivoMesa.h"
#include "ArchivoMenu.h"

///#include "ArchivoTurno.h"
#include "TurnoMenu.h"

#include "stock.h"

using namespace std;

int main()
{
    ArchivoMozo menuMozos("Mozos.dat");
    ArchivoMesa menuMesas("Mesas.dat");
    ArchivoCliente menuClientes("Clientes.dat");
    ArchivoMenu menuMenus("Menus.dat");

    ///ArchivoTurno menuTurnos("Turnos.dat");
    TurnoMenu menuTurno("Turnos.dat");

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
                menuMozos.MenuMozos();
                break;
            case 2:
                system("cls");
                mostrarMenuStock();
                menuStock();
                break;
            case 3:
                system("cls");
                menuMesas.MenuMesas();
                break;
            case 4:
                break;
            case 5:
                system("cls");
                menuClientes.MenuClientes();
                break;
            case 6:
                system("cls");
                menuMenus.MenuMenus();
                break;
            case 7:
                system("cls");
                ///menuTurnos.MenuTurnos();
                menuTurno.mostrar();
                break;
            default:
                cout << "Opcion invalida!" << endl;
        }

    } while(opcion != 8);

    return 0;
}
