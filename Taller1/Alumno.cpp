#include "Alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno(int _id, string _nombre, string _apellido, string _carrera, string _fechaI) {
    id = _id;
    nombre = _nombre;
    apellido = _apellido;
    carrera = _carrera;
    fechaI = _fechaI;
}
int Alumno::getId() { return id; }
string Alumno::getNombre() { return nombre; }
string Alumno::getApellido() { return apellido; }
string Alumno::getFechaI() { return fechaI; }
string Alumno::getCarrera() { return carrera; }
void Alumno::mostrarInfo() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Fecha de Ingreso: " << fechaI << endl;
}