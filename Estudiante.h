#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <iostream>

class Estudiante {
private:
    std::string cedula;
    std::string apellidos;
    std::string nombres;
    float notaFinal;
    std::string carrera;
    int nivel;

public:
    // Constructores
    Estudiante();
    Estudiante(std::string ced, std::string ape, std::string nom, 
               float nota, std::string car, int niv);

    // Getters
    std::string getCedula() const;
    std::string getApellidos() const;
    std::string getNombres() const;
    float getNotaFinal() const;
    std::string getCarrera() const;
    int getNivel() const;

    // Setters
    void setCedula(std::string ced);
    void setApellidos(std::string ape);
    void setNombres(std::string nom);
    void setNotaFinal(float nota);
    void setCarrera(std::string car);
    void setNivel(int niv);

    // Sobrecarga de operadores para comparar por cédula (necesario para BST)
    bool operator<(const Estudiante& otro) const;
    bool operator>(const Estudiante& otro) const;
    bool operator==(const Estudiante& otro) const;
    bool operator!=(const Estudiante& otro) const;

    // Muestra los datos del estudiante
    void mostrar() const;
};

#endif