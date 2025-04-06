#include "Ejercicio2Estudiante.hpp"
#include "Ejercicio2Curso.hpp"


//Ejercicio 2 a), b)

Estudiante::Estudiante(const string&_nombrecompleto, int _legajo){
    nombrecompleto = _nombrecompleto; 
    legajo = _legajo;
} 
void Estudiante:: agregarCurso(const string& nombreCurso, float nota){
    cursosnotas[nombreCurso] = nota;
}
string Estudiante::getnombrecompleto() const {return nombrecompleto;}
int Estudiante::getlegajo() const {return legajo;}
float Estudiante::getpromedio() const {
    if (cursosnotas.empty()) return 0;
    float suma = 0;
    for (pair<string, float> par : cursosnotas) {
        suma += par.second;
    }

    return suma / cursosnotas.size();

};
bool Estudiante::operator<(const Estudiante& estudiante2) const{
    return nombrecompleto < estudiante2.nombrecompleto;
}
ostream& operator << (ostream& os, const Estudiante& _estudiante){
    os << _estudiante.getnombrecompleto();
    return os;

}

void Curso::agregarestudiante(shared_ptr<Estudiante> estudiante){
    estudiantes.push_back(estudiante);
}
void Curso::eliminarestudiante(shared_ptr<Estudiante> estudiante){
    shared_ptr<Estudiante> curr = estudiantes[0];
    for (size_t i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i] == estudiante){
            estudiantes.erase(estudiantes.begin() + i);
            break;
        }
    }
}
bool Curso::esta_en_la_lista(int legajo){
    for (size_t i = 0; i < estudiantes.size(); i++){
        if (estudiantes[i]->getlegajo() == legajo){
            return true;
        }

    }
    return false;
}
bool Curso::curso_completo(){
    if (estudiantes.size()>=20){
        return true;
    } else {
        return false;
    }
}
void Curso::imprimir_en_orden_alfabetico(){
    sort(estudiantes.begin(), estudiantes.end());
    for (size_t i = 0; i<estudiantes.size();i++){
        cout << *estudiantes[i] << endl;
    }
}

void mostrartmenu(){
    std::cout << "\n========== MENÚ PRINCIPAL ==========\n";
    std::cout << "1. Agregar estudiante\n";
    std::cout << "2. Eliminar estudiante\n";
    std::cout << "3. Imprimir lista de estudiantes ordenada\n";
    std::cout << "4. Ver promedio de un estudiante\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}