/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <limits>

using namespace std;

class Componente {
protected:
    string codigo;
    string nombre;
    double precioCosto;
    int cantidadExistencia;
    int stockMinimo;

public:
    Componente(string cod, string nom, double costo, int cant, int stockMin)
        : codigo(cod), nombre(nom), precioCosto(costo),
          cantidadExistencia(cant), stockMinimo(stockMin) {}

    virtual ~Componente() {}

    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    double getPrecioCosto() const { return precioCosto; }
    int getCantidadExistencia() const { return cantidadExistencia; }
    int getStockMinimo() const { return stockMinimo; }

    void setNombre(const string& nom) { nombre = nom; }
    void setPrecioCosto(double costo) { precioCosto = costo; }
    void setCantidadExistencia(int cant) { cantidadExistencia = cant; }
    void setStockMinimo(int stockMin) { stockMinimo = stockMin; }

    virtual double calcularPrecioVenta() const = 0;

    virtual void mostrar() const {
        cout << "Codigo: " << codigo
             << " | Nombre: " << nombre
             << " | Costo: $" << precioCosto
             << " | Existencia: " << cantidadExistencia
             << " | Stock minimo: " << stockMinimo;
    }
};

// ===================== NACIONAL =====================
class ComponenteNacional : public Componente {
private:
    string empresaProductora;

public:
    ComponenteNacional(string cod, string nom, double costo, int cant, int stockMin, string empresa)
        : Componente(cod, nom, costo, cant, stockMin), empresaProductora(empresa) {}

    void setEmpresaProductora(const string& empresa) {
        empresaProductora = empresa;
    }

    string getEmpresaProductora() const {
        return empresaProductora;
    }

    double calcularPrecioVenta() const {
        return precioCosto * 1.05;
    }

    void mostrar() const {
        Componente::mostrar();
        cout << " | Tipo: Nacional"
             << " | Empresa: " << empresaProductora
             << " | Venta (+5%): $" << calcularPrecioVenta()
             << endl;
    }
};

// ===================== IMPORTADO =====================
class ComponenteImportado : public Componente {
private:
    string paisProcedencia;
    double precioUSD;

public:
    ComponenteImportado(string cod, string nom, double costo, int cant, int stockMin,
                        string pais, double usd)
        : Componente(cod, nom, costo, cant, stockMin),
          paisProcedencia(pais), precioUSD(usd) {}

    void setPaisProcedencia(const string& pais) {
        paisProcedencia = pais;
    }

    void setPrecioUSD(double usd) {
        precioUSD = usd;
    }

    string getPaisProcedencia() const {
        return paisProcedencia;
    }

    double getPrecioUSD() const {
        return precioUSD;
    }

    double calcularPrecioVenta() const {
        return (precioCosto * 1.05) + (27 * precioUSD);
    }

    double calcularBase() const {
        return precioCosto * 1.05;
    }

    double calcularExtra() const {
        return 27 * precioUSD;
    }

    void mostrar() const {
        Componente::mostrar();

        cout << " | Tipo: Importado"
             << " | Pais: " << paisProcedencia
             << " | USD: $" << precioUSD
             << " | Venta base (+5%): $" << calcularBase()
             << " | Extra divisa: $" << calcularExtra()
             << " | Total venta: $" << calcularPrecioVenta()
             << endl;
    }
};

// ===================== ALMACEN =====================
class Almacen {
private:
    vector< unique_ptr<Componente> > inventario;

    Componente* buscarComponente(const string& cod) {
        for (size_t i = 0; i < inventario.size(); i++) {
            if (inventario[i]->getCodigo() == cod)
                return inventario[i].get();
        }
        return NULL;
    }

    void limpiarBuffer() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    void registrarComponente() {
        int tipo;
        string cod, nom;
        double costo;
        int cant, stockMin;

        cout << "Tipo (1 Nacional / 2 Importado): ";
        cin >> tipo;
        limpiarBuffer();

        cout << "Codigo: ";
        getline(cin, cod);

        if (buscarComponente(cod) != NULL) {
            cout << "Ya existe ese codigo.\n";
            return;
        }

        cout << "Nombre: ";
        getline(cin, nom);

        cout << "Costo: ";
        cin >> costo;

        cout << "Cantidad: ";
        cin >> cant;

        cout << "Stock minimo: ";
        cin >> stockMin;
        limpiarBuffer();

        if (tipo == 1) {
            string empresa;
            cout << "Empresa productora: ";
            getline(cin, empresa);

            inventario.push_back(
                unique_ptr<Componente>(
                    new ComponenteNacional(cod, nom, costo, cant, stockMin, empresa)
                )
            );
        }
        else {
            string pais;
            double usd;

            cout << "Pais: ";
            getline(cin, pais);

            cout << "Precio USD: ";
            cin >> usd;

            inventario.push_back(
                unique_ptr<Componente>(
                    new ComponenteImportado(cod, nom, costo, cant, stockMin, pais, usd)
                )
            );
        }

        cout << "Registrado correctamente.\n";
    }

    void modificarComponente() {
        string cod;

        cout << "Codigo: ";
        cin >> cod;
        limpiarBuffer();

        Componente* comp = buscarComponente(cod);

        if (!comp) {
            cout << "No encontrado.\n";
            return;
        }

        string nom;
        double costo;
        int cant, stockMin;

        cout << "Nuevo nombre: ";
        getline(cin, nom);

        cout << "Nuevo costo: ";
        cin >> costo;

        cout << "Nueva existencia: ";
        cin >> cant;

        cout << "Nuevo stock minimo: ";
        cin >> stockMin;
        limpiarBuffer();

        comp->setNombre(nom);
        comp->setPrecioCosto(costo);
        comp->setCantidadExistencia(cant);
        comp->setStockMinimo(stockMin);

        if (ComponenteNacional* nac = dynamic_cast<ComponenteNacional*>(comp)) {
            string empresa;
            cout << "Nueva empresa: ";
            getline(cin, empresa);
            nac->setEmpresaProductora(empresa);
        }

        if (ComponenteImportado* imp = dynamic_cast<ComponenteImportado*>(comp)) {
            string pais;
            double usd;

            cout << "Nuevo pais: ";
            getline(cin, pais);

            cout << "Nuevo USD: ";
            cin >> usd;

            imp->setPaisProcedencia(pais);
            imp->setPrecioUSD(usd);
        }

        cout << "Modificado correctamente.\n";
    }

    void listarNacionalesPorPrecio() {
        double limite;
        bool encontrado = false;

        cout << "Precio minimo: ";
        cin >> limite;

        for (size_t i = 0; i < inventario.size(); i++) {
            ComponenteNacional* nac =
                dynamic_cast<ComponenteNacional*>(inventario[i].get());

            if (nac && nac->calcularPrecioVenta() > limite) {
                nac->mostrar();
                encontrado = true;
            }
        }

        if (!encontrado)
            cout << "Sin resultados.\n";
    }

    void listarImportadosPorPais() {
        string pais;
        bool encontrado = false;

        limpiarBuffer();
        cout << "Pais: ";
        getline(cin, pais);

        for (size_t i = 0; i < inventario.size(); i++) {
            ComponenteImportado* imp =
                dynamic_cast<ComponenteImportado*>(inventario[i].get());

            if (imp && imp->getPaisProcedencia() == pais) {
                imp->mostrar();
                encontrado = true;
            }
        }

        if (!encontrado)
            cout << "Sin resultados.\n";
    }

    void detectarBajoStock() {
        bool encontrado = false;

        for (size_t i = 0; i < inventario.size(); i++) {
            if (inventario[i]->getCantidadExistencia() <
                inventario[i]->getStockMinimo()) {

                inventario[i]->mostrar();
                encontrado = true;
            }
        }

        if (!encontrado)
            cout << "Stock suficiente en todos.\n";
    }
};

// ===================== MAIN =====================
int main() {
    Almacen almacen;
    int opcion;

    do {
        cout << "\n===== ALMACEN =====\n";
        cout << "1. Registrar\n";
        cout << "2. Modificar\n";
        cout << "3. Nacionales por precio\n";
        cout << "4. Importados por pais\n";
        cout << "5. Bajo stock\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: almacen.registrarComponente(); break;
            case 2: almacen.modificarComponente(); break;
            case 3: almacen.listarNacionalesPorPrecio(); break;
            case 4: almacen.listarImportadosPorPais(); break;
            case 5: almacen.detectarBajoStock(); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}