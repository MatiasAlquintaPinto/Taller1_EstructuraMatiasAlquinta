#include "Curso.h"


Curso::Curso(string _codigoUnico, string _nombre, int _cantMax, string _carrera, string _nProfesor) {
    codigoUnico = _codigoUnico;
    nombre = _nombre;
    cantMax = _cantMax;
    carrera = _carrera;
    nProfesor = _nProfesor;
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
}