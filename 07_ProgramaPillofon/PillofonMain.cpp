#include <iostream>
#include <string>
#include <limits>
 
using namespace std;
 
// DEFINIR E INICIALIZAR VARIABLES
string nombreEmpleado;
int edadEmpleado;
int tipoEmpleado;    // 1. Tiempo completo, 2. Medio tiempo, 3. Por contrato
char generoEmpleado; // M. Masculino, F. Femenino
double sueldoMensualEmpleado;
float horasDiariasLV; // Horas diarias de lunes a viernes
float horasSabado;    // Horas de sabado
 
// VARIABLES DE LA TABLA DE EXCEL
float horassemanalesEmpleadoPlanta;
float horasMensualesEmpleadoPlanta;
float horasMensualesEmpleadoMedioTiempo; // Para la opción 2
float horassemanalesEmpleadoMedioTiempo;
float horasMensualesEmpleadoContrato; // Para la opción 3
float horassemanalesEmpleadoContrato;
 
float horasTotalesTrabajadas; // La variable general del reporte
 
// Variables del Reporte Final (Dinero)
float sueldoHora;
float SueldodariolV;
float SueldoSabados;
float SueldoMinuto;
float SueldoSegundo;
float SueldoSemanalLV;
float SueldoSemanalLS;
float SueldoQuincenal;
int respuesta; // Variable para controlar la repetición del programa
 
int main(){
 
do
{
    /* code */


        cout << "PILLOFON S.A. DE C.V." << endl;
        cout << "Bienvenido al sistema de calculo de sueldo por hora" << endl;
        // DATOS GENERALES DEL EMPLEADO
        cout << "Ingrese el nombre del empleado: ";
        getline(cin, nombreEmpleado); // Leer el nombre completo del empleado
        cout << "Ingrese la edad del empleado: ";
        cin >> edadEmpleado; // Leer la edad del empleado
        // validar la edad del empleado (18 a 70 años)
        while (edadEmpleado < 18 || edadEmpleado > 70)
        {
            cout << "Edad no valida. Por favor, ingrese una edad entre 18 y 70 años." << endl;
            cout << "Ingrese la edad del empleado: ";
            cin >> edadEmpleado;
        }
        cout << "Ingrese el genero del empleado (M. Masculino, F. Femenino): ";
 
        cin >> generoEmpleado; // Leer el genero del empleado
 
        // validar el genero del empleado (M o F)
 
        while (generoEmpleado != 'M' && generoEmpleado != 'm' && generoEmpleado != 'F' && generoEmpleado != 'f')
        {
            cout << "Genero no valido. Por favor, ingrese M o F." << endl;
            cout << "Ingrese el genero del empleado (M. Masculino, F. Femenino): ";
            cin >> generoEmpleado;
        }
        // ingresar el sueldo mensual del empleado
 
        cout << "Ingrese el sueldo mensual del empleado: ";
 
        cin >> sueldoMensualEmpleado; // Leer el sueldo mensual del empleado
 
        // validar que sea mayor a 16,0000.00
 
        while (sueldoMensualEmpleado < 16000.00)
        {
            cout << "Sueldo mensual no valido. Por favor, ingrese un sueldo mayor a 16,000.00." << endl;
            cout << "Ingrese el sueldo mensual del empleado: ";
            cin >> sueldoMensualEmpleado;
        }
        cout << "Ingrese el tipo de empleado (1. Empleado de Planta, 2. Medio tiempo, 3. Por contrato): ";
        cin >> tipoEmpleado; // Leer el tipo de empleado
        // validar el tipo de empleado (1, 2 o 3)
        while (tipoEmpleado < 1 || tipoEmpleado > 3)
        {
            cout << "Tipo de empleado no valido. Por favor, ingrese 1, 2 o 3." << endl;
            cout << "Ingrese el tipo de empleado (1. Empleado de Planta, 2. Medio tiempo, 3. Por contrato): ";
            cin >> tipoEmpleado;
        }
 
        switch (tipoEmpleado)
        {
 
        case 1: // Empleado de Planta
            cout << "Empleado de Planta" << endl;
            // Se definen las horas restando de forma directa la hora de almuerzo
            horasDiariasLV = 9.5; // Jornada de 10.5 horas en la empresa - 1 hora de almuerzo
            horasSabado = 6.0;    // Jornada de 7.0 horas en la empresa - 1 hora de almuerzo
 
            // Multiplicamos los 5 días de la semana (L a V) y le sumamos el total del sábado
            horassemanalesEmpleadoPlanta = (horasDiariasLV * 5) + horasSabado;
 
            // Proyección mensual basada en la regla de las 4 semanas fijas
            horasMensualesEmpleadoPlanta = horassemanalesEmpleadoPlanta * 4;
 
            // Se carga el resultado final en nuestra variable general para habilitar el reporte
            horasTotalesTrabajadas = horasMensualesEmpleadoPlanta;
            break;
 
        case 2: // Medio tiempo
            cout << "Empleado de Medio Tiempo" << endl;
            // Trabaja de Lunes a Sábado en horario continuo
            horasDiariasLV = 5.5; // Jornada de 6.5 horas - 1 hora de almuerzo
            horasSabado = 5.5;    // Jornada de 6.5 horas - 1 hora de almuerzo (Mismo horario que entre semana)
 
            // Se totaliza la semana multiplicando directamente por los 6 días laborables
            horassemanalesEmpleadoMedioTiempo = horasDiariasLV * 6;
 
            // Cálculo mensual aplicando el factor de las 4 semanas
            horasMensualesEmpleadoMedioTiempo = horassemanalesEmpleadoMedioTiempo * 4;
 
            // Se transfiere el valor obtenido a la variable unificada del reporte
            horasTotalesTrabajadas = horasMensualesEmpleadoMedioTiempo;
            break;
 
        case 3: // Por contrato
            cout << "Empleado por Contrato" << endl;
            // Solicitud de las horas semanales acordadas en su respectivo contrato
            cout << "Ingrese las horas semanales del empleado por contrato (Entre 30 y 40): ";
            cin >> horassemanalesEmpleadoContrato;
 
            // Validación de Rango: Asegura el cumplimiento de la Regla N° 3 de la guía de la empresa
            while (horassemanalesEmpleadoContrato < 30 || horassemanalesEmpleadoContrato > 40)
            {
                cout << "ERROR: horas fuera de rango permitido" << endl;
                cout << "Ingrese las horas semanales del empleado por contrato (Entre 30 y 40): ";
                cin >> horassemanalesEmpleadoContrato;
            }
 
            // Multiplicación directa por 4 semanas para obtener el acumulado del mes
            horasMensualesEmpleadoContrato = horassemanalesEmpleadoContrato * 4;
 
            // Se direcciona el dato al embudo general del sistema
            horasTotalesTrabajadas = horasMensualesEmpleadoContrato;
 
            // Inicializamos los días en 0 ya que esta modalidad no mide marcas de reloj individuales por día
            horasDiariasLV = 0;
            horasSabado = 0;
            break;
 
        default:
            cout << "Tipo de empleado no valido." << endl;
            break;
        }
        // Este segmento procesa el dinero de forma automatizada usando la variable embudo
 
        // 1. Cálculo base: Sueldo por Hora (Sueldo Mensual dividido entre Horas Totales del Mes)
        sueldoHora = sueldoMensualEmpleado / horasTotalesTrabajadas;
 
        // 2. Cálculo de ingresos diarios según el valor de hora determinado
        SueldodariolV = sueldoHora * horasDiariasLV;
        SueldoSabados = sueldoHora * horasSabado;
 
        // 3. Conversiones temporales exactas en base 60 para obtener el valor por minuto y por segundo
        SueldoMinuto = sueldoHora / 60;
        SueldoSegundo = SueldoMinuto / 60;
 
        // 4. Totales de ingresos por periodos semanales considerando o no la jornada extendida del sábado
        SueldoSemanalLV = SueldodariolV * 5;               // Sumatoria de los 5 días (Lunes a Viernes)
        SueldoSemanalLS = SueldoSemanalLV + SueldoSabados; // Integración del pago del día Sábado
 
        // 5. Cálculo del sueldo quincenal exacto (Sueldo mensual dividido entre 2)
        SueldoQuincenal = sueldoMensualEmpleado / 2;
 
        // IMPRESIÓN VISUAL DEL REPORTE FINAL
        cout << "\n=============================================" << endl;
        cout << "               REPORTE DE PAGO               " << endl;
        cout << "=============================================" << endl;
        cout << "Empleado: " << nombreEmpleado << endl;
        cout << "Sueldo Diario (Lunes a Viernes) = L. " << SueldodariolV << endl;
        cout << "Sueldo de los Sabados           = L. " << SueldoSabados << endl;
        cout << "Sueldo por Hora                 = L. " << sueldoHora << endl;
        cout << "Sueldo por Minuto               = L. " << SueldoMinuto << endl;
        cout << "Sueldo por Segundo              = L. " << SueldoSegundo << endl;
        cout << "Sueldo Semanal (Lunes a Viernes)= L. " << SueldoSemanalLV << endl;
 
        // Condicional para aplicar o descartar la jornada extendida del sábado en la impresión
        if (tipoEmpleado == 3)
        {
            // Si es empleado por contrato, no se divide por días de semana
            cout << "Sueldo Semanal (Lunes a Sabado) = No aplica (Por Contrato)" << endl;
        }
        else
        {
            // Si es Planta o Medio Tiempo, se muestra el acumulado que incluye el sábado
            cout << "Sueldo Semanal (Lunes a Sabado) = L. " << SueldoSemanalLS << endl;
        }
 
        cout << "Sueldo Quincenal                = L. " << SueldoQuincenal << endl;
        cout << "Horas Trabajadas Totales        = " << horasTotalesTrabajadas << " horas al mes." << endl;
        cout << "=============================================" << endl;
 

           cout << "¿Desea calcular el sueldo de otro empleado? (1. Sí, 2. No): ";
           cin >> respuesta;   // Leer la respuesta del usuario para controlar la repetición del programa
           // limpiar el buffer de entrada para evitar problemas con getline en la próxima iteración
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
       } while (respuesta == 1); // El programa se repetirá mientras el usuario ingrese 1 para calcular otro empleado



        return 0;
    }