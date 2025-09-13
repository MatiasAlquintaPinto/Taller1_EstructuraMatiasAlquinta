#include "GestionAlumnos.h"

GestionAlumnos::GestionAlumnos() {
    head = nullptr;
}

void GestionAlumnos::insertar(Alumno* a) {
    Nodo* nuevo = new Nodo(a);
    nuevo->siguiente = head;
    head = nuevo;
}

void GestionAlumnos::mostrarTodos() {
    Nodo* current = head;
    while (current != nullptr) {
        current->dato->mostrarInfo();
        cout << "------------------" << endl;
        current = current->siguiente;
    }
}

Alumno* GestionAlumnos::buscar(int id) {
    Nodo* current = head;
    while (current != nullptr) {
        if (current->dato->getId() == id)
            return current->dato;
        current = current->siguiente;
    }
    return nullptr;
}

void GestionAlumnos::eliminar(int id) {
    Nodo* current = head;
    Nodo* anterior = nullptr;

    while (current != nullptr && current->dato->getId() != id) {
        anterior = current;
        current = current->siguiente;
    }

    if (current == nullptr) return;

    if (anterior == nullptr)
        head = current->siguiente;
    else
        anterior->siguiente = current->siguiente;

    delete current->dato;
    delete current;
}
void GestionAlumnos::buscarPorNombre(string nombre) {
    Nodo* current = head;
    bool encontrado = false;
    while (current != nullptr) {
        if (current->dato->getNombre() == nombre) {
            current->dato->mostrarInfo();
            cout << "------------------" << endl;
            encontrado = true;
        }
        current = current->siguiente;
    }
    if (!encontrado) {
        cout << "No se encontraron alumnos con el nombre: "+nombre << endl;
    }
}
void GestionAlumnos::mostrarPorCarrera(string carrera) {
    Nodo* current = head;
    bool encontrado = false;
    while (current != nullptr) {
        if (current->dato->getCarrera() == carrera) {
            current->dato->mostrarInfo();
            cout << "------------------" << endl;
            encontrado = true;
        }
        current = current->siguiente;
    }
    if (!encontrado) cout << "No se encontraron alumnos en la carrera: " << carrera << endl;
}
