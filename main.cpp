#include <iostream>

#include "ClienteMenu.h"
#include "MenuMenu.h"
#include "MesaMenu.h"
#include "MozoMenu.h"
#include "TurnoMenu.h"
#include "StockMenu.h"

#include "ArchivoVenta.h"

using namespace std;

int main()
{
    ClienteMenu menuClientes("Clientes.dat");
    MenuMenu menuMenus("Menus.dat");
    MesaMenu menuMesas("Mesas.dat");
    MozoMenu menuMozos("Mozos.dat");
    StockMenu stockMenu("stock.dat");
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
               menuMozos.mostrarMenu();
                break;
            case 2:
                system("cls");
                stockMenu.mostrarMenu();
                break;
            case 3:
                system("cls");
                menuMesas.mostrarMenu();
               break;
            case 4:
                archivoVenta.menuVentas();
                break;
            case 5:
                system("cls");
               menuClientes.mostrarMenu();
                break;
            case 6:
                system("cls");
               menuMenus.mostrarMenu();
                break;
            case 7:
                system("cls");
                menuTurnos.mostrar();
                break;
            default:
                cout << "Opcion invalida!" << endl;
        }

    } while(opcion != 8);

    return 0;
}
