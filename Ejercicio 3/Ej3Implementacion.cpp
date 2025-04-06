#include "Ejercicio3Entero.hpp"
#include "Ejercicio3Real.hpp"
#include "Ejercicio3Complejo.hpp"


//Entero
Entero::Entero(const int n) : numero(n) {}
int Entero::getValor() const{return numero;}
shared_ptr<Numero> Entero::sumar(const shared_ptr<Numero>& otronum) const{
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if (cast_num_entero) {//osea si el numero es entero
        int resultado = this->numero + cast_num_entero->numero;
        return make_shared<Entero>(resultado);
    }
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if (cast_num_real) {
        double resultado = static_cast<double>(this->numero) + cast_num_real->getValor();
        return make_shared<Real>(resultado);
    }
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if (cast_num_complejo){
        double resultado_real = static_cast<double>(this->numero) + cast_num_complejo->getReal();
        double resultado_complejo = cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real,resultado_complejo);
    }
    return nullptr;

}
shared_ptr<Numero> Entero::restar (const shared_ptr<Numero>& otronum) const{
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if (cast_num_entero) {//osea si el numero es entero
        int resultado = this->numero - cast_num_entero->numero;
        return make_shared<Entero>(resultado);
    }
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if (cast_num_real) {
        double resultado = static_cast<double>(this->numero) - cast_num_real->getValor();
        return make_shared<Real>(resultado);
    }
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if (cast_num_complejo){
        double resultado_real = static_cast<double>(this->numero) - cast_num_complejo->getReal();
        double resultado_complejo = cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real,resultado_complejo);
    }
    return nullptr;

}
shared_ptr<Numero> Entero::multiplicar(const shared_ptr<Numero>& otronum) const{
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if (cast_num_entero) {//osea si el numero es entero
        int resultado = this->numero * cast_num_entero->numero;
        return make_shared<Entero>(resultado);
    }
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if (cast_num_real) {
        double resultado = static_cast<double>(this->numero) * cast_num_real->getValor();
        return make_shared<Real>(resultado);
    }
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if (cast_num_complejo){
        // Multiplicación: (a) * (c + di) = (a*c) + (a*d)i
        double resultado_real = static_cast<double>(this->numero) * cast_num_complejo->getReal();
        double resultado_complejo = static_cast<double>(this->numero) *cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real,resultado_complejo);
    }
    return nullptr;

}
string Entero::toString() const {
    return to_string(numero);
}



//Real
Real::Real(const double n) : numero(n) {}
double Real::getValor() const {return numero;}
shared_ptr<Numero> Real::sumar(const shared_ptr<Numero>& otronum) const{
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if(cast_num_real){
        double resultado = this->numero + cast_num_real->getValor();
        return make_shared<Real>(resultado);
    }
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if(cast_num_entero){
        double resultado = this->numero + static_cast<double>(cast_num_entero->getValor());
        return make_shared<Real>(resultado);
    }
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if(cast_num_complejo){
        double resultado_real = this->numero + cast_num_complejo->getReal();
        double resultado_complejo = cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real,resultado_complejo);
    }
    return nullptr;

}
shared_ptr<Numero> Real::restar (const shared_ptr<Numero>& otronum) const{
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if(cast_num_real){
        double resultado = this->numero - cast_num_real->getValor();
        return make_shared<Real>(resultado);
    }
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if(cast_num_entero){
        double resultado = this->numero - static_cast<double>(cast_num_entero->getValor());
        return make_shared<Real>(resultado);
    }
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if(cast_num_complejo){
        double resultado_real = this->numero - cast_num_complejo->getReal();
        double resultado_complejo = cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real,resultado_complejo);
    }
    return nullptr;
}
shared_ptr<Numero> Real::multiplicar(const shared_ptr<Numero>& otronum) const{
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if(cast_num_real){
        double resultado = this->numero * cast_num_real->getValor();
        return make_shared<Real>(resultado);
    }
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if(cast_num_entero){
        double resultado = this->numero * static_cast<double>(cast_num_entero->getValor());
        return make_shared<Real>(resultado);
    }
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if(cast_num_complejo){
        // Multiplicación: (a) * (c + di) = (a*c) + (a*d)i
        double resultado_real = this->numero * cast_num_complejo->getReal();
        double resultado_complejo = this->numero * cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real,resultado_complejo);
    }
    return nullptr;
}
string Real::toString() const {
    return to_string(numero);
}


//Complejo
Complejo::Complejo(const double _real, const double _imaginario)
: real(_real), imaginario(_imaginario) {}
double Complejo::getReal() const {return real;}
double Complejo::getImaginario() const {return imaginario;}
shared_ptr<Numero> Complejo::sumar(const shared_ptr<Numero>& otronum) const{
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if (cast_num_complejo){
        double resultado_real = this->real + cast_num_complejo->getReal();
        double resultado_imaginario = this->imaginario + cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real, resultado_imaginario);
    }
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if(cast_num_entero){
        double resultado_real = this->real + static_cast<double>(cast_num_entero->getValor());
        return make_shared<Complejo>(resultado_real, this->imaginario);
    }
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if(cast_num_real){
        double resultado_real = this->real + cast_num_real->getValor();
        return make_shared<Complejo>(resultado_real, this->imaginario);
    }
    return nullptr;

}
shared_ptr<Numero> Complejo::restar (const shared_ptr<Numero>& otronum) const{
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if (cast_num_complejo){
        double resultado_real = this->real - cast_num_complejo->getReal();
        double resultado_imaginario = this->imaginario - cast_num_complejo->getImaginario();
        return make_shared<Complejo>(resultado_real, resultado_imaginario);
    }
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if(cast_num_entero){
        double resultado_real = this->real - static_cast<double>(cast_num_entero->getValor());
        return make_shared<Complejo>(resultado_real, this->imaginario);
    }
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if(cast_num_real){
        double resultado_real = this->real - cast_num_real->getValor();
        return make_shared<Complejo>(resultado_real, this->imaginario);
    }
    return nullptr;
}
shared_ptr<Numero> Complejo::multiplicar(const shared_ptr<Numero>& otronum) const{
    shared_ptr<Complejo> cast_num_complejo = dynamic_pointer_cast<Complejo>(otronum);
    if (cast_num_complejo){
        //Multiplicar complejos: (a+bi)(c+di)=(ac−bd)+(ad+bc)i
        double resultado_real = (this->real * cast_num_complejo->getReal()) - 
        (this->imaginario * cast_num_complejo->getImaginario());
        double resultado_imaginario = (this->real * cast_num_complejo->getImaginario()) +
        (this->imaginario * cast_num_complejo->getReal());
        return make_shared<Complejo>(resultado_real, resultado_imaginario);
    }
    shared_ptr<Entero> cast_num_entero = dynamic_pointer_cast<Entero>(otronum);
    if(cast_num_entero){
        double resultado_real = this->real * static_cast<double>(cast_num_entero->getValor());
        double resultado_imaginario = this->imaginario * static_cast<double>(cast_num_entero->getValor());
        return make_shared<Complejo>(resultado_real, resultado_imaginario);
    }
    shared_ptr<Real> cast_num_real = dynamic_pointer_cast<Real>(otronum);
    if(cast_num_real){
        double resultado_real = this->real * cast_num_real->getValor();
        double resultado_imaginario = this->imaginario * static_cast<double>(cast_num_real->getValor());
        return make_shared<Complejo>(resultado_real, resultado_imaginario);
    }
    return nullptr;
}
string Complejo::toString() const {
    string real_ = to_string(real);
    string imaginario_;
    string stringcompleto;
    if (imaginario >= 0){
    imaginario_ = to_string(imaginario);
    stringcompleto = real_ + " + " + imaginario_ + "i";
    }else {
    imaginario_ = to_string(-imaginario);
    stringcompleto = real_ + " - " + imaginario_ + "i";
    }
    return stringcompleto;
}