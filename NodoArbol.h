#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Estudiante.h"

class NodoArbol {
public:
    Estudiante estudiante;
    NodoArbol* izquierdo;
    NodoArbol* derecho;

    NodoArbol(Estudiante est);
};

#endif