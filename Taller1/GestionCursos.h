#ifndef GESTIONCURSOS_H
#define GESTIONCURSOS_H

#include "Curso.h"
#include <iostream>
using namespace std;

class GestionCursos {
private:
    class Nodo {
    public:
        Curso* dato;
        Nodo* siguiente;
        Nodo(Curso* c) : dato(c), siguiente(nullptr) {}
    };

    Nodo* head;

public:
    GestionCursos();
    void insertar(Curso* c);
    void eliminar(string codigo);
    Curso* buscar(string codigo);
    void mostrarTodos();
    void buscarPorNombre(string nombre);
    void mostrarCursosDeAlumno(Alumno* a);
    void mostrarCursosYNotasDeAlumno(Alumno* a);
};

#endif