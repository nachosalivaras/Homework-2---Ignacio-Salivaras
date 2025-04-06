#include "ClaseAbstractaBancoCuenta.hpp"
#include "Ejercicio4CajadeAhorro.hpp"

#ifndef CuentaCorriente_HPP
#define CuentaCorreinte_HPP
class CuentaCorriente: public BancoCuenta{
    private:
    /* 
    La vinculación con la caja de ahorro es un detalle interno de implementación. 
    El usuario de la clase no debería tener acceso directo a esta información, ya que 
    podría modificar el estado de la cuenta de forma incorrecta o insegura.
    */
    shared_ptr<CajaAhorro> cajaAhorroVinculada;
    public:
    /*
    MISMO MOTIVO QUE EN CUENTACORRIENTE:
    Al igual que lo mencionamos anteriormente,  el usuario tiene que poder acceder a su informacion, 
    a retirar dinero y a saber cuanto dinero le queda en la cuenta. Estos metodos tienen que ser
    publicos ya que en su clase bases son publicos, entonces si yo no los hago publicos se rompe el
    contrato de visibilidad, porque si tengo un puntero a la clase base, el usuario piensa que
    puede acceder a mis metodos publicos tanto en la clase base como en la clases derivadas.
     
    */ 
    
    CuentaCorriente(string titular, double balanceInicial, shared_ptr<CajaAhorro> _cajaAhorroVinculada);
    void retirar(double monto) override;
    virtual void mostrarInfo() override;
};



#endif