#include "ClaseAbstractaBancoCuenta.hpp"
#ifndef CajaAhorro_HPP
#define CajaAhorro_HPP

class CajaAhorro: public BancoCuenta{
    private:
    // El usuario no tiene porque tener acceso a esta informacion, ni modificarla.
    int contador_mostrarinfo = 0;
    public:
    /*
    Al igual que lo mencionamos anteriormente,  el usuario tiene que poder acceder a su informacion, 
    a retirar dinero y a saber cuanto dinero le queda en la cuenta. Estos metodos tienen que ser
    publicos ya que en su clase bases son publicos, entonces si yo no los hago publicos se rompe el
    contrato de visibilidad, porque si tengo un puntero a la clase base, el usuario piensa que
    puede acceder a mis metodos publicos tanto en la clase base como en la clases derivadas.
    */ 
    
    CajaAhorro(string titular, double balanceInicial);
    void retirar(double monto) override;
    virtual void mostrarInfo() override;
    /*
    Esta definición de CuentaCorriente como clase amiga (friend) es necesaria porque quiero, 
    desde CuentaCorriente, modificar el balance de una CajaDeAhorro vinculada.
    Al declarar CuentaCorriente como clase amiga dentro de CajaDeAhorro, le doy acceso 
    completo a sus atributos y métodos, incluyendo aquellos que son protected o private 
    en la jerarquía.
    Esto me permite usar métodos como modificarBalance() desde CuentaCorriente, aunque 
    dicho método es protected en la clase base (BancoCuenta), ya que no podría acceder a 
    él directamente al tratarse de un objeto externo y no del objeto actual (this).
    En resumen, friend me habilita a romper la barrera de acceso para poder operar 
    directamente sobre los datos internos de otra instancia.
    */
    friend class CuentaCorriente;
};



#endif