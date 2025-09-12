#include "Curso.h"

Curso::Curso(string _codigoUnico, string _nombre, int _cantMax, string _carrera, string _nProfesor) {
    codigoUnico = _codigoUnico;
    nombre = _nombre;
    cantMax = _cantMax;
    carrera = _carrera;
    nProfesor = _nProfesor;
    headInscritos = nullptr;
    inscritos = 0;
}

string Curso::getCodigoUnico() { return codigoUnico; }
string Curso::getNombre() { return nombre; }
int Curso::getCantMax() { return cantMax; }
string Curso::getCarrera() { return carrera; }
string Curso::getNProfesor() { return nProfesor; }

void Curso::mostrarInfo() {
    cout << "Codigo Unico: " << codigoUnico << endl;
    cout << "Nombre Curso: " << nombre << endl;
    cout << "Cantidad Maxima de Estudiantes: " << cantMax << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Nombre Profesor: " << nProfesor << endl;
    cout << "Inscritos: " << inscritos << "/" << cantMax << endl;
}

bool Curso::inscribirAlumno(Alumno* a) {
    if (inscritos >= cantMax) return false;
    NodoAlumno* nuevo = new NodoAlumno(a);
    nuevo->siguiente = headInscritos;
    headInscritos = nuevo;
    inscritos++;
    return true;
}

bool Curso::eliminarAlumno(int id) {
    NodoAlumno* current = headInscritos;
    NodoAlumno* anterior = nullptr;

    while (current != nullptr) {
        if (current->alumno->getId() == id) {
            if (anterior == nullptr) {
                headInscritos = current->siguiente;
            } else {
                anterior->siguiente = current->siguiente;
            }
            delete current;
            inscritos--;
            return true;
        }
        anterior = current;
        current = current->siguiente;
    }
    return false;
}

void Curso::mostrarInscritos() {
    NodoAlumno* current = headInscritos;
    if (current == nullptr) {
        cout << "No hay alumnos inscritos en este curso." << endl;
        return;
    }
    cout << "Alumnos inscritos en curso: " << nombre << ":" << endl;
    while (current != nullptr) {
        current->alumno->mostrarInfo();
        current = current->siguiente;
    }
}
