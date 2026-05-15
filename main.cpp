#include <iostream>
#include <string>

using namespace std;

class Equipo
{
public:
    string nombre;
    string institucion;
    string categoria;
    double puntaje;
    string pais;
};

int main()
{
    Equipo equipos[20];
    int contador = 0;
    int opcion;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar equipos" << endl;
        cout << "2. Mostrar equipos" << endl;
        cout << "3. Ordenar por puntaje" << endl;
        cout << "4. Mejor y peor equipo" << endl;
        cout << "5. Filtrar por pais" << endl;
        cout << "6. Contar nacionales por puntaje" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
            {
                if(contador < 20)
                {
                    cin.ignore();

                    cout << "Nombre: ";
                    getline(cin, equipos[contador].nombre);

                    cout << "Institucion: ";
                    getline(cin, equipos[contador].institucion);

                    cout << "Categoria: ";
                    getline(cin, equipos[contador].categoria);

                    cout << "Puntaje: ";
                    cin >> equipos[contador].puntaje;

                    cin.ignore();

                    cout << "Pais: ";
                    getline(cin, equipos[contador].pais);

                    contador++;

                    cout << "Equipo registrado.\n";
                }
                else
                {
                    cout << "Vector lleno.\n";
                }

                break;
            }

            case 2:
            {
                cout << "\n=== EQUIPOS ===\n";

                for(int i = 0; i < contador; i++)
                {
                    cout << i + 1 << ". "
                         << equipos[i].nombre << " | "
                         << equipos[i].institucion << " | "
                         << equipos[i].categoria << " | "
                         << equipos[i].puntaje << " | "
                         << equipos[i].pais << endl;
                }

                break;
            }

            case 3:
            {
                for(int i = 0; i < contador - 1; i++)
                {
                    for(int j = i + 1; j < contador; j++)
                    {
                        if(equipos[i].puntaje < equipos[j].puntaje)
                        {
                            Equipo aux = equipos[i];
                            equipos[i] = equipos[j];
                            equipos[j] = aux;
                        }
                    }
                }

                cout << "Equipos ordenados.\n";

                break;
            }

            case 4:
            {
                if(contador > 0)
                {
                    Equipo mejor = equipos[0];
                    Equipo peor = equipos[0];

                    for(int i = 1; i < contador; i++)
                    {
                        if(equipos[i].puntaje > mejor.puntaje)
                        {
                            mejor = equipos[i];
                        }

                        if(equipos[i].puntaje < peor.puntaje)
                        {
                            peor = equipos[i];
                        }
                    }

                    cout << "\n=== MEJOR EQUIPO ===\n";
                    cout << mejor.nombre << " | "
                         << mejor.puntaje << endl;

                    cout << "\n=== PEOR EQUIPO ===\n";
                    cout << peor.nombre << " | "
                         << peor.puntaje << endl;
                }

                break;
            }

            case 5:
            {
                string buscar;

                cin.ignore();

                cout << "Ingrese pais: ";
                getline(cin, buscar);

                cout << "\n=== EQUIPOS DEL PAIS ===\n";

                for(int i = 0; i < contador; i++)
                {
                    if(equipos[i].pais == buscar)
                    {
                        cout << equipos[i].nombre << " | "
                             << equipos[i].puntaje << endl;
                    }
                }

                break;
            }

            case 6:
            {
                double minimo;
                int cantidad = 0;

                cout << "Puntaje minimo: ";
                cin >> minimo;

                for(int i = 0; i < contador; i++)
                {
                    if(equipos[i].pais == "Republica Dominicana"
                       && equipos[i].puntaje > minimo)
                    {
                        cantidad++;
                    }
                }

                cout << "Equipos nacionales mayores al puntaje: "
                     << cantidad << endl;

                break;
            }

            case 0:
            {
                cout << "Saliendo...\n";
                break;
            }

            default:
            {
                cout << "Opcion invalida.\n";
            }
        }

    } while(opcion != 0);

    return 0;
}