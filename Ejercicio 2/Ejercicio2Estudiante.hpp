#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#ifndef Estudiante_H
#define Estudiante_H
using namespace std;

//Ejercicio 2 a), b)

class Estudiante {
    private:
    string nombrecompleto;
    int legajo;
    unordered_map<string, float> cursosnotas;

    public:
    Estudiante(const string&_nombrecompleto, int _legajo);
    void agregarCurso(const string& nombreCurso, float nota);
    string getnombrecompleto() const;
    int getlegajo() const;
    float getpromedio() const;
    bool operator < (const Estudiante& estudiante2) const;
    friend ostream& operator << (ostream& os, const Estudiante& p);

  
};

#endif
