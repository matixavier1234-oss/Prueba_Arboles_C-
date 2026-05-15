#include "Estudiante.h"
#include <iostream>

using namespace std;

Estudiante::Estudiante() : cedula(""), apellidos(""), nombres(""), 
                           notaFinal(0.0), carrera(""), nivel(0) {}

Estudiante::Estudiante(string ced, string ape, string nom, 
                       float nota, string car, int niv)
    : cedula(ced), apellidos(ape), nombres(nom), 
      notaFinal(nota), carrera(car), nivel(niv) {}

string Estudiante::getCedula() const { return cedula; }
string Estudiante::getApellidos() const { return apellidos; }
string Estudiante::getNombres() const { return nombres; }
float Estudiante::getNotaFinal() const { return notaFinal; }
string Estudiante::getCarrera() const { return carrera; }
int Estudiante::getNivel() const { return nivel; }

void Estudiante::setCedula(string ced) { cedula = ced; }
void Estudiante::setApellidos(string ape) { apellidos = ape; }
void Estudiante::setNombres(string nom) { nombres = nom; }
void Estudiante::setNotaFinal(float nota) { notaFinal = nota; }
void Estudiante::setCarrera(string car) { carrera = car; }
void Estudiante::setNivel(int niv) { nivel = niv; }

bool Estudiante::operator<(const Estudiante& otro) const {
    return cedula < otro.cedula;
}
bool Estudiante::operator>(const Estudiante& otro) const {
    return cedula > otro.cedula;
}
bool Estudiante::operator==(const Estudiante& otro) const {
    return cedula == otro.cedula;
}
bool Estudiante::operator!=(const Estudiante& otro) const {
    return cedula != otro.cedula;
}

void Estudiante::mostrar() const {
    cout << "Cédula: " << cedula << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Nombres: " << nombres << endl;
    cout << "Nota final: " << notaFinal << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "------------------------" << endl;
}