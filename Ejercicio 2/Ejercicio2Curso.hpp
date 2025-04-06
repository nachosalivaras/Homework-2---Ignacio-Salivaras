#include "Ejercicio2Estudiante.hpp"
#include <vector>
#include <memory>
#ifndef Curso_H
#define Curso_H

//Ejercicio 2 a), b)

class Curso {
    private:
    vector<shared_ptr<Estudiante>> estudiantes;

    public:
    void agregarestudiante(shared_ptr<Estudiante> estudiante);
    void eliminarestudiante(shared_ptr<Estudiante> estudiante);
    bool esta_en_la_lista(int legajo);
    bool curso_completo();
    void imprimir_en_orden_alfabetico();
};

#endif
