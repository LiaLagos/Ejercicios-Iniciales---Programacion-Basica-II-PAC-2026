#include <bits/stdc++.h>
using namespace std;

struct Estudiante{
    string nombre, apellido, numCuenta;
    char sexo;
    double p1,p2,p3,finalNota;
    string categoria;
};

string clasificar(double nota){
    if(nota>=90) return "Excelente";
    if(nota>=80) return "Muy Bueno";
    if(nota>=70) return "Bueno";
    if(nota>=60) return "Regular";
    return "Maleta";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cout << "Ingrese la cantidad de estudiantes (>=3): ";
    while(!(cin>>N) || N<3){
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido. Ingrese un numero entero >=3: ";
    }

    vector<Estudiante> v; v.reserve(N);
    for(int i=0;i<N;i++){
        Estudiante e;
        cout << "\n--- Estudiante "<< i+1 <<" ---\n";
        cout << "Nombre: "; cin >> ws; getline(cin, e.nombre);
        cout << "Apellido: "; getline(cin, e.apellido);
        cout << "Numero de cuenta: "; cin >> e.numCuenta;
        cout << "Sexo (M/F): "; cin >> e.sexo;
        auto readNota=[&](const string &msg){
            double x; cout<<msg; while(!(cin>>x) || x<0 || x>100){
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Nota invalida. "<<msg;
            }
            return x;
        };
        e.p1 = readNota("Nota 1 (0-100): ");
        e.p2 = readNota("Nota 2 (0-100): ");
        e.p3 = readNota("Nota 3 (0-100): ");
        e.finalNota = e.p1*0.25 + e.p2*0.35 + e.p3*0.40;
        e.categoria = clasificar(e.finalNota);
        v.push_back(e);
    }

    // Guardar en archivo
    ofstream ofs("calificaciones.txt");
    if(!ofs){
        cerr<<"No se pudo crear el archivo de salida.\n";
        return 1;
    }

    double sumaTotal=0;
    int aprobados=0;
    ofs << "Listado de estudiantes:\n";
    for(auto &e: v){
        ofs << "Nombre: "<< e.nombre <<" "<< e.apellido <<" | Cuenta: "<< e.numCuenta
            <<" | Sexo: "<< e.sexo <<" | P1: "<< e.p1 <<" P2: "<< e.p2 <<" P3: "<< e.p3
            <<" | Final: "<< fixed << setprecision(2) << e.finalNota <<" | "<< e.categoria <<"\n";
        sumaTotal += e.finalNota;
        if(e.finalNota>=60) aprobados++;
    }
    double promedioGeneral = sumaTotal / N;

    // Mostrar en pantalla
    cout << "\n--- Resultado ---\n";
    cout << "Cantidad de estudiantes: "<< N <<"\n";
    cout << "Promedio general: "<< fixed << setprecision(2) << promedioGeneral <<"\n\n";

    cout << "Detalles por estudiante:\n";
    for(auto &e: v){
        cout << e.nombre <<" "<< e.apellido <<" | Cuenta: "<< e.numCuenta
             <<" | Final: "<< fixed << setprecision(2) << e.finalNota <<" | "<< e.categoria <<"\n";
    }

    cout << "\nAprobados: "<< aprobados <<"\n";
    cout << "Reprobados: "<< (N - aprobados) <<"\n";
    cout << "Porcentaje aprobados: "<< fixed << setprecision(2) << (100.0*aprobados/N) <<"%\n";
    cout << "Porcentaje reprobados: "<< fixed << setprecision(2) << (100.0*(N-aprobados)/N) <<"%\n";

    // Escribir resumen al archivo
    ofs << "\nResumen:\n";
    ofs << "Cantidad: "<< N <<"\n";
    ofs << "Promedio general: "<< fixed << setprecision(2) << promedioGeneral <<"\n";
    ofs << "Aprobados: "<< aprobados <<" Reprobados: "<< (N-aprobados) <<"\n";

    ofs.close();
    cout << "\nDatos guardados en 'calificaciones.txt'.\n";
    return 0;
}
