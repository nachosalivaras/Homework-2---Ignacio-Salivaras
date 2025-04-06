#include "InterfazNumero.hpp"
#ifndef Real_HPP
#define Real_HPP

class Real: public Numero{
    private:
    const double numero;
    public:
    Real(const double n);
    double getValor() const;
    shared_ptr<Numero> sumar(const shared_ptr<Numero>& otronum) const override;
    shared_ptr<Numero> restar (const shared_ptr<Numero>& otronum) const override;
    shared_ptr<Numero> multiplicar(const shared_ptr<Numero>& otronum) const override;
    string toString() const override;

};


#endif