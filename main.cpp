#include "ArbolBST.h"
#include <iostream>
#include <limits>

using namespace std;

// Funciones auxiliares para entrada con validación
string leerString(string mensaje)
{
    string valor;
    cout << mensaje;
    getline(cin, valor);
    // Eliminar espacios al inicio/fin
    size_t inicio = valor.find_first_not_of(" \t");
    if (inicio != string::npos)
    {
        valor = valor.substr(inicio);
    }
    size_t fin = valor.find_last_not_of(" \t");
    if (fin != string::npos)
    {
        valor = valor.substr(0, fin + 1);
    }
    return valor;
}

float leerFloat(string mensaje)
{
    float valor;
    cout << mensaje;
    while (!(cin >> valor))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Ingrese un número: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}

int leerInt(string mensaje)
{
    int valor;
    cout << mensaje;
    while (!(cin >> valor))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Ingrese un número entero: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    ArbolBST arbol;
    int opcion;

    do
    {
        cout << "\n===== SISTEMA DE GESTIÓN DE ESTUDIANTES =====" << endl;
        cout << "1. Insertar estudiante" << endl;
        cout << "2. Buscar estudiante por cédula" << endl;
        cout << "3. Eliminar estudiante" << endl;
        cout << "4. Recorrido Inorden" << endl;
        cout << "5. Recorrido Preorden" << endl;
        cout << "6. Recorrido Postorden" << endl;
        cout << "7. Recorrido por niveles BFS" << endl;
        cout << "8. Contar estudiantes" << endl;
        cout << "9. Calcular altura del árbol" << endl;
        cout << "10. Mostrar estudiante con mayor nota" << endl;
        cout << "11. Mostrar estudiante con menor nota" << endl;
        cout << "12. Mostrar estudiantes aprobados" << endl;
        cout << "13. Mostrar estudiantes reprobados" << endl;
        cout << "14. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
        {
            cout << "\n--- INSERTAR ESTUDIANTE ---" << endl;
            string cedula = leerString("Cédula: ");
            string apellidos = leerString("Apellidos: ");
            string nombres = leerString("Nombres: ");
            float nota = leerFloat("Nota final: ");
            string carrera = leerString("Carrera: ");
            int nivel = leerInt("Nivel: ");
            Estudiante nuevo(cedula, apellidos, nombres, nota, carrera, nivel);
            arbol.insertarEstudiante(nuevo);
            break;
        }
        case 2:
        {
            string cedula = leerString("Ingrese cédula a buscar: ");
            arbol.buscarEstudiante(cedula);
            break;
        }
        case 3:
        {
            string cedula = leerString("Ingrese cédula del estudiante a eliminar: ");
            arbol.eliminarEstudiante(cedula);
            break;
        }
        case 4:
            arbol.recorridoInorden();
            break;
        case 5:
            arbol.recorridoPreorden();
            break;
        case 6:
            arbol.recorridoPostorden();
            break;
        case 7:
            arbol.recorridoPorNiveles();
            break;
        case 8:
            cout << "Total de estudiantes: " << arbol.contarNodos() << endl;
            break;
        case 9:
            cout << "Altura del árbol: " << arbol.calcularAltura() << endl;
            break;
        case 10:
            arbol.buscarNotaMayor();
            break;
        case 11:
            arbol.buscarNotaMenor();
            break;
        case 12:
            arbol.mostrarAprobados();
            break;
        case 13:
            arbol.mostrarReprobados();
            break;
        case 14:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
        if (opcion != 14)
        {
            cout << "\nPresione Enter para continuar...";
            cin.get();
            limpiarPantalla();
        }
    } while (opcion != 14);

    return 0;
}