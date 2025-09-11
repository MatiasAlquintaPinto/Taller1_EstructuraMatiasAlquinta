#ifndef CURSO_H
#define CURSO_H
#include <string>
#include <iostream>
using namespace std;
class Curso {
private:
    string codigoUnico;
    string nombre;
    int cantMax;
    string carrera;
    string nProfesor;
public:
Curso(string _codigoUnico, string _nombre, int _cantMax, string _carrera, string _nProfesor);
string getCodigoUnico();
string getNombre();
int getCantMax();
string getCarrera();
string getNProfesor();

void mostrarInfo();
};

#endif