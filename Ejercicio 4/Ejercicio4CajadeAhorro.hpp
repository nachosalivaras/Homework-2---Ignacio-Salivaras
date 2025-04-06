#include "ClaseAbstractaBancoCuenta.hpp"
#ifndef CajaAhorro_HPP
#define CajaAhorro_HPP

class CajaAhorro: public BancoCuenta{
    private:
    // El usuario no tiene porque tener acceso a esta informacion.
    int contador_mostrarinfo = 0;
    public:
    /*
    El atributo tiene que poder acceder a su informacion, a retirar dinero y a saber cuanto
    dinero le queda en la cuenta
    */ 
    
    CajaAhorro(string titular, double balanceInicial);
    void retirar(double monto) override;
    virtual void mostrarInfo() override;
    friend class CuentaCorriente;
};



#endif