#include "InterfazNumero.hpp"
#ifndef Complejo_HPP
#define Complejo_HPP

class Complejo: public Numero{
    private:
    double const real;
    double const imaginario;
    public:
    Complejo(const double _real, const double _imaginario);
    double getReal() const;
    double getImaginario() const;
    shared_ptr<Numero> sumar(const shared_ptr<Numero>& otronum) const override;
    shared_ptr<Numero> restar (const shared_ptr<Numero>& otronum) const override;
    shared_ptr<Numero> multiplicar(const shared_ptr<Numero>& otronum) const override;
    string toString() const override;

};


#endif