#include "ArbolBST.h"
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
ArbolBST::ArbolBST() : raiz(nullptr) {}

// Destructor
ArbolBST::~ArbolBST() {
    destruirArbol(raiz);
}

// Inserta un estudiante
void ArbolBST::insertarEstudiante(Estudiante est) {
    raiz = insertarRecursivo(raiz, est);
}

NodoArbol* ArbolBST::insertarRecursivo(NodoArbol* nodo, Estudiante est) {
    if (nodo == nullptr) {
        return new NodoArbol(est);
    }
    if (est < nodo->estudiante) {
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, est);
    } else if (est > nodo->estudiante) {
        nodo->derecho = insertarRecursivo(nodo->derecho, est);
    } else {
        cout << "Ya existe un estudiante con la cédula " << est.getCedula() << endl;
    }
    return nodo;
}

// Búsqueda por cédula
bool ArbolBST::buscarEstudiante(string cedula) const {
    NodoArbol* resultado = buscarRecursivo(raiz, cedula);
    if (resultado != nullptr) {
        cout << "Estudiante encontrado:" << endl;
        resultado->estudiante.mostrar();
        return true;
    } else {
        cout << "No se encontró estudiante con cédula: " << cedula << endl;
        return false;
    }
}

NodoArbol* ArbolBST::buscarRecursivo(NodoArbol* nodo, string cedula) const {
    if (nodo == nullptr || nodo->estudiante.getCedula() == cedula) {
        return nodo;
    }
    if (cedula < nodo->estudiante.getCedula()) {
        return buscarRecursivo(nodo->izquierdo, cedula);
    } else {
        return buscarRecursivo(nodo->derecho, cedula);
    }
}

// Encontrar mínimo (para eliminar con dos hijos)
NodoArbol* ArbolBST::encontrarMinimo(NodoArbol* nodo) {
    while (nodo && nodo->izquierdo != nullptr) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

// Eliminar por cédula
void ArbolBST::eliminarEstudiante(string cedula) {
    raiz = eliminarRecursivo(raiz, cedula);
    cout << "Eliminación completada (si existía)." << endl;
}

NodoArbol* ArbolBST::eliminarRecursivo(NodoArbol* nodo, string cedula) {
    if (nodo == nullptr) return nullptr;
    
    if (cedula < nodo->estudiante.getCedula()) {
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, cedula);
    } else if (cedula > nodo->estudiante.getCedula()) {
        nodo->derecho = eliminarRecursivo(nodo->derecho, cedula);
    } else {
        // Nodo encontrado
        if (nodo->izquierdo == nullptr) {
            NodoArbol* temp = nodo->derecho;
            delete nodo;
            return temp;
        } else if (nodo->derecho == nullptr) {
            NodoArbol* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }
        // Dos hijos: reemplazar con el sucesor inorden
        NodoArbol* temp = encontrarMinimo(nodo->derecho);
        nodo->estudiante = temp->estudiante;
        nodo->derecho = eliminarRecursivo(nodo->derecho, temp->estudiante.getCedula());
    }
    return nodo;
}

// Recorridos
void ArbolBST::recorridoInorden() const {
    cout << "=== RECORRIDO INORDEN ===" << endl;
    inordenRecursivo(raiz);
}

void ArbolBST::inordenRecursivo(NodoArbol* nodo) const {
    if (nodo != nullptr) {
        inordenRecursivo(nodo->izquierdo);
        nodo->estudiante.mostrar();
        inordenRecursivo(nodo->derecho);
    }
}

void ArbolBST::recorridoPreorden() const {
    cout << "=== RECORRIDO PREORDEN ===" << endl;
    preordenRecursivo(raiz);
}

void ArbolBST::preordenRecursivo(NodoArbol* nodo) const {
    if (nodo != nullptr) {
        nodo->estudiante.mostrar();
        preordenRecursivo(nodo->izquierdo);
        preordenRecursivo(nodo->derecho);
    }
}

void ArbolBST::recorridoPostorden() const {
    cout << "=== RECORRIDO POSTORDEN ===" << endl;
    postordenRecursivo(raiz);
}

void ArbolBST::postordenRecursivo(NodoArbol* nodo) const {
    if (nodo != nullptr) {
        postordenRecursivo(nodo->izquierdo);
        postordenRecursivo(nodo->derecho);
        nodo->estudiante.mostrar();
    }
}

// BFS (recorrido por niveles)
void ArbolBST::recorridoPorNiveles() const {
    cout << "=== RECORRIDO POR NIVELES (BFS) ===" << endl;
    if (raiz == nullptr) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    queue<NodoArbol*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        NodoArbol* actual = cola.front();
        cola.pop();
        actual->estudiante.mostrar();
        if (actual->izquierdo != nullptr) cola.push(actual->izquierdo);
        if (actual->derecho != nullptr) cola.push(actual->derecho);
    }
}

// Conteo de nodos
int ArbolBST::contarNodos() const {
    return contarNodosRecursivo(raiz);
}

int ArbolBST::contarNodosRecursivo(NodoArbol* nodo) const {
    if (nodo == nullptr) return 0;
    return 1 + contarNodosRecursivo(nodo->izquierdo) + contarNodosRecursivo(nodo->derecho);
}

// Altura del árbol
int ArbolBST::calcularAltura() const {
    return calcularAlturaRecursivo(raiz);
}

int ArbolBST::calcularAlturaRecursivo(NodoArbol* nodo) const {
    if (nodo == nullptr) return -1;
    int altIzq = calcularAlturaRecursivo(nodo->izquierdo);
    int altDer = calcularAlturaRecursivo(nodo->derecho);
    return 1 + max(altIzq, altDer);
}

// Nota mayor
void ArbolBST::buscarNotaMayor() const {
    Estudiante* mejor = nullptr;
    buscarNotaMayorRecursivo(raiz, mejor);
    if (mejor != nullptr) {
        cout << "Estudiante con la NOTA MÁS ALTA:" << endl;
        mejor->mostrar();
    } else {
        cout << "El árbol está vacío." << endl;
    }
}

void ArbolBST::buscarNotaMayorRecursivo(NodoArbol* nodo, Estudiante*& mejor) const {
    if (nodo == nullptr) return;
    if (mejor == nullptr || nodo->estudiante.getNotaFinal() > mejor->getNotaFinal()) {
        mejor = &nodo->estudiante;
    }
    buscarNotaMayorRecursivo(nodo->izquierdo, mejor);
    buscarNotaMayorRecursivo(nodo->derecho, mejor);
}

// Nota menor
void ArbolBST::buscarNotaMenor() const {
    Estudiante* peor = nullptr;
    buscarNotaMenorRecursivo(raiz, peor);
    if (peor != nullptr) {
        cout << "Estudiante con la NOTA MÁS BAJA:" << endl;
        peor->mostrar();
    } else {
        cout << "El árbol está vacío." << endl;
    }
}

void ArbolBST::buscarNotaMenorRecursivo(NodoArbol* nodo, Estudiante*& peor) const {
    if (nodo == nullptr) return;
    if (peor == nullptr || nodo->estudiante.getNotaFinal() < peor->getNotaFinal()) {
        peor = &nodo->estudiante;
    }
    buscarNotaMenorRecursivo(nodo->izquierdo, peor);
    buscarNotaMenorRecursivo(nodo->derecho, peor);
}

// Aprobados (nota >= 7)
void ArbolBST::mostrarAprobados() const {
    cout << "=== ESTUDIANTES APROBADOS (Nota >= 7) ===" << endl;
    mostrarAprobadosRecursivo(raiz);
}

void ArbolBST::mostrarAprobadosRecursivo(NodoArbol* nodo) const {
    if (nodo == nullptr) return;
    mostrarAprobadosRecursivo(nodo->izquierdo);
    if (nodo->estudiante.getNotaFinal() >= 7.0) {
        nodo->estudiante.mostrar();
    }
    mostrarAprobadosRecursivo(nodo->derecho);
}

// Reprobados (nota < 7)
void ArbolBST::mostrarReprobados() const {
    cout << "=== ESTUDIANTES REPROBADOS (Nota < 7) ===" << endl;
    mostrarReprobadosRecursivo(raiz);
}

void ArbolBST::mostrarReprobadosRecursivo(NodoArbol* nodo) const {
    if (nodo == nullptr) return;
    mostrarReprobadosRecursivo(nodo->izquierdo);
    if (nodo->estudiante.getNotaFinal() < 7.0) {
        nodo->estudiante.mostrar();
    }
    mostrarReprobadosRecursivo(nodo->derecho);
}

// Destruir árbol (liberar memoria)
void ArbolBST::destruirArbol(NodoArbol* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->izquierdo);
        destruirArbol(nodo->derecho);
        delete nodo;
    }
}