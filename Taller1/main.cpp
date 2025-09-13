#include <iostream>
#include "Alumno.h"
#include "GestionAlumnos.h"
#include "GestionCursos.h"
using namespace std;
void menuAlumnos(GestionAlumnos &gestionAlumnos);
void menuCursos(GestionCursos &gestionCursos);
void menuInscripciones(GestionAlumnos &gestionAlumnos, GestionCursos &gestionCursos);
void menuNotas(GestionAlumnos &gestionAlumnos, GestionCursos &gestionCursos);
void menuReportes(GestionAlumnos &gestionAlumnos, GestionCursos &gestionCursos);
int leerOpcion(); 
int main() {
int opcion = -1;
GestionAlumnos gestionAlumnos;
GestionCursos gestionCursos;
while (opcion != 0) {
    cout << "=== Menu Principal ===" << endl;
    cout << "1- Manejo de Alumnos" << endl;
    cout << "2- Manejo de Cursos" << endl;
    cout << "3- Manejo de Inscripciones" << endl;
    cout << "4- Manejo de Notas" << endl;
    cout << "5- Consultas y Reportes" << endl;
    cout << "0- Salir" << endl;
    cout << "Seleccione una opcion: ";
    opcion = leerOpcion(); 

    switch(opcion) {
        case 1:
            cout << "Opcion 1 seleccionada: Manejo de Alumnos" << endl;
            menuAlumnos(gestionAlumnos);
            break;
        case 2:
            cout << "Opcion 2 seleccionada: Manejo de Cursos" << endl;
            menuCursos(gestionCursos);
            break;
        case 3:
            cout << "Opcion 3 seleccionada: Manejo de Inscripciones" << endl;
            menuInscripciones(gestionAlumnos, gestionCursos);
            break;
        case 4:
            cout << "Opcion 4 seleccionada: Manejo de Notas" << endl;
            menuNotas(gestionAlumnos, gestionCursos);
            break;
        case 5:
            cout << "Opcion 5 seleccionada: Consultas y Reportes" << endl;
            menuReportes(gestionAlumnos, gestionCursos);
            break;
        case 0:
            cout << "Cerrando el sistema" << endl;
            break;
        default:
            cout << "Opcion incorrecta, escoja nuevamente." << endl;
        }
        cout << endl;
    }
    return 0;
}
void menuAlumnos(GestionAlumnos &gestion) {
    int opcion = -1;
    while (opcion != 0) {
        cout << "Menu gestion de Alumnos" << endl;
        cout << "1.- Agregar Alumno" << endl;
        cout << "2.- Buscar Alumno por ID" << endl;
        cout << "3.- Buscar Alumno por Nombre" << endl;
        cout << "4.- Eliminar Alumno por ID" << endl;
        cout << "5.- Mostrar Todos los Alumnos" << endl;
        cout << "0.- Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opcion = leerOpcion(); 

        if (opcion == 1) {
            int id;
            string nombre, apellido, carrera, fechaI;
            cout << "ID: "; cin >> id;
            cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Apellido: "; getline(cin, apellido);
            cout << "Carrera: "; getline(cin, carrera);
            cout << "Fecha de Ingreso: "; getline(cin, fechaI);

            Alumno* a = new Alumno(id, nombre, apellido, carrera, fechaI);
            gestion.insertar(a);
            cout << "Alumno agregado correctamente" << endl;
        } 
        else if (opcion == 2) {
            int id;
            cout << "Ingrese ID de alumno: "; cin >> id;
            Alumno* a = gestion.buscar(id);
            if (a != nullptr) a->mostrarInfo();
            else cout << "Alumno no encontrado." << endl;
        }
        else if (opcion == 3) {
            string nombre;
            cin.ignore();
            cout << "Ingrese Nombre del alumno: ";
            getline(cin, nombre);
            gestion.buscarPorNombre(nombre);
        }
        else if (opcion == 4) {
            int id;
            cout << "Ingrese ID a eliminar: "; cin >> id;
            gestion.eliminar(id);
            cout << "El alumno fue eliminado." << endl;
        } 
        else if (opcion == 5) {
            gestion.mostrarTodos();
        } 
        else if (opcion == 0) {
            cout << "Saliendo del menu alumnos" << endl;
        } 
        else {
            cout << "Opcion incorrecta, escoja nuevamente" << endl;
        }
    }
}
void menuCursos(GestionCursos &gestion) {
    int opcion = -1;
    while (opcion != 0) {
        cout << "Menu gestion de Cursos" << endl;
        cout << "1.- Agregar Curso" << endl;
        cout << "2.- Buscar Curso por Codigo" << endl;
        cout << "3.- Buscar Curso por Nombre" << endl;
        cout << "4.- Eliminar Curso por Codigo" << endl;
        cout << "5.- Mostrar Todos los Cursos" << endl;
        cout << "0.- Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opcion = leerOpcion(); 

        if (opcion == 1) {
            string codigo, nombre, carrera, profesor;
            int cantMax;
            cin.ignore();
            cout << "Codigo Unico: "; getline(cin, codigo);
            cout << "Nombre del Curso: "; getline(cin, nombre);
            cout << "Cantidad Maxima de Estudiantes: "; cin >> cantMax;
            cin.ignore();
            cout << "Carrera: "; getline(cin, carrera);
            cout << "Nombre Profesor: "; getline(cin, profesor);

            Curso* c = new Curso(codigo, nombre, cantMax, carrera, profesor);
            gestion.insertar(c);
            cout << "Curso agregado correctamente" << endl;
        } 
        else if (opcion == 2) {
            string codigo;
            cin.ignore();
            cout << "Ingrese Codigo del curso: "; getline(cin, codigo);
            Curso* c = gestion.buscar(codigo);
            if (c != nullptr) c->mostrarInfo();
            else cout << "Curso no encontrado." << endl;
        }
        else if (opcion == 3) {
            string nombre;
            cin.ignore();
            cout << "Ingrese Nombre del curso: "; getline(cin, nombre);
            gestion.buscarPorNombre(nombre);
        }
        else if (opcion == 4) {
            string codigo;
            cin.ignore();
            cout << "Ingrese Codigo del curso a eliminar: "; getline(cin, codigo);
            gestion.eliminar(codigo);
            cout << "El curso fue eliminado." << endl;
        } 
        else if (opcion == 5) {
            gestion.mostrarTodos();
        } 
        else if (opcion == 0) {
            cout << "Saliendo del menu cursos" << endl;
        } 
        else {
            cout << "Opcion no valida" << endl;
        }
    }
}
void menuInscripciones(GestionAlumnos &gestionAlumnos, GestionCursos &gestionCursos) {
    int opcion = -1;
    while(opcion != 0) {
        cout << "--- Menu de inscripciones ---"<< endl;
        cout << "1- Inscribir alumno en curso"<< endl;
        cout << "2- Eliminar inscripcion de alumno"<< endl;
        cout << "3- Mostrar alumnos inscritos en un curso"<< endl;
        cout << "0- Volver al menu principal"<< endl;
        cout << "Seleccione una opcion: "<< endl;
        opcion = leerOpcion(); 
        if(opcion == 1) {
            int idAlumno;
            string codigoCurso;
            cout << "ID del alumno: "; cin >> idAlumno;
            cout << "Codigo del curso: "; cin >> codigoCurso;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            Curso* c = gestionCursos.buscar(codigoCurso);
            if(a == nullptr) cout << "Alumno no encontrado"<< endl;
            else if(c == nullptr) cout << "Curso no encontrado"<< endl;
            else if(a->getCarrera() != c->getCarrera()) cout << "Carreras no coinciden, no se puede inscribir"<< endl;
            else if(c->inscribirAlumno(a)) cout << "Alumno inscrito correctamente"<< endl;
            else cout << "Curso lleno, no se puede inscribir"<< endl;
        }
        else if(opcion == 2) {
            int idAlumno;
            string codigoCurso;
            cout << "ID del alumno a eliminar: "; cin >> idAlumno;
            cout << "Codigo del curso: "; cin >> codigoCurso;
            Curso* c = gestionCursos.buscar(codigoCurso);
            if(c == nullptr) cout << "Curso no encontrado"<< endl;
            else if(c->eliminarAlumno(idAlumno)) cout << "Alumno eliminado del curso"<< endl;
            else cout << "Alumno no estaba inscrito en el curso"<< endl;
        }
        else if(opcion == 3) {
            string codigoCurso;
            cout << "Codigo del curso: "; cin >> codigoCurso;
            Curso* c = gestionCursos.buscar(codigoCurso);
            if(c == nullptr) cout << "Curso no encontrado."<< endl;
            else c->mostrarInscritos();
        }
        else if(opcion == 0) cout << "Saliendo de menu inscripciones"<< endl;
        else cout << "Opcion invalida"<< endl;
    }
}
void menuNotas(GestionAlumnos &gestionAlumnos, GestionCursos &gestionCursos) {
    int opcion = -1;
    while(opcion != 0) {
        cout << "--- Menu de Notas ---" << endl;
        cout << "1.- Agregar nota a un alumno" << endl;
        cout << "2.- Ver promedio de un alumno en un curso" << endl;
        cout << "3.- Ver promedio general de un alumno" << endl;
        cout << "0.- Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opcion = leerOpcion(); 

        if(opcion == 1) {
            int idAlumno;
            string codigoCurso;
            float nota;
            cout << "ID del alumno: "; cin >> idAlumno;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            if(a == nullptr) cout << "Alumno no encontrado." << endl;
            else {
                cout << "Codigo del curso: "; cin >> codigoCurso;
                Curso* c = gestionCursos.buscar(codigoCurso);
                if(c == nullptr) cout << "Curso no encontrado." << endl;
                else {
                    cout << "Nota (1.0 a 7.0): "; cin >> nota;
                    if(nota < 1.0 || nota > 7.0) cout << "Nota invalida." << endl;
                    else {
                        a->agregarNota(codigoCurso, nota);
                        cout << "Nota agregada correctamente." << endl;
                    }
                }
            }
        }
        else if(opcion == 2) {
            int idAlumno;
            string codigoCurso;
            cout << "ID del alumno: "; cin >> idAlumno;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            if(a == nullptr) cout << "Alumno no encontrado." << endl;
            else {
                cout << "Codigo del curso: "; cin >> codigoCurso;
                float prom = a->promedioCurso(codigoCurso);
                if(prom == 0) cout << "No hay notas para este curso." << endl;
                else cout << "Promedio en el curso " << codigoCurso << ": " << prom << endl;
            }
        }
        else if(opcion == 3) {
            int idAlumno;
            cout << "ID del alumno: "; cin >> idAlumno;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            if(a == nullptr) cout << "Alumno no encontrado." << endl;
            else {
                float prom = a->promedioGeneral();
                if(prom == 0) cout << "No hay notas registradas para este alumno." << endl;
                else cout << "Promedio general del alumno: " << prom << endl;
            }
        }
        else if(opcion == 0) cout << "Saliendo del menu de notas" << endl;
        else cout << "Opcion invalida, intente nuevamente." << endl;
    }
}
void menuReportes(GestionAlumnos &gestionAlumnos, GestionCursos &gestionCursos) {
    int opcion = -1;
    while(opcion != 0) {
        cout << "--- Menu consultas y reportes ---" << endl;
        cout << "1- Obtener todos los alumnos de una carrera" << endl;
        cout << "2- Obtener todos los cursos en los que un alumno está inscrito" << endl;
        cout << "3- Calcular promedio de un alumno en un curso" << endl;
        cout << "4- Calcular promedio general de un alumno" << endl;
        cout << "5- Consultar informacion completa de un alumno" << endl;
        cout << "0- Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opcion = leerOpcion(); 

        if(opcion == 1) {
            string carrera;
            cin.ignore();
            cout << "Ingrese carrera: "; getline(cin, carrera);
            gestionAlumnos.mostrarPorCarrera(carrera);
        }
        else if(opcion == 2) {
            int idAlumno;
            cout << "ID del alumno: "; cin >> idAlumno;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            if(a == nullptr) cout << "Alumno no encontrado." << endl;
            else {
                cout << "Cursos en los que está inscrito el alumno:" << endl;
                gestionCursos.mostrarCursosDeAlumno(a);
            }
        }
        else if(opcion == 3) {
            int idAlumno;
            string codigoCurso;
            cout << "ID del alumno: "; cin >> idAlumno;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            if(a == nullptr) cout << "Alumno no encontrado." << endl;
            else {
                cout << "Codigo del curso: "; cin >> codigoCurso;
                float prom = a->promedioCurso(codigoCurso);
                if(prom == 0) cout << "No hay notas para este curso" << endl;
                else cout << "Promedio en el curso " << codigoCurso << ": " << prom << endl;
            }
        }
        else if(opcion == 4) {
            int idAlumno;
            cout << "ID del alumno: "; cin >> idAlumno;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            if(a == nullptr) cout << "Alumno no encontrado." << endl;
            else {
                float prom = a->promedioGeneral();
                if(prom == 0) cout << "No hay notas registradas para el alumno indicado" << endl;
                else cout << "Promedio general del alumno: " << prom << endl;
            }
        }
        else if(opcion == 5) {
            int idAlumno;
            cout << "ID del alumno: "; cin >> idAlumno;
            Alumno* a = gestionAlumnos.buscar(idAlumno);
            if(a == nullptr) cout << "Alumno no encontrado." << endl;
            else {
                a->mostrarInfo();
                cout << "Cursos inscritos y notas:" << endl;
                gestionCursos.mostrarCursosYNotasDeAlumno(a);
                cout << "Promedio general: " << a->promedioGeneral() << endl;
            }
        }
        else if(opcion == 0) cout << "Saliendo del menu de reportes" << endl;
        else cout << "Opcion invalida, intente nuevamente." << endl;
    }
}    
int leerOpcion() {
    int opcion;
    cin >> opcion;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return -1; 
    }
    return opcion;
}