#include "GestionCursos.h"

GestionCursos::GestionCursos() {
    head = nullptr;
}

void GestionCursos::insertar(Curso* c) {
    Nodo* nuevo = new Nodo(c);
    nuevo->siguiente = head;
    head = nuevo;
}

void GestionCursos::mostrarTodos() {
    Nodo* current = head;
    while (current != nullptr) {
        current->dato->mostrarInfo();
        cout << "------------------" << endl;
        current = current->siguiente;
    }
}

Curso* GestionCursos::buscar(string codigo) {
    Nodo* current = head;
    while (current != nullptr) {
        if (current->dato->getCodigoUnico() == codigo)
            return current->dato;
        current = current->siguiente;
    }
    return nullptr;
}

void GestionCursos::eliminar(string codigo) {
    Nodo* current = head;
    Nodo* anterior = nullptr;

    while (current != nullptr && current->dato->getCodigoUnico() != codigo) {
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
void GestionCursos::buscarPorNombre(string nombre) {
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
        cout << "No se encontraron cursos con el nombre: "+nombre << endl;
    }
}