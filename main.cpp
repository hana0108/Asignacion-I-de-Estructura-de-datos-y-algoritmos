#include <iostream>
#include <string>

using namespace std;

class Estudiante
{
public:
    string nombre;
    string matricula;
    double calificaciones[5];
    double promedio;
    string estado;
};

int main()
{
    Estudiante estudiantes[20];
    int contador = 0;
    int opcion;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Mostrar aprobados" << endl;
        cout << "4. Ordenar por promedio" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
            {
                if(contador < 20)
                {
                    cin.ignore();

                    cout << "Nombre: ";
                    getline(cin, estudiantes[contador].nombre);

                    cout << "Matricula: ";
                    getline(cin, estudiantes[contador].matricula);

                    double suma = 0;

                    for(int i = 0; i < 5; i++)
                    {
                        cout << "Calificacion " << i + 1 << ": ";
                        cin >> estudiantes[contador].calificaciones[i];

                        suma += estudiantes[contador].calificaciones[i];
                    }

                    estudiantes[contador].promedio = suma / 5;

                    if(estudiantes[contador].promedio >= 70)
                    {
                        estudiantes[contador].estado = "Aprobado";
                    }
                    else
                    {
                        estudiantes[contador].estado = "Reprobado";
                    }

                    contador++;

                    cout << "Estudiante registrado.\n";
                }
                else
                {
                    cout << "Vector lleno.\n";
                }

                break;
            }

            case 2:
            {
                cout << "\n=== ESTUDIANTES ===\n";

                for(int i = 0; i < contador; i++)
                {
                    cout << "\nNombre: "
                         << estudiantes[i].nombre << endl;

                    cout << "Matricula: "
                         << estudiantes[i].matricula << endl;

                    cout << "Promedio: "
                         << estudiantes[i].promedio << endl;

                    cout << "Estado: "
                         << estudiantes[i].estado << endl;
                }

                break;
            }

            case 3:
            {
                cout << "\n=== ESTUDIANTES APROBADOS ===\n";

                for(int i = 0; i < contador; i++)
                {
                    if(estudiantes[i].promedio >= 70)
                    {
                        cout << estudiantes[i].nombre
                             << " | Promedio: "
                             << estudiantes[i].promedio
                             << endl;
                    }
                }

                break;
            }

            case 4:
            {
                for(int i = 0; i < contador - 1; i++)
                {
                    for(int j = i + 1; j < contador; j++)
                    {
                        if(estudiantes[i].promedio <
                           estudiantes[j].promedio)
                        {
                            Estudiante aux = estudiantes[i];
                            estudiantes[i] = estudiantes[j];
                            estudiantes[j] = aux;
                        }
                    }
                }

                cout << "Estudiantes ordenados.\n";

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