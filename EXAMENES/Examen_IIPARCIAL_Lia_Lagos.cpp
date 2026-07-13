// Nombre: Lia Samira Lagos Palacios
// N°Cuenta: 20251002446
// Examen II Parcial
// Examen 2 PUMA TECH STORE

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //libreria para limpiar la pantalla
#include <iomanip>
#include <fstream>

using namespace std;

// declaracion de vectores globales de la tienda
// nombres de productos
vector<string> nombrescelulares = {"Smartphone Android - Puma A55", "Iphone- Puma il3", "Celular Basico - Puma Mini"};
vector<string> nombreslaptopsCompus = {"Laptop i5 -PumaBook 15", "Laptop Gamer - PumaGamerX", "PC Escritorio - PumaDesk"};
vector<string> nombrestabletsEquip = {"Tablet 10 - PumaTab", "iPad - PumaPad Air", "Impresora WIFI - PumaPrint"};
vector<string> nombresAccesorios = {"Audifonos Bluetooth", "Mouse Inalambrico", "Teclado mecanico"};

// precios de productos por area
vector<double> precioCelulares = {6800.00, 19500.00, 1800.00};
vector<double> precioLaptopsCompus = {18900.00, 32500.00, 14800.00};
vector<double> precioTabletsEquip = {7900.00, 16500.00, 4500.00};
vector<double> precioAccesorios = {650.00, 350.00, 1250.00};

// vectores de inventario de productos por area
vector<int> inventarioCelulares = {18, 8, 20};
vector<int> inventarioLaptopsCompus = {10, 6, 7};
vector<int> inventarioTabletsEquip = {12, 6, 9};
vector<int> inventarioAccesorios = {30, 40, 15};

// vectores para los puntos de los clientes
vector<int> puntosCelulares = {120, 250, 60};
vector<int> puntosLaptopsCompus = {220, 350, 180};
vector<int> puntosTabletsEquip = {140, 230, 90};
vector<int> puntosAccesorios = {25, 15, 45};

// vectores generales :p
vector<string> TipoCliente = {"Estudiante ", "Profesional", "Corporativo"};
vector<int> registroTiposClientes;
vector<string> registroNombresClientes;
vector<int> registroEdadesClientes;
vector<string> registroSexosClientes;
vector<int> carritoPuntos;
//================ ESTADISTICAS ==================
vector<int> cantidadVendidaProducto(12, 0);
vector<double> ingresoProducto(12, 0);
vector<double> descuentoProducto(12, 0);

// Ganancias por categoría
double ganCelulares = 0;
double ganComputadoras = 0;
double ganTablets = 0;
double ganAccesorios = 0;

// Totales del día
double totalDescuentosDia = 0;
double totalISVDia = 0;
double totalVentasDia = 0;
double totalVentasUSD = 0;

// Puntos
int totalPuntosGenerados = 0;
int totalPuntosCanjeados = 0;

// Métodos de pago
int pagoEfectivo = 0;
int pagoTransferencia = 0;
int pagoTarjeta = 0;

// Financieros
double totalRecargosTarjeta = 0;
double totalDescuentosFinancieros = 0;

// VECTORES DEL CARRITO DE COMPRAS
vector<string> carritoProductos;
vector<string> carritoAreas;
vector<string> carritoUnidades;
vector<double> carritoCantidades;
vector<double> carritoPreciosUnitarios;
vector<double> carritoSubtotales;

// funciones
void pausa();
void limpiarPantalla();

void pausa()
{ // Función para pausar la ejecución del programa y esperar a que el usuario presione ENTER
    cout << "\nPresione ENTER para continuar" << endl;
    cin.ignore(1000, '\n');
    cin.get(); // el cin.get() es un método para pausar la ejecución del programa hasta que el usuario presione la tecla ENTER.
    // Esto permite al usuario leer los mensajes en pantalla antes de continuar con el programa.
}

// ===== FUNCION PARA LIMPIAR PANTALLA =====
void limpiarPantalla()
{
    system("cls"); // Si usas otro compilador diferente a Windows, puede ser system("clear");
}

// TODOS LOS DESCUENTOS
// funcion de descuentos por tipo sexo del cliente y edad del cliente

bool esMayorDeEdad(int edad)
{
    return edad >= 18;
}

void calculosDescuentos(double subtotalProducto, double &descuentoTipoCliente, double &descuentoSexo,
                        double &descuentoEdad, int tipoCliente, char sexoCliente, int edadCliente, string categoria)
{
    // Descuento por tipo de client
    if (tipoCliente == 1 && categoria == "Accesorios")
    {
        descuentoTipoCliente += subtotalProducto * 0.08;
    }
    else if (tipoCliente == 2 && categoria == "Computadoras")
    {
        descuentoTipoCliente += subtotalProducto * 0.10;
    }
    else if (tipoCliente == 3 && categoria == "Tablets")
    {
        descuentoTipoCliente += subtotalProducto * 0.12;
    }

    // Descuento por sexo del cliente
    if ((sexoCliente == 'F' || sexoCliente == 'f') && categoria == "Accesorios")
    {
        descuentoSexo += subtotalProducto * 0.10;
    }
    else if ((sexoCliente == 'M' || sexoCliente == 'm') && categoria == "Computadoras")
    {
        descuentoSexo += subtotalProducto * 0.05;
    }

    // Descuento por tercera edad
    if (edadCliente >= 60)
    {
        descuentoEdad += subtotalProducto * 0.10;
    }
}

// funcion descuentos segun promociones especiales
void mostrarBeneficiosPromociones(int codigoProducto, int cantidad, double &descuentoPromocion)
{
    // Promoción 1: Combo Gaming (Laptop Gamer + Teclado Mecánico)
    if ((codigoProducto == 5 && cantidad >= 1) || (codigoProducto == 12 && cantidad >= 1))
    {
        descuentoPromocion += 0.15; // 15% de descuento en ambos productos
    }

    // Promoción 2: Más de 3 unidades del mismo accesorio
    if ((codigoProducto == 10 || codigoProducto == 11 || codigoProducto == 12) && cantidad > 3)
    {
        descuentoPromocion += 0.10; // 10% de descuento en el accesorio
    }

    // Promoción 3: Compra de Celular + Audífonos
    if ((codigoProducto == 1 || codigoProducto == 2 || codigoProducto == 3) && cantidad >= 1)
    {
        descuentoPromocion += 0.05; // 5% de descuento en los audífonos
    }

    if ((codigoProducto == 6 || codigoProducto == 9) && cantidad >= 1)
    {
        descuentoPromocion += 0.06;
    }
}

// DATOS DE CLIENTES
// funcion para registrar clientes
void registrarCliente(string nombreCliente, int edadCliente, int tipoCliente, string sexoCliente,
                      vector<string> &regNombres, vector<int> &regEdades, vector<int> &regTipos, vector<string> &regSexos)
{
    regNombres.push_back(nombreCliente);
    regEdades.push_back(edadCliente);
    regTipos.push_back(tipoCliente);
    regSexos.push_back(sexoCliente);

    cout << "=========================================================" << endl;
    cout << "            REGISTRO DE CLIENTE EXITOSO                  " << endl;
    cout << "=========================================================" << endl;
    cout << " Nombre   : " << nombreCliente << endl;
    cout << " Edad     : " << edadCliente << endl;
    cout << " Sexo     : " << sexoCliente << endl;
    cout << " Tipo     : " << TipoCliente[tipoCliente - 1] << endl;
    cout << " Estado   : Registrado correctamente en el sistema" << endl;
    cout << "=========================================================" << endl;
    cout << " Total de clientes registrados: " << regNombres.size() << endl;
    cout << "=========================================================\n"
         << endl;
}

void DatosCliente(string &nombreCliente, int &edadCliente, int &tipoCliente, char &sexoCliente)
{
    cout << "=========================================================" << endl;
    cout << " ============ BIENVENIDO A PUMA TECH STORE ==============" << endl;
    cout << "                   REGISTRO DE CLIENTE                       " << endl;
    cout << "=========================================================" << endl;

    cout << "Por favor ingrese su nombre:";
    getline(cin, nombreCliente);

    // VALIDACIÓN DE EDAD
    do
    {
        cout << "Ingrese su edad: ";
        cin >> edadCliente;
        if (edadCliente < 0 || edadCliente > 100)
        {
            cout << "Error: Edad no valida. Intente de nuevo.\n"
                 << endl;
        }
        if (edadCliente >= 60)
        {
            cout << "   - 10% de descuento en todos los productos" << endl;
        }
    } while (edadCliente < 0 || edadCliente > 100);

    // VALIDACIÓN DEL SEXO
    do
    {
        cout << "Ingrese su sexo (M/F): ";
        cin >> sexoCliente;
        if (sexoCliente != 'M' && sexoCliente != 'F' && sexoCliente != 'm' && sexoCliente != 'f')
        {
            cout << "Error: Sexo no valido. Intente de nuevo.\n"
                 << endl;
        }
        if (sexoCliente == 'M' || sexoCliente == 'm')
        {
            cout << "   - 10% de descuento en Accesorios" << endl;
        }
        else if (sexoCliente == 'F' || sexoCliente == 'f')
        {
            cout << "   - 5% de descuento en Laptops y Computadoras" << endl;
        }
    } while (sexoCliente != 'M' && sexoCliente != 'F' && sexoCliente != 'm' && sexoCliente != 'f');

    // MOSTRAR TIPOS DE CLIENTE USANDO VECTOR
    cout << "\nTipos de cliente disponibles:" << endl;
    for (int i = 0; i < (int)TipoCliente.size(); i++)
    {
        cout << "  " << (i + 1) << ". " << TipoCliente[i] << endl;
    }

    // VALIDACIÓN DEL TIPO DE CLIENTE
    do
    {
        cout << "Ingrese Tipo de Cliente (1-" << TipoCliente.size() << "): ";
        cin >> tipoCliente;
        if (tipoCliente < 1 || tipoCliente > (int)TipoCliente.size())
        {
            cout << "Error: Tipo invalido. Intente de nuevo." << endl;
        }
        if (tipoCliente == 1)
        {
            cout << "   - 8% de descuento en Accesorios" << endl;
        }
        else if (tipoCliente == 2)
        {
            cout << "   - 10% de descuento en Laptops y Computadoras" << endl;
        }
        else if (tipoCliente == 3)
        {
            cout << "   - 12% de descuento en Tablets y Equipos" << endl;
        }
    } while (tipoCliente < 1 || tipoCliente > (int)TipoCliente.size());

    pausa();
    limpiarPantalla();
}

// PRODUCTOS AREAS, PRECIOS Y MENUS
// FUNCION: MENU PRINCIPAL CON VECTORES
void menuPrincipal()
{
    pausa();
    int codigo = 1;

    cout << "\n";
    cout << "==============================================================" << endl;
    cout << "                 P U M A   T E C H   S T O R E                " << endl;
    cout << "==============================================================" << endl;
    cout << "                 CATALOGO GENERAL DE PRODUCTOS                " << endl;
    cout << "==============================================================" << endl;

    cout << "\n--------------- AREA DE CELULARES ----------------------------" << endl;
    for (size_t i = 0; i < nombrescelulares.size(); i++)
    {
        cout << setw(2) << codigo++ << ". "
             << left << setw(30) << nombrescelulares[i]
             << "L. " << right << fixed << setprecision(2)
             << precioCelulares[i] << endl;
    }

    cout << "\n------------- AREA DE COMPUTADORAS ---------------------------" << endl;
    for (size_t i = 0; i < nombreslaptopsCompus.size(); i++)
    {
        cout << setw(2) << codigo++ << ". "
             << left << setw(30) << nombreslaptopsCompus[i]
             << "L. " << right << fixed << setprecision(2)
             << precioLaptopsCompus[i] << endl;
    }

    cout << "\n----------- AREA DE TABLETS Y EQUIPOS ------------------------" << endl;
    for (size_t i = 0; i < nombrestabletsEquip.size(); i++)
    {
        cout << setw(2) << codigo++ << ". "
             << left << setw(30) << nombrestabletsEquip[i]
             << "L. " << right << fixed << setprecision(2)
             << precioTabletsEquip[i] << endl;
    }

    cout << "\n---------------- AREA DE ACCESORIOS --------------------------" << endl;
    for (size_t i = 0; i < nombresAccesorios.size(); i++)
    {
        cout << setw(2) << codigo++ << ". "
             << left << setw(30) << nombresAccesorios[i]
             << "L. " << right << fixed << setprecision(2)
             << precioAccesorios[i] << endl;
    }

    cout << "==============================================================" << endl;
}

// FUNCIÓN: OBTENER DATOS DEL PRODUCTO SEGÚN EL CÓDIGO
// Parámetros por valor: codigoProducto
// Parámetros por referencia
bool obtenerDatosProducto(int codigoProducto, string &nombreProducto, double &precioUnitario,
                          string &areaProducto, int &stockDisponible, int &puntosProducto)
{

    int limiteCelulares = nombrescelulares.size();
    int limiteComputadoras = limiteCelulares + nombreslaptopsCompus.size();
    int limiteTablets = limiteComputadoras + nombrestabletsEquip.size();
    int limiteAccesorios = limiteTablets + nombresAccesorios.size();

    if (codigoProducto >= 1 && codigoProducto <= 3)
    {
        int i = codigoProducto - 1;
        nombreProducto = nombrescelulares[i];
        precioUnitario = precioCelulares[i];
        areaProducto = "Celulares";
        stockDisponible = inventarioCelulares[i];
        puntosProducto = puntosCelulares[i];
        return true;
    }
    else if (codigoProducto >= 4 && codigoProducto <= 6)
    {
        int i = codigoProducto - 4;
        nombreProducto = nombreslaptopsCompus[i];
        precioUnitario = precioLaptopsCompus[i];
        areaProducto = "Computadoras";
        stockDisponible = inventarioLaptopsCompus[i];
        puntosProducto = puntosLaptopsCompus[i];
        return true;
    }
    else if (codigoProducto >= 7 && codigoProducto <= 9)
    {
        int i = codigoProducto - 7;
        nombreProducto = nombrestabletsEquip[i];
        precioUnitario = precioTabletsEquip[i];
        areaProducto = "Tablets";
        stockDisponible = inventarioTabletsEquip[i];
        puntosProducto = puntosTabletsEquip[i];
        return true;
    }
    else if (codigoProducto >= 10 && codigoProducto <= 12)
    {
        int i = codigoProducto - 10;
        nombreProducto = nombresAccesorios[i];
        precioUnitario = precioAccesorios[i];
        areaProducto = "Accesorios";
        stockDisponible = inventarioAccesorios[i];
        puntosProducto = puntosAccesorios[i];
        return true;
    }

    return false; // Código de producto inválido
}

void actualizarInventario(int codigoProducto, int cantidadcomprada)
{
    if (codigoProducto >= 1 && codigoProducto <= 3)
    {
        inventarioCelulares[codigoProducto - 1] -= cantidadcomprada;
    }
    else if (codigoProducto >= 4 && codigoProducto <= 6)
    {
        inventarioLaptopsCompus[codigoProducto - 4] -= cantidadcomprada;
    }
    else if (codigoProducto >= 7 && codigoProducto <= 9)
    {
        inventarioTabletsEquip[codigoProducto - 7] -= cantidadcomprada;
    }
    else if (codigoProducto >= 10 && codigoProducto <= 12)
    {
        inventarioAccesorios[codigoProducto - 10] -= cantidadcomprada;
    }
}

void actualizarPuntosCliente(int puntosProducto, int cantidadcomprada, int &puntosCliente)
{
    puntosCliente += puntosProducto * cantidadcomprada;
}

void descuentoCompraMayor(double subtotal, int categorias, double &descuento)
{
    if (subtotal >= 10000)
        descuento += subtotal * 0.04;

    else if (subtotal >= 5000)
        descuento += subtotal * 0.02;

    if (categorias >= 3)
        descuento += subtotal * 0.03;
}

int contarCategorias()
{
    bool celular = false;
    bool computadora = false;
    bool tablet = false;
    bool accesorio = false;

    for (int i = 0; i < carritoAreas.size(); i++)
    {
        if (carritoAreas[i] == "Celulares")
            celular = true;

        else if (carritoAreas[i] == "Computadoras")
            computadora = true;

        else if (carritoAreas[i] == "Tablets")
            tablet = true;

        else if (carritoAreas[i] == "Accesorios")
            accesorio = true;
    }

    int total = 0;

    if (celular)
        total++;
    if (computadora)
        total++;
    if (tablet)
        total++;
    if (accesorio)
        total++;

    return total;
}

double canjearPuntos(int &puntosCliente)
{
    double descuento = 0;

    if (puntosCliente >= 300)
    {
        descuento = 200;
        puntosCliente -= 300;
        totalPuntosCanjeados += 300;
    }
    else if (puntosCliente >= 200)
    {
        descuento = 120;
        puntosCliente -= 200;
        totalPuntosCanjeados += 200;
    }
    else if (puntosCliente >= 100)
    {
        descuento = 50;
        puntosCliente -= 100;
        totalPuntosCanjeados += 100;
    }

    return descuento;
}

void controlBucleCompra(const string &nombreCliente, char &continuarCompra, double &subtotalGeneral, int &puntosCliente)
{
    int totalProductos = nombrescelulares.size() + nombreslaptopsCompus.size() + nombrestabletsEquip.size() + nombresAccesorios.size();
    int codigoProducto;

    string nombreProducto, areaProducto;
    ;
    string unidad = "unidades"; // Unidad de medida por defecto
    int stockDisponible;
    int puntosProducto;
    double precioUnitario;
    double cantidad;
    double subtotalBase;
    double descuentoPromocion;

    cout << "Bienvenido/a " << nombreCliente << " a PUMA TECH STORE!" << endl;

    menuPrincipal();
    cout << "\nIngrese el Codigo del producto que desea llevar (1-" << totalProductos << "): ";
    cin >> codigoProducto;

    if (codigoProducto < 1 || codigoProducto > totalProductos)
    {
        cout << "=> Error: Codigo de producto inexistente." << endl;
    }
    else
    {
        if (obtenerDatosProducto(codigoProducto, nombreProducto, precioUnitario, areaProducto, stockDisponible, puntosProducto))
        {

            cout << "\n=========================================================" << endl;
            cout << "               PRODUCTO SELECCIONADO                     " << endl;
            cout << "=========================================================" << endl;
            cout << " Codigo         : " << codigoProducto << endl;
            cout << " Producto       : " << nombreProducto << endl;
            cout << " Inventario      : " << stockDisponible << endl;
            cout << " Puntos         : " << puntosProducto << endl;
            cout << " Area           : " << areaProducto << endl;
            cout << " Precio Unitario: L. " << fixed << setprecision(2) << precioUnitario << endl;
            cout << "=========================================================" << endl;

            do
            {
                cout << "Ingrese la cantidad que desea llevar: ";
                cin >> cantidad;

                if (cantidad <= 0)
                {
                    cout << "Error: La cantidad debe ser mayor que 0. Intente de nuevo.\n";
                }

            } while (cantidad <= 0);

            if (cantidad > stockDisponible)
            {
                cout << "\n=============================" << endl;
                cout << "       STOCK INSUFICIENTE    " << endl;
                cout << "=============================" << endl;
                cout << "Disponible: " << stockDisponible << endl;
                return; // Salir de la función si no hay suficiente stock
            }

            if (cantidad == 0)
            {
                cout << "\n=============================" << endl;
                cout << "       PRODUCTO AGOTADO    " << endl;
                cout << "=============================" << endl;
                return;
            }

            mostrarBeneficiosPromociones(codigoProducto, cantidad, descuentoPromocion);
            actualizarInventario(codigoProducto, cantidad);
            actualizarPuntosCliente(puntosProducto, cantidad, puntosCliente);

            subtotalBase = cantidad * precioUnitario;

            cantidadVendidaProducto[codigoProducto - 1] += cantidad;
            ingresoProducto[codigoProducto - 1] += subtotalBase;

            totalPuntosGenerados += puntosProducto * cantidad;

            if (areaProducto == "Celulares")
                ganCelulares += subtotalBase;

            else if (areaProducto == "Computadoras")
                ganComputadoras += subtotalBase;

            else if (areaProducto == "Tablets")
                ganTablets += subtotalBase;

            else if (areaProducto == "Accesorios")
                ganAccesorios += subtotalBase;

            carritoProductos.push_back(nombreProducto);
            carritoAreas.push_back(areaProducto);
            carritoCantidades.push_back(cantidad);
            carritoPreciosUnitarios.push_back(precioUnitario);
            carritoSubtotales.push_back(subtotalBase);
            carritoPuntos.push_back(puntosProducto * cantidad);

            subtotalGeneral += subtotalBase;

            cout << "\n=========================================================" << endl;
            cout << "               PRODUCTO AGREGADO AL CARRITO             " << endl;
            cout << "=========================================================" << endl;
            cout << " Producto        : " << nombreProducto << endl;
            cout << " Cantidad        : " << cantidad << " " << unidad;
            if (cantidad != 1)
            {
                cout << "";
            }
            cout << endl;
            cout << " Precio Unitario : L. " << fixed << setprecision(2) << precioUnitario << endl;
            cout << " Subtotal Artic. : L. " << fixed << setprecision(2) << subtotalBase << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << " Subtotal Compra : L. " << fixed << setprecision(2) << subtotalGeneral << endl;
            cout << "=========================================================" << endl;
        }
    }

    do
    {
        cout << "\nDesea seguir agregando productos al carrito? (s/n): ";
        cin >> continuarCompra;
        if (continuarCompra != 's' && continuarCompra != 'S' &&
            continuarCompra != 'n' && continuarCompra != 'N')
        {
            cout << "Error: Opcion no valida. Ingrese 's' o 'n'." << endl;
        }
    } while (continuarCompra != 's' && continuarCompra != 'S' &&
             continuarCompra != 'n' && continuarCompra != 'N');
    cout << endl;
}

void mostrarEstadisticas()
{
    vector<string> productos;

    productos.insert(productos.end(), nombrescelulares.begin(), nombrescelulares.end());
    productos.insert(productos.end(), nombreslaptopsCompus.begin(), nombreslaptopsCompus.end());
    productos.insert(productos.end(), nombrestabletsEquip.begin(), nombrestabletsEquip.end());
    productos.insert(productos.end(), nombresAccesorios.begin(), nombresAccesorios.end());

    int masVendido = 0;
    int menosVendido = 0;
    int mayorIngreso = 0;
    int mayorDescuento = 0;
    int menorInventario = 0;

    int menorInv = 999999;

    for (int i = 0; i < 12; i++)
    {
        if (cantidadVendidaProducto[i] > cantidadVendidaProducto[masVendido])
            masVendido = i;

        if (cantidadVendidaProducto[i] < cantidadVendidaProducto[menosVendido])
            menosVendido = i;

        if (ingresoProducto[i] > ingresoProducto[mayorIngreso])
            mayorIngreso = i;

        if (descuentoProducto[i] > descuentoProducto[mayorDescuento])
            mayorDescuento = i;
    }

    vector<int> inventarioFinal;

    // EL .INSERT modifica el vector añade uno varios elementos, desplaza los elementos etc
    // el .end es para que apunte al ultimo elemento es como una señal de alto
    // .begin este es para el primer valor o elemento
    inventarioFinal.insert(inventarioFinal.end(), inventarioCelulares.begin(), inventarioCelulares.end());
    inventarioFinal.insert(inventarioFinal.end(), inventarioLaptopsCompus.begin(), inventarioLaptopsCompus.end());
    inventarioFinal.insert(inventarioFinal.end(), inventarioTabletsEquip.begin(), inventarioTabletsEquip.end());
    inventarioFinal.insert(inventarioFinal.end(), inventarioAccesorios.begin(), inventarioAccesorios.end());

    for (int i = 0; i < 12; i++)
    {
        if (inventarioFinal[i] < menorInv)
        {
            menorInv = inventarioFinal[i];
            menorInventario = i;
        }
    }

    cout << "\n==============================================";
    cout << "\n      ESTADISTICAS DEL DIA";
    cout << "\n==============================================";

    cout << "\nProducto mas vendido: " << productos[masVendido];

    cout << "\nProducto menos vendido: " << productos[menosVendido];

    cout << "\nGanancia Celulares: L. " << ganCelulares;

    cout << "\nGanancia Computadoras: L. " << ganComputadoras;

    cout << "\nGanancia Tablets: L. " << ganTablets;

    cout << "\nGanancia Accesorios: L. " << ganAccesorios;

    cout << "\nTotal descuentos: L. " << totalDescuentosDia;

    cout << "\nTotal ISV: L. " << totalISVDia;

    cout << "\nTotal vendido: L. " << totalVentasDia;

    cout << "\nTotal vendido USD: $ " << totalVentasUSD;

    cout << "\nProducto mayor ingreso: " << productos[mayorIngreso];

    cout << "\nProducto mayor descuento: " << productos[mayorDescuento];

    cout << "\nProducto menor inventario: " << productos[menorInventario];

    cout << "\nTotal puntos generados: " << totalPuntosGenerados;

    cout << "\nTotal puntos canjeados: " << totalPuntosCanjeados;

    cout << "\nRecargos tarjeta: L. " << totalRecargosTarjeta;

    cout << "\nDescuentos financieros: L. " << totalDescuentosFinancieros;

    cout << "\nMetodo de pago mas utilizado: ";

    if (pagoEfectivo >= pagoTransferencia && pagoEfectivo >= pagoTarjeta)
        cout << "Efectivo";

    else if (pagoTransferencia >= pagoTarjeta)
        cout << "Transferencia";

    else
        cout << "Tarjeta";

    cout << "\n==============================================\n";
}

void exportarTXT()
{
    ofstream archivo("Estadisticas_PumaTechStore.txt");

    archivo << "========== ESTADISTICAS DEL DIA ==========\n\n";

    archivo << "Ganancia Celulares: " << ganCelulares << endl;
    archivo << "Ganancia Computadoras: " << ganComputadoras << endl;
    archivo << "Ganancia Tablets: " << ganTablets << endl;
    archivo << "Ganancia Accesorios: " << ganAccesorios << endl;

    archivo << "Total descuentos: " << totalDescuentosDia << endl;
    archivo << "Total ISV: " << totalISVDia << endl;

    archivo << "Total ventas Lempiras: " << totalVentasDia << endl;
    archivo << "Total ventas USD: " << totalVentasUSD << endl;

    archivo << "Puntos generados: " << totalPuntosGenerados << endl;
    archivo << "Puntos canjeados: " << totalPuntosCanjeados << endl;

    archivo << "Recargos tarjeta: " << totalRecargosTarjeta << endl;

    archivo << "Descuentos financieros: " << totalDescuentosFinancieros << endl;

    archivo << "====================================";

    archivo.close();
}
// FUNCION PRINCIPAL

int main()
{

    // Variables para el control del flujo de clientes
    char otroCliente = 'S';

    // Variables para estadísticas del día
    double totalDescuentosDia = 0.0;
    double totalISVDia = 0.0;
    double totalVentasDia = 0.0;
    double ganCelulares = 0.0, ganComputadoras = 0.0, ganTablets = 0.0, ganAccesorios = 0.0;

    do
    {
        // Variables para el registro de clientes
        string nombreCliente;
        int edadCliente;
        int tipoCliente;
        char sexoCliente;
        int puntosCliente = 0;
        int metodo;

        char continuarCompra = 'S';

        double subtotalGeneral = 0.0;
        double descuentoTipoCliente = 0.0;
        double descuentoSexo = 0.0;
        double descuentoEdad = 0.0;
        double descuentoPromocion = 0.0;
        double descuentoTotal = 0.0;
        double subtotalConDescuento = 0.0;
        double impuestoISV = 0.0;
        double totalPagar = 0.0;
        double totalUSD = 0.0;

        DatosCliente(nombreCliente, edadCliente, tipoCliente, sexoCliente);

        registrarCliente(nombreCliente, edadCliente, tipoCliente, string(1, sexoCliente), registroNombresClientes, registroEdadesClientes, registroTiposClientes, registroSexosClientes);

        // LIMPIAR CARRITO PARA EL NUEVO CLIENTE
        carritoProductos.clear();
        carritoAreas.clear();
        carritoUnidades.clear();
        carritoCantidades.clear();
        carritoPreciosUnitarios.clear();
        carritoSubtotales.clear();
        carritoPuntos.clear();

        do
        {
            controlBucleCompra(nombreCliente, continuarCompra, subtotalGeneral, puntosCliente);
        } while (continuarCompra == 's' || continuarCompra == 'S');

        for (int i = 0; i < (int)carritoSubtotales.size(); i++)
        {
            calculosDescuentos(carritoSubtotales[i], descuentoTipoCliente, descuentoSexo,
                               descuentoEdad, tipoCliente, sexoCliente, edadCliente, carritoAreas[i]);
        }

        //===========================================
        // DESCUENTO POR COMPRA MAYOR
        //===========================================

        int categorias = contarCategorias();

        descuentoCompraMayor(subtotalGeneral, categorias, descuentoPromocion);

        subtotalConDescuento = subtotalGeneral - descuentoTotal;
        if
        (subtotalConDescuento < 0)
        subtotalConDescuento = 0;
            
        double descuentoCanje = canjearPuntos(puntosCliente);
        descuentoTotal = descuentoTipoCliente + descuentoSexo + descuentoEdad + descuentoPromocion + descuentoCanje;
        impuestoISV = subtotalConDescuento * 0.15;

        totalPagar = subtotalConDescuento + impuestoISV;

        totalUSD = totalPagar / 24.42;

        cout << "\n=========================================================" << endl;
        cout << "                  PUMA TECH STORE                         " << endl;
        cout << "                  FACTURA DE COMPRA                      " << endl;
        cout << "=========================================================" << endl;

        cout << "Cliente        : " << nombreCliente << endl;
        cout << "Edad           : " << edadCliente << " anios" << endl;
        cout << "Sexo           : " << sexoCliente << endl;
        cout << "Tipo Cliente   : " << TipoCliente[tipoCliente - 1] << endl;
        cout << "=========================================================" << endl;

        cout << left
             << setw(4) << "#"
             << setw(35) << "Producto"
             << setw(18) << "Area"
             << setw(10) << "Cant."
             << setw(14) << "Precio"
             << setw(12) << "Puntos"
             << setw(14) << "Subtotal"
             << endl;

        cout << "--------------------------------------------------------"
             << "---------------------------" << endl;

        for (int i = 0; i < (int)carritoProductos.size(); i++)
        {
            cout << left
                 << setw(4) << i + 1
                 << setw(35) << carritoProductos[i]
                 << setw(18) << carritoAreas[i]
                 << setw(10) << carritoCantidades[i]
                 << setw(14) << fixed << setprecision(2) << carritoPreciosUnitarios[i]
                 << setw(12) << carritoPuntos[i]
                 << setw(14) << carritoSubtotales[i]
                 << endl;
        }

        cout << "=========================================================" << endl;

        cout << "Subtotal General............... L. " << subtotalGeneral << endl;

        cout << "\n----------- DESCUENTOS ----------------" << endl;
        cout << "Descuento Tipo Cliente......... L. " << descuentoTipoCliente << endl;
        cout << "Descuento por Sexo............. L. " << descuentoSexo << endl;
        cout << "Descuento por Edad............. L. " << descuentoEdad << endl;
        cout << "Promociones Especiales......... L. " << descuentoPromocion << endl;
        cout << "---------------------------------------" << endl;
        cout << "Descuento Total................ L. " << descuentoTotal << endl;

        cout << "\nSubtotal con Descuento......... L. " << subtotalConDescuento << endl;

        cout << "ISV (15%)...................... L. " << impuestoISV << endl;

        cout << "TOTAL A PAGAR.................. L. " << totalPagar << endl;

        cout << "TOTAL EN DOLARES............... $ " << totalUSD << endl;

        cout << "Puntos generados......... " << totalPuntosGenerados << endl;
        cout << "Puntos disponibles....... " << puntosCliente << endl;

        cout << "Canje de puntos.............. L. " << descuentoCanje << endl;

        do
        {
            cout << "\n=========================";
            cout << "\n  INGRESE METODO DE PAGO ";
            cout << "\n=========================";
            cout << "\n1. Efectivo";
            cout << "\n2. Transferencia";
            cout << "\n3. Tarjeta de credito";
            cout << "\nOpcion: ";

            cin >> metodo;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nError. Solo se permiten numeros.\n";
                metodo = 0;
            }

        } while (metodo < 1 || metodo > 3);

        if (metodo == 1)
        {
            // EFECTIVO
            double recibido;

            do
            {
                cout << "\nMonto recibido: L. ";
                cin >> recibido;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Error. Ingrese un monto valido.\n";
                    recibido = -1;
                }
                else if (recibido < totalPagar)
                {
                    cout << "El monto ingresado es insuficiente.\n";
                }

            } while (recibido < totalPagar);

            cout << "\nCambio: L. " << recibido - totalPagar << endl;

            pagoEfectivo++;
        }
        else if (metodo == 2)
        {
            // TRANSFERENCIA
            string referencia;
            string bancoOrigen;
            string bancoDestino;

            cout << "\nNumero de referencia: ";
            cin >> referencia;

            cout << "Banco origen: ";
            cin.ignore();
            getline(cin, bancoOrigen);

            cout << "Banco destino: ";
            getline(cin, bancoDestino);

            cout << "\nTransferencia registrada correctamente.\n";

            pagoTransferencia++;
        }
        else if (metodo == 3)
        {
            // TARJETA DE CREDITO
            string numeroTarjeta;
            string banco;
            int cuotas;

            do
            {
                cout << "\nNumero de tarjeta: ";
                cin >> numeroTarjeta;

                if (numeroTarjeta.length() < 13 || numeroTarjeta.length() > 19)
                {
                    cout << "Numero de tarjeta invalido. (SIN ESPACIOS NUMUEROS DISPONIBLES DEL 13 A 19) \n";
                }

            } while (numeroTarjeta.length() < 13 || numeroTarjeta.length() > 19);

            cout << "Banco emisor: ";
            cin.ignore();
            getline(cin, banco);

            do
            {
                cout << "Cantidad de cuotas: ";
                cin >> cuotas;

                double recargo = totalPagar * 0.03;

                totalPagar += recargo;

                totalRecargosTarjeta += recargo;

                cout << "\nRecargo por tarjeta (3%): L. "
                     << fixed << setprecision(2)
                     << recargo << endl;

                cout << "Nuevo total: L. " << totalPagar << endl;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Ingrese un numero valido.\n";
                    cuotas = 0;
                }
                else if (cuotas < 1)
                {
                    cout << "Las cuotas deben ser mayores que 0.\n";
                }

            } while (cuotas < 1);

            cout << "\nPago con tarjeta procesado correctamente.\n";

            pagoTarjeta++;
        }

        cout << "=========================================================" << endl;
        cout << "      ¡GRACIAS POR COMPRAR EN PUMA TECH STORE!           " << endl;
        cout << "=========================================================" << endl;

        cout << "\nDesea ingresar otro cliente (S/N): ";
        cin >> otroCliente;
    } while (otroCliente == 's' || otroCliente == 'S');

    for (int i = 0; i < carritoProductos.size(); i++)
    {
        if (carritoAreas[i] == "Celulares")
            ganCelulares += carritoSubtotales[i];

        else if (carritoAreas[i] == "Computadoras")
            ganComputadoras += carritoSubtotales[i];

        else if (carritoAreas[i] == "Tablets")
            ganTablets += carritoSubtotales[i];

        else if (carritoAreas[i] == "Accesorios")
            ganAccesorios += carritoSubtotales[i];
    }


    mostrarEstadisticas();

    char descargar;

    cout << "\nDesea guardar las estadisticas en un archivo TXT? (S/N): ";
    cin >> descargar;

    if (descargar == 'S' || descargar == 's')
    {
        exportarTXT();

        cout << "\nArchivo generado correctamente.";
        cout << "\nNombre: Estadisticas_PumaTechStore.txt\n";
    }

    return 0;
}