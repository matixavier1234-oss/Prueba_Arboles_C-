#ifndef ARBOLBST_H
#define ARBOLBST_H

#include "NodoArbol.h"
#include <string>

class ArbolBST {
private:
    NodoArbol* raiz;

    // Métodos privados recursivos
    NodoArbol* insertarRecursivo(NodoArbol* nodo, Estudiante est);
    NodoArbol* buscarRecursivo(NodoArbol* nodo, std::string cedula) const;
    NodoArbol* encontrarMinimo(NodoArbol* nodo);
    NodoArbol* eliminarRecursivo(NodoArbol* nodo, std::string cedula);
    
    void inordenRecursivo(NodoArbol* nodo) const;
    void preordenRecursivo(NodoArbol* nodo) const;
    void postordenRecursivo(NodoArbol* nodo) const;
    
    int contarNodosRecursivo(NodoArbol* nodo) const;
    int calcularAlturaRecursivo(NodoArbol* nodo) const;
    
    void buscarNotaMayorRecursivo(NodoArbol* nodo, Estudiante*& mejor) const;
    void buscarNotaMenorRecursivo(NodoArbol* nodo, Estudiante*& peor) const;
    
    void mostrarAprobadosRecursivo(NodoArbol* nodo) const;
    void mostrarReprobadosRecursivo(NodoArbol* nodo) const;
    
    void destruirArbol(NodoArbol* nodo);

public:
    ArbolBST();
    ~ArbolBST();

    // Operaciones públicas
    void insertarEstudiante(Estudiante est);
    bool buscarEstudiante(std::string cedula) const;
    void eliminarEstudiante(std::string cedula);
    
    void recorridoInorden() const;
    void recorridoPreorden() const;
    void recorridoPostorden() const;
    void recorridoPorNiveles() const;   // BFS con cola
    
    int contarNodos() const;
    int calcularAltura() const;
    
    void buscarNotaMayor() const;
    void buscarNotaMenor() const;
    void mostrarAprobados() const;
    void mostrarReprobados() const;
};

#endif