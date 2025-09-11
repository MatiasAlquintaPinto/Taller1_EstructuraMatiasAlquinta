#include <iostream>
#include "Alumno.h"
#include "GestionAlumnos.h"
using namespace std;

int main() {
int opcion = -1;

while (opcion != 0) {
    cout << "===== MENU PRINCIPAL =====" << endl;
    cout << "1.- Manejo de Alumnos" << endl;
    cout << "2.- Manejo de Cursos" << endl;
    cout << "3.- Manejo de Inscripciones" << endl;
    cout << "4.- Manejo de Notas" << endl;
    cout << "5.- Consultas y Reportes" << endl;
    cout << "0.- Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Opcion 1 seleccionada: Manejo de Alumnos (pendiente)" << endl;
    } 
    else if (opcion == 2) {
        cout << "Opcion 2 seleccionada: Manejo de Cursos (pendiente)" << endl;
    } 
    else if (opcion == 3) {
        cout << "Opcion 3 seleccionada: Manejo de Inscripciones (pendiente)" << endl;
    } 
    else if (opcion == 4) {
        cout << "Opcion 4 seleccionada: Manejo de Notas (pendiente)" << endl;
    } 
    else if (opcion == 5) {
        cout << "Opcion 5 seleccionada: Consultas y Reportes (pendiente)" << endl;
    } 
    else if (opcion == 0) {
        cout << "Saliendo del programa..." << endl;
    } 
    else {
        cout << "Opcion incorrecta, escoja nuevamente." << endl;
    }
    }

    return 0;
}