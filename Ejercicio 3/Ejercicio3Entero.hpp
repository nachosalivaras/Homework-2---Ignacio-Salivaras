#include "InterfazNumero.hpp"
#ifndef Entero_HPP
#define Entero_HPP

class Entero: public Numero{
    private:
    const int numero;

    public:
    Entero(const int n);
    int getValor() const;
    shared_ptr<Numero> sumar(const shared_ptr<Numero>& otronum) const override;
    shared_ptr<Numero> restar (const shared_ptr<Numero>& otronum) const override;
    shared_ptr<Numero> multiplicar(const shared_ptr<Numero>& otronum) const override;
    string toString() const override;


};


#endif