#include "ClaseAbstractaBancoCuenta.hpp"
#include "Ejercicio4CuentaCorriente.hpp"

BancoCuenta::BancoCuenta(string titular_cuenta, double balance_) : 
balance(balance_), titularCuenta(titular_cuenta)  {};
void BancoCuenta::depositar(double ingreso){
    if (ingreso > 0)
    balance += ingreso;
    cout << "Se acaban de depositar: $" << ingreso << endl;
}
double BancoCuenta::getBalance() const { return balance; }
string BancoCuenta::getTitular() const { return titularCuenta; }
void BancoCuenta::modificarBalance(double monto){
    balance += monto;
}

CajaAhorro::CajaAhorro(string titular, double balanceInicial) : 
BancoCuenta(titular, balanceInicial) {};
void CajaAhorro::retirar(double monto){
    if(monto<=0){
        cout << "Monto Invalido.\n";
    } else if (monto>getBalance()){
        cout << "Fondos insufiecientes.\n";
    } else {
        modificarBalance(-monto);
        cout << "Retiro exitoso. Nuevo balance: $" << getBalance() << endl;
    }

}
void CajaAhorro::mostrarInfo(){
    contador_mostrarinfo++;
    cout << "Titular: " << getTitular() << endl;
    cout << "Tipo de cuenta: Caja de Ahorro" << endl;
    cout << "Balance actual: $" << getBalance() << endl;
    if (contador_mostrarinfo > 2){
        cout << "Se le desconto $20 de su cuenta por solicitar la informacion mas de dos veces" << endl;
        modificarBalance(-20);
    }
};


CuentaCorriente::CuentaCorriente(string titular, double balanceInicial, 
shared_ptr<CajaAhorro> _cajaAhorroVinculada) : 
BancoCuenta(titular, balanceInicial), cajaAhorroVinculada(_cajaAhorroVinculada) {};
void CuentaCorriente::retirar(double monto){
    if(monto <= getBalance()){
        modificarBalance(-monto);
        cout << "El dinero fue retirado exitosamente de la cuenta corriente: $" << monto <<endl;
    } else if(getBalance() + cajaAhorroVinculada->getBalance() >= monto){
        double desdeCC = getBalance();
        double restante = monto - desdeCC;
        modificarBalance(-desdeCC);
        cajaAhorroVinculada->modificarBalance(-restante);
        cout << "El dinero fue retirado exitosamente: $" << desdeCC
        << " de Cuenta Corriente y $" << restante << " de Caja de Ahorro" << endl;
        }
        else{
            cout << "La cuenta no posee ese dinero aunque se vacien ambas cuentas, Caja de Ahorro y Cuenta Corriente" << endl;
        }
    }
void CuentaCorriente::mostrarInfo(){        
    cout << "Titular: " << getTitular() << endl;
    cout << "Tipo de cuenta: Cuenta Corriente" << endl;
    cout << "Balance actual: $" << getBalance() << endl;
    };