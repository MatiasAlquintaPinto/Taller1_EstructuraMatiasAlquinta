#include "Alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno(int _id, string _nombre, string _apellido, string _carrera, string _fechaI) {
    id = _id;
    nombre = _nombre;
    apellido = _apellido;
    carrera = _carrera;
    fechaI = _fechaI;
    headNotas = nullptr;
}

int Alumno::getId() { return id; }
string Alumno::getNombre() { return nombre; }
string Alumno::getApellido() { return apellido; }
string Alumno::getCarrera() { return carrera; }
string Alumno::getFechaI() { return fechaI; }

void Alumno::mostrarInfo() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Fecha de Ingreso: " << fechaI << endl;
}

void Alumno::agregarNota(string codigoCurso, float nota) {
    Nota* nuevo = new Nota(codigoCurso, nota);
    nuevo->siguiente = headNotas;
    headNotas = nuevo;
}

float Alumno::promedioCurso(string codigoCurso) {
    Nota* current = headNotas;
    int count = 0;
    float suma = 0;
    while (current != nullptr) {
        if (current->codigoCurso == codigoCurso) {
            suma += current->nota;
            count++;
        }
        current = current->siguiente;
    }
    if (count == 0) return 0;
    return suma / count;
}

float Alumno::promedioGeneral() {
    Nota* current = headNotas;
    int count = 0;
    float suma = 0;
    while (current != nullptr) {
        suma += current->nota;
        count++;
        current = current->siguiente;
    }
    if (count == 0) return 0;
    return suma / count;
}
