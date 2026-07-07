/* UNIVERSIDAD NACIONAL AUTÓNOMA DE HONDURAS
FACULTAD DE CIENCIAS ECONÓMICAS, ADMINISTRATIVAS Y CONTABLES
DEPARTAMENTO DE INFORMÁTICA
DIA 044 Programación Básica
Proyecto: PUMA SUPER-MARKET
Grupo N°5
*/

#include <iostream> // PARA USAR std::cout, std::cin, std::endl
#include <string>  // PARA USAR std::string y getline()
#include <vector> // PARA USAR std::vector (VECTORES)
#include <iomanip> // PARA USAR std::fixed y std::setprecision()

using namespace std;

//  VECTORES GLOBALES DE PRODUCTOS

// Nombres de productos por área
vector<string> nombresVerduras = {"Tomates", "Repollo", "Papas"};
vector<string> nombresCarnes = {"Carne molida", "Carne de cerdo", "Carne para asar"};
vector<string> nombresLicores = {"Cerveza nacional", "Cerveza extranjera", "Vino", "Vodka"};

// Precios de productos por área
vector<double> preciosVerduras = {10.00, 15.00, 17.00};
vector<double> preciosCarnes = {50.00, 70.00, 75.00};
vector<double> preciosLicores = {50.00, 80.00, 200.00, 100.00};

// Unidades de medida por área
vector<string> unidadesVerduras = {"Libra", "Libra", "Libra"};
vector<string> unidadesCarnes = {"Libra", "Libra", "Libra"};
vector<string> unidadesLicores = {"Unidad", "Unidad", "Botella", "Botella"};

// Vector para tipos de cliente
vector<string> tiposCliente = {"Estrella", "Regular", "Nuevo"};

// Vector para días de la semana
vector<string> diasSemana = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

// Vectores para almacenar clientes nuevos registrados
vector<string> registroNombresClientes;
vector<int> registroEdadesClientes;
vector<int> registroTiposClientes;

// VECTORES DEL CARRITO DE COMPRAS
vector<string> carritoProductos;
vector<string> carritoAreas;
vector<string> carritoUnidades;
vector<double> carritoCantidades;
vector<double> carritoPreciosUnitarios;
vector<double> carritoSubtotales;

// FUNCIÓN: VALIDACIÓN DE EDAD PARA RESTRICCIÓN DE VENTA DE LICORES
// Parámetro por valor: edad
bool esMayorDeEdad(int edad) {
    return edad >= 18;
}

// FUNCIÓN: MOSTRAR BENEFICIOS POR TIPO DE CLIENTE
void mostrarBeneficiosTipoCliente(int tipoCliente) {
    cout << "\n=========================================================" << endl;
    cout << "         BENEFICIOS SEGUN SU TIPO DE CLIENTE             " << endl;
    cout << "=========================================================" << endl;

    switch (tipoCliente) {
        case 1:
            cout << " Usted es Cliente ESTRELLA. Sus beneficios:" << endl;
            cout << "   - 4% de descuento en Carnes y Verduras" << endl;
            break;
        case 2:
            cout << " Usted es Cliente REGULAR. Sus beneficios:" << endl;
            cout << "   - 3% de descuento en Carnes" << endl;
            break;
        case 3:
            cout << " Usted es Cliente NUEVO. Sus beneficios:" << endl;
            cout << "   - 2% de descuento en Licores" << endl;
            break;
    }
    cout << "=========================================================\n" << endl;
}

// FUNCIÓN: MOSTRAR DESCUENTOS EXTRAS DISPONIBLES
// Parámetros por valor: diaSemana, edadCliente
void mostrarDescuentosExtras(int diaSemana, int edadCliente) {
    cout << "=========================================================" << endl;
    cout << "           DESCUENTOS EXTRAS DISPONIBLES HOY             " << endl;
    cout << "=========================================================" << endl;

    // Descuento Lunes o Miércoles
    if (diaSemana == 1 || diaSemana == 3) {
        cout << " - Dia especial (Lunes/Miercoles):" << endl;
        cout << " +3% de descuento adicional" << endl;
    }

    // Descuento Viernes para adultos mayores
    if (diaSemana == 5 && edadCliente >= 65) {
        cout << " - Viernes de Adulto Mayor:" << endl;
        cout << " +10% de descuento adicional" << endl;
    }

    // Promociones siempre activas
    cout << " - Promocion en Carnes:" << endl;
    cout << " La segunda libra de carne al 50% de descuento" << endl;
    cout << " - Promocion en Cervezas:" << endl;
    cout << " Si lleva 6 o mas cervezas, descuento fijo de L.10.00" << endl;

    cout << "=========================================================\n" << endl;
}

// FUNCIÓN: REGISTRAR CLIENTE (Cambio #3 - registra cualquier tipo de cliente)
// Parámetros por valor: nombreCliente, edadCliente, tipoCliente
// Parámetros por referencia: vectores de registro
void registrarCliente(string nombreCliente, int edadCliente, int tipoCliente,
                      vector<string> &regNombres, vector<int> &regEdades, vector<int> &regTipos) {
    regNombres.push_back(nombreCliente);
    regEdades.push_back(edadCliente);
    regTipos.push_back(tipoCliente);

    cout << "\n=========================================================" << endl;
    cout << "            REGISTRO DE CLIENTE EXITOSO                  " << endl;
    cout << "=========================================================" << endl;
    cout << " Nombre   : " << nombreCliente << endl;
    cout << " Edad     : " << edadCliente << " anios" << endl;
    cout << " Tipo     : " << tiposCliente[tipoCliente - 1] << endl;
    cout << " Estado   : Registrado correctamente en el sistema" << endl;
    cout << "=========================================================" << endl;
    cout << " Total de clientes registrados: " << regNombres.size() << endl;
    cout << "=========================================================\n" << endl;
}

// FUNCIÓN: CAPTURA DE DATOS DEL CLIENTE CON VALIDACIONES
// Parámetros por referencia: nombreCliente, edadCliente, tipoCliente, diaSemana
void DatosCliente(string &nombreCliente, int &edadCliente, int &tipoCliente, int &diaSemana) {
    cout << "=========================================================" << endl;
    cout << "               REGISTRO DE CLIENTE                       " << endl;
    cout << "=========================================================" << endl;

    cout << "Por favor ingrese su nombre: ";
    getline(cin, nombreCliente);

    // VALIDACIÓN DE EDAD
    do {
        cout << "Ingrese su edad: ";
        cin >> edadCliente;
        if (edadCliente < 0 || edadCliente > 100) {
            cout << "Error: Edad no valida. Intente de nuevo.\n" << endl;
        }
    } while (edadCliente < 0 || edadCliente > 100);

    // MOSTRAR TIPOS DE CLIENTE USANDO VECTOR
    cout << "\nTipos de cliente disponibles:" << endl;
    for (int i = 0; i < (int)tiposCliente.size(); i++) {
        cout << "  " << (i + 1) << ". " << tiposCliente[i] << endl;
    }

    // VALIDACIÓN DEL TIPO DE CLIENTE
    do {
        cout << "Ingrese Tipo de Cliente (1-" << tiposCliente.size() << "): ";
        cin >> tipoCliente;
        if (tipoCliente < 1 || tipoCliente > (int)tiposCliente.size()) {
            cout << "Error: Tipo invalido. Intente de nuevo." << endl;
        }
    } while (tipoCliente < 1 || tipoCliente > (int)tiposCliente.size());

    // MOSTRAR BENEFICIOS DEL TIPO ELEGIDO INMEDIATAMENTE
    mostrarBeneficiosTipoCliente(tipoCliente);

    // MOSTRAR DÍAS DE LA SEMANA USANDO VECTOR
    cout << "\nDias de la semana:" << endl;
    for (int i = 0; i < (int)diasSemana.size(); i++) {
        cout << "  " << (i + 1) << ". " << diasSemana[i] << endl;
    }

    // VALIDACIÓN DEL DÍA DE LA SEMANA
    do {
        cout << "Ingrese el dia de hoy (1-" << diasSemana.size() << "): ";
        cin >> diaSemana;
        if (diaSemana < 1 || diaSemana > (int)diasSemana.size()) {
            cout << "Error: Dia no valido. Intente de nuevo." << endl;
        }
    } while (diaSemana < 1 || diaSemana > (int)diasSemana.size());

    // MOSTRAR DESCUENTOS EXTRAS SEGÚN DÍA ELEGIDO
    mostrarDescuentosExtras(diaSemana, edadCliente);
}

// FUNCIÓN: MENÚ PRINCIPAL CON VECTORES
void menuPrincipal() {
    int codigo = 1;

    cout << "=========================================================" << endl;
    cout << "             PUMA SUPER-MARKET - MENU DE AREAS           " << endl;
    cout << "=========================================================" << endl;

    // ÁREA DE VERDURAS (recorrido con vector)
    cout << " [ AREA DE VERDURAS ]" << endl;
    for (int i = 0; i < (int)nombresVerduras.size(); i++) {
        cout << "   " << codigo << ". " << nombresVerduras[i]
             << "  (L." << preciosVerduras[i]
             << " / " << unidadesVerduras[i] << ")" << endl;
        codigo++;
    }
    cout << "---------------------------------------------------------" << endl;

    // ÁREA DE CARNES (recorrido con vector)
    cout << " [ AREA DE CARNES ]" << endl;
    for (int i = 0; i < (int)nombresCarnes.size(); i++) {
        cout << "   " << codigo << ". " << nombresCarnes[i]
             << "  (L." << preciosCarnes[i]
             << " / " << unidadesCarnes[i] << ")" << endl;
        codigo++;
    }
    cout << "---------------------------------------------------------" << endl;

    // ÁREA DE LICORES (recorrido con vector)
    cout << " [ AREA DE LICORES ]" << endl;
    for (int i = 0; i < (int)nombresLicores.size(); i++) {
        cout << "   " << codigo << ". " << nombresLicores[i]
             << "  (L." << preciosLicores[i]
             << " / " << unidadesLicores[i] << ")" << endl;
        codigo++;
    }
    cout << "=========================================================" << endl;
}

// FUNCIÓN: OBTENER DATOS DEL PRODUCTO SEGÚN EL CÓDIGO
// Parámetros por valor: codigoProducto
// Parámetros por referencia: nombreProducto, precioUnitario, areaProducto, unidadMedida
bool obtenerDatosProducto(int codigoProducto, string &nombreProducto, double &precioUnitario,
    string &areaProducto, string &unidadMedida) {

    int limiteVerduras = nombresVerduras.size();
    int limiteCarnes = limiteVerduras + nombresCarnes.size();
    int limiteLicores = limiteCarnes + nombresLicores.size();

    // Determinar el área del producto según el código ingresado
    if (codigoProducto >= 1 && codigoProducto <= limiteVerduras) {
        int i = codigoProducto - 1;
        nombreProducto = nombresVerduras[i];
        precioUnitario = preciosVerduras[i];
        areaProducto = "Verduras";
        unidadMedida = unidadesVerduras[i];
        return true;
    }
    else if (codigoProducto > limiteVerduras && codigoProducto <= limiteCarnes) {
        int i = codigoProducto - limiteVerduras - 1;
        nombreProducto = nombresCarnes[i];
        precioUnitario = preciosCarnes[i];
        areaProducto = "Carnes";
        unidadMedida = unidadesCarnes[i];
        return true;
    }
    else if (codigoProducto > limiteCarnes && codigoProducto <= limiteLicores) {
        int i = codigoProducto - limiteCarnes - 1;
        nombreProducto = nombresLicores[i];
        precioUnitario = preciosLicores[i];
        areaProducto = "Licores";
        unidadMedida = unidadesLicores[i];
        return true;
    }

    return false;
}

// FUNCIÓN: CONTROL DEL BUCLE DE COMPRA
// Parámetros por referencia: continuarCompra
// Parámetro por valor: nombreCliente, edadCliente
void controlBucleCompra(const string &nombreCliente, int edadCliente, char &continuarCompra,
    double &subtotalGeneral) {
    int totalProductos = nombresVerduras.size() + nombresCarnes.size() + nombresLicores.size();
    int codigoProducto;

    string nombreProducto, areaProducto, unidadMedida;
    double precioUnitario = 0.0;
    double cantidad = 0.0;
    double subtotalBase = 0.0;

    cout << "Bienvenido/a " << nombreCliente << " a PUMA SUPER-MARKET!" << endl;
    if (!esMayorDeEdad(edadCliente)) {
        cout << "* NOTA: Al ser menor de 18 anios, el area de licores estara bloqueada. *" << endl;
    }
    cout << "---------------------------------------------------------" << endl;

    menuPrincipal();
    cout << "\nIngrese el Codigo del producto que desea llevar (1-" << totalProductos << "): ";
    cin >> codigoProducto;

    if (codigoProducto < 1 || codigoProducto > totalProductos) {
        cout << "=> Error: Codigo de producto inexistente." << endl;
    }
    else if (codigoProducto > (int)(nombresVerduras.size() + nombresCarnes.size()) && !esMayorDeEdad(edadCliente)) {
        cout << "\n[ RESTRICCION DE EDAD ]" << endl;
        cout << "=> Error: Venta prohibida. Usted es menor de edad y no puede comprar licores.\n" << endl;
    }
    else {
        if (obtenerDatosProducto(codigoProducto, nombreProducto, precioUnitario, areaProducto, unidadMedida)) {

            cout << "\n=========================================================" << endl;
            cout << "               PRODUCTO SELECCIONADO                     " << endl;
            cout << "=========================================================" << endl;
            cout << " Codigo         : " << codigoProducto << endl;
            cout << " Producto       : " << nombreProducto << endl;
            cout << " Area           : " << areaProducto << endl;
            cout << " Precio Unitario: L. " << fixed << setprecision(2) << precioUnitario << endl;
            cout << " Unidad Medida  : " << unidadMedida << endl;
            cout << "=========================================================" << endl;

            do {
                if (unidadMedida == "Libra") {
                    cout << "Ingrese la cantidad de libras que desea comprar: ";
                }
                else if (unidadMedida == "Unidad") {
                    cout << "Ingrese la cantidad de unidades que desea comprar: ";
                }
                else if (unidadMedida == "Botella") {
                    cout << "Ingrese la cantidad de botellas que desea comprar: ";
                }

                cin >> cantidad;

                if (cantidad <= 0) {
                    cout << "Error: La cantidad debe ser mayor que 0. Intente de nuevo.\n";
                }

            } while (cantidad <= 0);

            subtotalBase = cantidad * precioUnitario;

            carritoProductos.push_back(nombreProducto);
            carritoAreas.push_back(areaProducto);
            carritoUnidades.push_back(unidadMedida);
            carritoCantidades.push_back(cantidad);
            carritoPreciosUnitarios.push_back(precioUnitario);
            carritoSubtotales.push_back(subtotalBase);

            subtotalGeneral += subtotalBase;

            cout << "\n=========================================================" << endl;
            cout << "               PRODUCTO AGREGADO AL CARRITO             " << endl;
            cout << "=========================================================" << endl;
            cout << " Producto        : " << nombreProducto << endl;
            cout << " Cantidad        : " << cantidad << " " << unidadMedida;
            if (cantidad != 1) {
                if (unidadMedida == "Libra") cout << "s";
                else if (unidadMedida == "Unidad") cout << "es";
                else if (unidadMedida == "Botella") cout << "s";
            }
            cout << endl;
            cout << " Precio Unitario : L. " << fixed << setprecision(2) << precioUnitario << endl;
            cout << " Subtotal Artic. : L. " << fixed << setprecision(2) << subtotalBase << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << " Subtotal Compra : L. " << fixed << setprecision(2) << subtotalGeneral << endl;
            cout << "=========================================================" << endl;
        }
    }

    do {
        cout << "\nDesea seguir agregando productos al carrito? (s/n): ";
        cin >> continuarCompra;
        if (continuarCompra != 's' && continuarCompra != 'S' &&
            continuarCompra != 'n' && continuarCompra != 'N') {
            cout << "Error: Opcion no valida. Ingrese 's' o 'n'." << endl;
        }
    } while (continuarCompra != 's' && continuarCompra != 'S' &&
             continuarCompra != 'n' && continuarCompra != 'N');
    cout << endl;
}

// FUNCIÓN PRINCIPAL
int main() {

    char otroCliente = 's';

    do {
        string nombreCliente;
        int edadCliente = 0;
        int tipoCliente = 0;
        int diaSemana = 0;
        char continuarCompra = 's';
        double subtotalGeneral = 0.0;

        DatosCliente(nombreCliente, edadCliente, tipoCliente, diaSemana);

        registrarCliente(nombreCliente, edadCliente, tipoCliente,
                         registroNombresClientes, registroEdadesClientes, registroTiposClientes);

        // LIMPIAR CARRITO PARA EL NUEVO CLIENTE
        carritoProductos.clear();
        carritoAreas.clear();
        carritoUnidades.clear();
        carritoCantidades.clear();
        carritoPreciosUnitarios.clear();
        carritoSubtotales.clear();

        do {
            controlBucleCompra(nombreCliente, edadCliente, continuarCompra, subtotalGeneral);
        } while (continuarCompra == 's' || continuarCompra == 'S');

        cout << "\n=========================================================" << endl;
        cout << "                 RESUMEN DE LA COMPRA                    " << endl;
        cout << "=========================================================" << endl;

        for (int i = 0; i < (int)carritoProductos.size(); i++) {
            cout << i + 1 << ". " << carritoProductos[i]
                 << " | Area: " << carritoAreas[i]
                 << " | Cantidad: " << carritoCantidades[i] << " " << carritoUnidades[i]
                 << " | P.Unit: L. " << fixed << setprecision(2) << carritoPreciosUnitarios[i]
                 << " | Subtotal: L. " << carritoSubtotales[i] << endl;
        }

        cout << "---------------------------------------------------------" << endl;
        cout << " SUBTOTAL GENERAL DE LA COMPRA: L. " << fixed << setprecision(2) << subtotalGeneral << endl;
        cout << "=========================================================" << endl;

        cout << "\nGracias por su compra, " << nombreCliente << "!" << endl;

        do {
            cout << "\n=========================================================" << endl;
            cout << "  Desea atender a otro cliente? (s/n): ";
            cin >> otroCliente;
            if (otroCliente != 's' && otroCliente != 'S' && otroCliente != 'n' && otroCliente != 'N') {
                cout << "  Error: Opcion no valida. Ingrese 's' o 'n'." << endl;
            }
        } while (otroCliente != 's' && otroCliente != 'S' && otroCliente != 'n' && otroCliente != 'N');
        cin.ignore();
        cout << "=========================================================\n" << endl;

    } while (otroCliente == 's' || otroCliente == 'S');

    cout << "\n=========================================================" << endl;
    cout << "       RESUMEN DE CLIENTES ATENDIDOS EN ESTA SESION      " << endl;
    cout << "=========================================================" << endl;
    cout << " Total de clientes: " << registroNombresClientes.size() << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < (int)registroNombresClientes.size(); i++) {
        cout << "  " << (i + 1) << ". " << registroNombresClientes[i]
             << " | Edad: " << registroEdadesClientes[i]
             << " | Tipo: " << tiposCliente[registroTiposClientes[i] - 1] << endl;
    }
    cout << "=========================================================" << endl;
    cout << "  Gracias por usar PUMA SUPER-MARKET. Hasta pronto!" << endl;
    cout << "=========================================================\n" << endl;

    return 0;
}