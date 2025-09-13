#ifndef CURSO_H
#define CURSO_H
#include <string>
#include <iostream>
#include "Alumno.h"
using namespace std;

class Curso {
private:
    string codigoUnico;
    string nombre;
    int cantMax;
    string carrera;
    string nProfesor;

    struct NodoAlumno {
        Alumno* alumno;
        NodoAlumno* siguiente;
        NodoAlumno(Alumno* a) : alumno(a), siguiente(nullptr) {}
    };

    NodoAlumno* headInscritos; 
    int inscritos;

public:
    Curso(string _codigoUnico, string _nombre, int _cantMax, string _carrera, string _nProfesor);

    string getCodigoUnico();
    string getNombre();
    int getCantMax();
    string getCarrera();
    string getNProfesor();
    void mostrarInfo();
    bool inscribirAlumno(Alumno* a);
    bool eliminarAlumno(int id);
    void mostrarInscritos();
    bool alumnoInscrito(int idAlumno);
    float promedioAlumno(int idAlumno);
};

#endif