#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#ifndef BancoCuenta_HPP
#define BancoCuenta_HPP
using namespace std;

class BancoCuenta{
    private:
    /*
    Justifiacion: Estos atributos son privados porque solo yo quiero modificar y acceder
    al balance de la cuenta y al nombre del titular.
    */
    double balance;
    string const titularCuenta;
    protected:
    
    /*
    Justifiacion: Estos metodos son protected porque solo yo quiero modificar y acceder
    al balance de la cuenta y al nombre del titular, pero necesito que sea protected para
    que mis subclases puedan acceder. Por ejemplo, cuenta corriente necesita poder acceder
    al balance de alguna forma y caja de ahorro tambien.
    */
    double getBalance() const;
    string getTitular() const;
    void modificarBalance(double monto);
    public:
    /*
    Justifiacion: Estos metodos son public porque yo quiero que mi usario pueda depositar,
    retirar y ver la info de su cuenta, pero no modificarla de forma manual por eso los 
    atributos son privados.
    */
    BancoCuenta(string titular_cuenta, double balance_);
    void depositar(double ingreso);
    virtual void retirar(double monto) = 0;
    virtual void mostrarInfo() = 0;
    virtual ~BancoCuenta() {};
};

#endif
