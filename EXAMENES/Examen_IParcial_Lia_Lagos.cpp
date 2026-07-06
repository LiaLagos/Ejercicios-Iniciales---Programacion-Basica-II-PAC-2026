// Nombre: Lia Samira Lagos Palacios
// N°Cuenta: 20251002446
// Examen I Parcial

#include <iostream>
#include <string>

using namespace std;

// hacer case(switch) para cada producto (CODIGO), con su precio y puntos, y una función para mostrar el menú de productos

void catalogo(int codigoproducto, string &nombreprouducto, string &categoria, double &precio, int &puntos)
{
    switch (codigoproducto)
    {
    case 1:
        nombreprouducto = "Puma A55";
        categoria = "Celulares";
        precio = 6800;
        puntos = 120;
        break;

    case 2:
        nombreprouducto = "Puma i13";
        categoria = "Celulares";
        precio = 19500;
        puntos = 250;
        break;

    case 3:
        nombreprouducto = "Puma Mini";
        categoria = "Celulares";
        precio = 1800;
        puntos = 60;
        break;

    case 4:
        nombreprouducto = "PumaBook 15";
        categoria = "Computadoras";
        precio = 18900;
        puntos = 220;
        break;

    case 5:
        nombreprouducto = "PumaGamer X";
        categoria = "Computadoras";
        precio = 32500;
        puntos = 350;
        break;

    case 6:
        nombreprouducto = "PumaDesk";
        categoria = "Computadoras";
        precio = 14800;
        puntos = 180;
        break;

    case 7:
        nombreprouducto = "PumaTab";
        categoria = "Tablets";
        precio = 7900;
        puntos = 140;
        break;

    case 8:
        nombreprouducto = "PumaPad Air";
        categoria = "Tablets";
        precio = 16500;
        puntos = 230;
        break;

    case 9:
        nombreprouducto = "PumaPrint";
        categoria = "Tablets";
        precio = 4500;
        puntos = 90;
        break;

    case 10:
        nombreprouducto = "Audifonos Bluetooth";
        categoria = "Accesorios";
        precio = 650;
        puntos = 25;
        break;

    case 11:
        nombreprouducto = "Mouse Inalambrico";
        categoria = "Accesorios";
        precio = 350;
        puntos = 15;
        break;

    case 12:
        nombreprouducto = "Teclado Mecanico";
        categoria = "Accesorios";
        precio = 1250;
        puntos = 45;
        break;
    }
}

int main()
{
    // INVENTARIO DE CADA UNO DE LOS 12 PRODUCTOS

    int inv1 = 18;
    int inv2 = 8;
    int inv3 = 20;
    int inv4 = 10;
    int inv5 = 6;
    int inv6 = 7;
    int inv7 = 12;
    int inv8 = 6;
    int inv9 = 9;
    int inv10 = 30;
    int inv11 = 40;
    int inv12 = 15;

    // ESTADISTICAS

    int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0;
    int v7 = 0, v8 = 0, v9 = 0, v10 = 0, v11 = 0, v12 = 0;

    double ganCelulares = 0;
    double ganComputadoras = 0;
    double ganTablets = 0;
    double ganAccesorios = 0;

    double totalDescuentosDia = 0;
    double totalISVDia = 0;
    double totalVentasDia = 0;

    int pagoEfectivo = 0;
    int pagoTransferencia = 0;

    char continuar = 'S';

    while (continuar == 'S' || continuar == 's')

    {
        int tipoCliente;
        char genero;
        int edad;

        double subtotal = 0;
        double descuentos = 0;
        int puntosCliente = 0;

        bool llevaCelular = false;
        bool llevaAudifonos = false;
        bool llevaLaptopGamer = false;
        bool llevaTeclado = false;

        cout << "               °.- PUMA TECH STORY - BIENVENIDO -.°        " << endl;
        cout << "=========================================================" << endl;
        cout << "Ingrese su nombre: ";
        string nombreCliente;
        cin.ignore();
        getline(cin, nombreCliente);
        cout << "=============================================================" << endl;

        do
        {
            cout << "\n INGRESE EL TIPO DE CLIENTE";
            cout << "\n1. Estudiante";
            cout << "\n2. Profesional";
            cout << "\n3. Corporativo";
            cout << "\nOpcion: ";
            cin >> tipoCliente;
            if (tipoCliente < 1 || tipoCliente > 3)
            {
                cout << "Opcion invalida. Intente de nuevo." << endl;
                continue;
            }
        } while (tipoCliente < 1 || tipoCliente > 3);

        do
        {
            cout << "INGRESAR SU GENERO O SEXO: (M/F):";
            cin >> genero;
            if (genero != 'M' && genero != 'F' && genero != 'm' && genero != 'f')
            {
                cout << "Error: Opción inválida. Intente de nuevo.\n"
                     << endl;
            }
        } while (genero != 'M' && genero != 'F' && genero != 'm' && genero != 'f');

        do
        {
            cout << "INGRESE SU EDAD: ";
            cin >> edad;
            if (edad < 0 || edad > 100)
            {
                cout << "Error: Edad no válida. Intente de nuevo.\n"
                     << endl;
            }
        } while (edad < 0 || edad > 100);

        int codigo;

        do
        {
            cout << "           |°.-TIENDA DE TECNOLOGÍA “PUMA TECH STORE”-°.|           " << endl;
            cout << "AREA#1: Celulares" << endl;
            cout << " 1. Smartphone Android “PumaA55--------------------------L. 6,800.00”" << endl;
            cout << " 2. iPhone “Puma i13”------------------------------------L. 19,500.00”" << endl;
            cout << " 3. Celular básico “Puma Mini”---------------------------L. 1,800.00”" << endl;
            cout << "AREA#2: Laptops Y Computadoras" << endl;
            cout << " 4. Laptop i5 “PumaBook 15”------------------------------L. 18,900.00”" << endl;
            cout << " 5. Laptop Gamer “PumaGamer X”---------------------------L. 32,500.00”" << endl;
            cout << " 6. PC Escritorio “PumaDesk”-----------------------------L. 14,800.00”" << endl;
            cout << "AREA#3: Tablets Y Equipos" << endl;
            cout << " 7. Tablet 10” “PumaTab”---------------------------------L. 7,900.00”" << endl;
            cout << " 8. iPad “PumaPad Air” ---------------------------------L. 16,500.00”" << endl;
            cout << " 9. Impresora WiFi “PumaPrint”---------------------------L. 4,500.00”" << endl;
            cout << "AREA#4: Accesorios" << endl;
            cout << "10. Audífonos Bluetooth----------------------------------L. 650.00”" << endl;
            cout << "11. Mouse inalámbrico-----------------------------------L. 350.00”" << endl;
            cout << "12. Teclado mecánico------------------------------------L. 1,250.00”" << endl;
            cout << "=========================================================" << endl;

            cout << "\n INGRESE UN: Codigo producto (1-12)";
            cin >> codigo;
            cout << "\n ¿DESEA FINALIZAR LA COMPRA? INGRESE:0 ";
            cin >> codigo;

            if (codigo == 0)
                break;

            string nombre, categoria;
            double precio;
            int puntos;

            catalogo(codigo, nombre, categoria, precio, puntos);

            int cantidad;

            cout << "Cantidad: ";
            cin >> cantidad;

            int stock = 0;

            switch (codigo)
            {
            case 1:
                stock = inv1;
                break;
            case 2:
                stock = inv2;
                break;
            case 3:
                stock = inv3;
                break;
            case 4:
                stock = inv4;
                break;
            case 5:
                stock = inv5;
                break;
            case 6:
                stock = inv6;
                break;
            case 7:
                stock = inv7;
                break;
            case 8:
                stock = inv8;
                break;
            case 9:
                stock = inv9;
                break;
            case 10:
                stock = inv10;
                break;
            case 11:
                stock = inv11;
                break;
            case 12:
                stock = inv12;
                break;
            }

            if (cantidad > stock)
            {
                cout << "¡Stock insuficiente!\n";
                continue;
            }

            double subtotalProducto = precio * cantidad;
            double desc = 0;

            // Tipo cliente

            if (tipoCliente == 1 && categoria == "Accesorios")
                desc += subtotalProducto * 0.08;

            if (tipoCliente == 2 && categoria == "Computadoras")
                desc += subtotalProducto * 0.10;

            if (tipoCliente == 3 && categoria == "Tablets")
                desc += subtotalProducto * 0.12;

            // Genero

            if (genero == 'F' && categoria == "Accesorios")
                desc += subtotalProducto * 0.10;

            if (genero == 'M' && categoria == "Computadoras")
                desc += subtotalProducto * 0.05;

            // Tercera edad

            if (edad >= 60)
                desc += subtotalProducto * 0.10;

            // Volumen accesorios

            if (categoria == "Accesorios" && cantidad > 3)
                desc += subtotalProducto * 0.04;

            subtotal += subtotalProducto;
            descuentos += desc;

            puntosCliente += (puntos * cantidad);

            if (categoria == "Celulares")
                ganCelulares += (subtotalProducto - desc);

            if (categoria == "Computadoras")
                ganComputadoras += (subtotalProducto - desc);

            if (categoria == "Tablets")
                ganTablets += (subtotalProducto - desc);

            if (categoria == "Accesorios")
                ganAccesorios += (subtotalProducto - desc);

            switch (codigo)
            {
            case 1:
                inv1 -= cantidad;
                v1 += cantidad;
                llevaCelular = true;
                break;
            case 2:
                inv2 -= cantidad;
                v2 += cantidad;
                llevaCelular = true;
                break;
            case 3:
                inv3 -= cantidad;
                v3 += cantidad;
                llevaCelular = true;
                break;
            case 4:
                inv4 -= cantidad;
                v4 += cantidad;
                break;
            case 5:
                inv5 -= cantidad;
                v5 += cantidad;
                llevaLaptopGamer = true;
                break;
            case 6:
                inv6 -= cantidad;
                v6 += cantidad;
                break;
            case 7:
                inv7 -= cantidad;
                v7 += cantidad;
                break;
            case 8:
                inv8 -= cantidad;
                v8 += cantidad;
                break;
            case 9:
                inv9 -= cantidad;
                v9 += cantidad;
                break;
            case 10:
                inv10 -= cantidad;
                v10 += cantidad;
                llevaAudifonos = true;
                break;
            case 11:
                inv11 -= cantidad;
                v11 += cantidad;
                break;
            case 12:
                inv12 -= cantidad;
                v12 += cantidad;
                llevaTeclado = true;
                break;
            }

        } while (true);

        // PROMOCIONES

        if (llevaLaptopGamer && llevaTeclado)
        {
            descuentos += subtotal * 0.07;
        }

        if (llevaCelular && llevaAudifonos)
        {
            descuentos += 325;
        }

        double subtotalFinal = subtotal - descuentos;
        double isv = subtotalFinal * 0.15;
        double total = subtotalFinal + isv;

        cout << "\nFACTURA DE PUMA TECH STORE";
        cout << "\n=============================";
        cout << "\nSubtotal:                              L. " << subtotal;
        cout << "\nDescuentos:                            L. " << descuentos;
        cout << "\nISV:                                   L. " << isv;
        cout << "\nTotal:                                 L. " << total;
        cout << "\nUSD:                                   L. " << total / 26.42;
        cout << "\nPuntos:                                L. " << puntosCliente;

        totalDescuentosDia += descuentos;
        totalISVDia += isv;
        totalVentasDia += total;
        int metodo;

        cout << "\nINGRESE METODO DE PAGO";
        cout << "\n1. Efectivo";
        cout << "\n2. Transferencia";
        cout << "\nOpcion: ";
        cin >> metodo;

        if (metodo == 1)
        {
            double recibido;

            cout << "Monto recibido: ";
            cin >> recibido;

            cout << "Cambio: " << recibido - total;

            pagoEfectivo++;
        }
        else
        {
            string referencia;
            string bancoOrigen;
            string bancoDestino;

            cout << "Referencia: ";
            cin >> referencia;

            cout << "Banco origen: ";
            cin >> bancoOrigen;

            cout << "Banco destino: ";
            cin >> bancoDestino;

            pagoTransferencia++;
        }

        cout << "\nDesea ingresar otro cliente (S/N): ";
        cin >> continuar;
    }

    cout << "\n\n===== ESTADISTICAS DEL DIA =====";

    cout << "\nGanancia Celulares: " << ganCelulares;
    cout << "\nGanancia Computadoras: " << ganComputadoras;
    cout << "\nGanancia Tablets: " << ganTablets;
    cout << "\nGanancia Accesorios: " << ganAccesorios;

    cout << "\nTotal descuentos: " << totalDescuentosDia;
    cout << "\nTotal ISV: " << totalISVDia;
    cout << "\nTotal vendido Lps: " << totalVentasDia;
    cout << "\nTotal vendido USD: " << totalVentasDia / 26.42;

    if (pagoEfectivo > pagoTransferencia)
        cout << "\nMetodo mas utilizado: Efectivo";

    else if (pagoTransferencia > pagoEfectivo)
        cout << "\nMetodo mas utilizado: Transferencia";

    else
        cout << "\nEmpate en metodos de pago";

    return 0;
}
