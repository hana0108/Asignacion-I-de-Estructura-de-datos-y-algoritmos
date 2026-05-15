/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

/*
Autor: Yanibel Pérez Vásquez
*/

int stock[6][15];

void GuardarStock()
{
    cout<<"REGISTRO DE EXISTENCIAS"<<endl;

    for(int i=0; i<6; i++)
    {
        cout<<"\nAlmacen "<<i+1<<endl;

        for(int j=0; j<15; j++)
        {
            cout<<"Producto "<<j+1<<": ";
            cin>>stock[i][j];
        }
    }
}

void MostrarStock()
{
    cout<<"\nMOSTRANDO STOCK"<<endl;

    for(int i=0; i<6; i++)
    {
        cout<<"\nAlmacen "<<i+1<<": ";

        for(int j=0; j<15; j++)
        {
            cout<<stock[i][j]<<"\t";
        }

        cout<<endl;
    }
}

void AlmacenMenorStock()
{
    cout<<"\nALMACEN CON MENOR STOCK"<<endl;

    int menorStock = 0;
    int suma = 0;
    int almacenMenor = 0;

    for(int j=0; j<15; j++)
    {
        menorStock += stock[0][j];
    }

    for(int i=1; i<6; i++)
    {
        suma = 0;

        for(int j=0; j<15; j++)
        {
            suma += stock[i][j];
        }

        if(suma < menorStock)
        {
            menorStock = suma;
            almacenMenor = i;
        }
    }

    cout<<"El almacen con menor stock es: Almacen "
        <<almacenMenor+1<<endl;

    cout<<"Cantidad total: "<<menorStock<<endl;
}

int main()
{
    GuardarStock();

    cout<<endl;

    MostrarStock();

    cout<<endl;

    AlmacenMenorStock();

    return 0;
}