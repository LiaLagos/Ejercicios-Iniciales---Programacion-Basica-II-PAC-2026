#include <iostream>
#include <string>

using namespace std;
// DEFINIR E INICIALIZAR VARIABLES
// variables tipo string
string nombreCliente;
string tipoCliente;
string areaProduto; 

// variables tipo int
int edadCliente;
int Nfact;
int codigoProducto;
int diaSemana;
int cantidadProducto;

// variables tipo float
float precioProducto;
float subtotalProducto;
float descuentoCliente;
float descuentoDia;
float descuentoTerceraEdad;
float descuentoSixPack;
float totalDescuentoProducto;
float netoPorProducto;
float isvProducto;
float totalLempiras;
float totalDolares;

int main() {
    do
    {
        cout << " | °.- SUPERMERCADO PUMA-SUPERMARKET -.° |"
        cout << "\n | Bienvenido al sistema del Supermercado Puma-Supermarket |" << endl;
        // DATOS GENERALES DEL CLIENTE
        for (int Nfact = 0; Nfact < 1; Nfact++)
        {
            cout << "Numero de factura: " << Nfact << endl;
        }
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, nombreCliente); // Leer el nombre completo del cliente
        cout << "Ingrese la edad del cliente: ";
        cin >> edadCliente; // Leer la edad del cliente

        // validar la edad del cliente (0 a 100 años)
        while (edadCliente < 0 || edadCliente >= 100)
        {
            cout << "ERROR: Edad no valida. Por favor, ingrese una edad validad." << endl;
            cout << "Ingrese la edad del cliente: ";
            cin >> edadCliente;
        }
        cout << "Ingrese el Tipo de Cliente (Estrella, Regular, Nuevo):";
        cin >> tipoCliente; // Leer el tipo de cliente

        // validar el tipo de cliente (Estrella, Regular, Nuevo)
        while (tipoCliente != "Estrella" && tipoCliente != "Regular" && tipoCliente != "Nuevo")
        {
            cout << "ERROR: Tipo de cliente no valido. Por favor, ingrese Estrella, Regular o Nuevo." << endl;
            cout << "Ingrese el Tipo de Cliente (Estrella, Regular, Nuevo):";
            cin >> tipoCliente;
        }

        cout << " | Seleccione el dia de la Semana | \n1. Lunes \n2. Martes \n3. Miercoles \n4. Jueves \n5. Viernes \n6. Sabado \n7. Domingo" << endl;
        cin >> diaSemana; // Leer el dia de la semana
        // validar el dia de la semana (1 a 7)
        while (diaSemana < 1 || diaSemana > 7)
        {
            cout << "ERROR: Dia de la semana no valido. Por favor, ingrese un numero entre 1 y 7." << endl;
            cout << " | Seleccione el dia de la Semana | \n1. Lunes \n2. Martes \n3. Miercoles \n4. Jueves \n5. Viernes \n6. Sabado \n7. Domingo" << endl;
            cin >> diaSemana;
        }
    }
}