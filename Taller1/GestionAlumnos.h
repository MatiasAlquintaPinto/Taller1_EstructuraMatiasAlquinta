#ifndef GESTIONALUMNOS_H
#define GESTIONALUMNOS_H

#include "Alumno.h"
#include <iostream>
using namespace std;

class GestionAlumnos {
private:
    class Nodo {
    public:
        Alumno* dato;
        Nodo* siguiente;
        Nodo(Alumno* a) : dato(a), siguiente(nullptr) {}
    };

    Nodo* head;

public:
    GestionAlumnos();
    void insertar(Alumno* a);
    void eliminar(int id);
    Alumno* buscar(int id);
    void mostrarTodos();
    void buscarPorNombre(string nombre);
};

#endif