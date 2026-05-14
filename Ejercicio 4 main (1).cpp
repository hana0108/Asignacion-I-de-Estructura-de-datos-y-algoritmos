/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Author: Genesis Quezada
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Movimiento {
    int producto;
    int origen;
    int destino;
    int cantidad;
    int costo;
};

struct Ruta {
    int origen;
    int destino;
    int distancia;
};

bool compararDistancia(Ruta a, Ruta b) {
    return a.distancia < b.distancia;
}

int main() {
    int stock[6][15] = {0};

    int distancia[6][6];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            distancia[i][j] = 9999;
        }
        distancia[i][i] = 0;
    }

    int umbral[15] = {0};

    stock[0][7] = 20;
    stock[3][7] = 0;
    umbral[7] = 10;
    distancia[0][3] = 7;

    stock[5][12] = 15;
    stock[2][12] = 5;
    umbral[12] = 10;
    distancia[5][2] = 5;

    vector<Movimiento> historial;
    int costoTotal = 0;

    for(int p = 0; p < 15; p++) {
        vector<int> sobrantes(6, 0);
        vector<int> faltantes(6, 0);

        for(int i = 0; i < 6; i++) {
            if(stock[i][p] > umbral[p]) {
                sobrantes[i] = stock[i][p] - umbral[p];
            }
            else if(stock[i][p] < umbral[p]) {
                faltantes[i] = umbral[p] - stock[i][p];
            }
        }

        vector<Ruta> opciones;

        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                if(i != j && sobrantes[i] > 0 && faltantes[j] > 0 && distancia[i][j] < 9999) {
                    opciones.push_back({i, j, distancia[i][j]});
                }
            }
        }

        sort(opciones.begin(), opciones.end(), compararDistancia);

        for(auto r : opciones) {
            if(sobrantes[r.origen] > 0 && faltantes[r.destino] > 0) {
                int mover = min(sobrantes[r.origen], faltantes[r.destino]);
                int costo = mover * r.distancia;

                historial.push_back({p, r.origen, r.destino, mover, costo});

                costoTotal += costo;

                stock[r.origen][p] -= mover;
                stock[r.destino][p] += mover;

                sobrantes[r.origen] -= mover;
                faltantes[r.destino] -= mover;
            }
        }
    }

    for(auto m : historial) {
        cout << "Producto " << m.producto << ": "
             << m.cantidad << " unidades movidas de Almacén "
             << m.origen << " a Almacén "
             << m.destino << ". Costo: "
             << m.costo << endl;
    }

    cout << endl;
    cout << "Total de movimientos realizados: " << historial.size() << endl;
    cout << "Costo total: " << costoTotal << endl;

    return 0;
}