# 📚 Prueba Práctica: Árboles Binarios de Búsqueda – C++ y Java

**Asignatura:** Estructura de Datos  
**Tema:** Árboles binarios, recorridos y aplicación práctica  
**Universidad:** Universidad Técnica de Ambato  

---

## 📌 Descripción del proyecto

Este repositorio contiene la implementación completa de un sistema académico que permite gestionar estudiantes mediante un **árbol binario de búsqueda (ABB)**. Cada estudiante almacena: cédula, apellidos, nombres, nota final, carrera y nivel.

El sistema está desarrollado en **C++** y **Java** siguiendo los principios de:
- Programación orientada a objetos.
- Recursividad para las operaciones del árbol.
- Uso de punteros (C++) y referencias (Java).
- Recorridos: Inorden, Preorden, Postorden y BFS (con cola).

Ambas versiones exponen un menú interactivo con 14 opciones que cubren todas las funciones obligatorias.

---

## 📁 Estructura del repositorio

prueba-practica-arboles-cpp-java/
│
├── cpp/
│ ├── Estudiante.h
│ ├── Estudiante.cpp
│ ├── NodoArbol.h
│ ├── NodoArbol.cpp
│ ├── ArbolBST.h
│ ├── ArbolBST.cpp
│ ├── main.cpp
│ └── Makefile (opcional)
│
├── java/
│ ├── Estudiante.java
│ ├── NodoArbol.java
│ ├── ArbolBST.java
│ └── Main.java
│
├── evidencias/
│ ├── menu.png
│ ├── insercion.png
│ ├── inorden.png
│ ├── bfs.png
│ ├── mayor_nota.png
│ ├── aprobados.png
│ └── eliminacion.png
│
├── README.md
└── LICENSE (opcional


---

## ⚙️ Requisitos

### Para C++
- Compilador con soporte C++11 o superior (g++, clang++).
- Sistema operativo: Windows, Linux o macOS.

### Para Java
- JDK 8 o superior.
- (Opcional) IDE como IntelliJ, Eclipse o NetBeans.

---

## 🚀 Instrucciones de compilación y ejecución

### 🔹 Versión C++

```bash
# Entrar al directorio cpp
cd cpp

# Compilar
g++ -std=c++11 -o sistema_estudiantes Estudiante.cpp NodoArbol.cpp ArbolBST.cpp main.cpp

# Ejecutar
./sistema_estudiantes   # Linux/macOS
sistema_estudiantes.exe # Windows

    