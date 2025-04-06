#include "Ejercicio4CuentaCorriente.hpp"

int main(){
    shared_ptr<CajaAhorro> ca = make_shared<CajaAhorro>("Ines",5000);
    CuentaCorriente cc = CuentaCorriente("Ines",2000,ca);

    std::cout << "\n--- Probando Caja de Ahorro ---\n";
    ca->mostrarInfo();   // 1
    ca->mostrarInfo();   // 2
    ca->mostrarInfo();   // 3 → debería descontar $20
    ca->retirar(6000);    // ❌ no debería poder retirar más de lo que hay
    ca->retirar(100);    // ✅ retiro válido
    ca->mostrarInfo();   // mostrar estado actual

    std::cout << "\n--- Probando Cuenta Corriente ---\n";
    cc.retirar(1000);       // ✅ suficiente en CC
    cc.retirar(2001);       // ✅ ahora debería usar parte de la caja
    cc.retirar(8000);      // ❌ no alcanza en ninguna → muestra mensaje
    ca->mostrarInfo();   // ver cuánto quedó en la caja
    cc.mostrarInfo();    // ver como quedo la cuenta corriente

}