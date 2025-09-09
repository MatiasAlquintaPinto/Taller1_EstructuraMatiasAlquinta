#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
using namespace std;
class Alumno {
private:
int id;
string nombre;
string apellido;
string carrera;
string fechaI;
public: 
Alumno(int _id, string _nombre, string _apellido, string _carrera, string _fechaI);
int getId();
string getNombre();
string getApellido();
string getCarrera();
string getFechaI();
void mostrarInfo();
};
#endif
