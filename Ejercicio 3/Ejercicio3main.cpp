#include "Ejercicio3Entero.hpp"
#include "Ejercicio3Real.hpp"
#include "Ejercicio3Complejo.hpp"

int main(){
    shared_ptr<Numero> num_entero = make_shared<Entero>(34);
    shared_ptr<Numero> num_real = make_shared<Real>(3.543);
    shared_ptr<Numero> num_complejo = make_shared<Complejo>(23,6);
    //Operaciones Entero...
    cout << "OPERACIONES CON ENTERO: \n" << endl;
    //Suma:
    cout<<"Suma:   \n"<<endl;
    //Entero con Entero...
    cout << "Sumando Entero con Entero..." << endl;
    shared_ptr<Numero> suma = num_entero->sumar(num_entero);
    cout << suma->toString() << "\n" << endl;
    //Entero con Real...
    cout << "Sumando Entero con Real..." << endl;
    shared_ptr<Numero> suma2 = num_entero->sumar(num_real);
    cout << suma2->toString() << "\n" << endl;
    //Entero con Complejo...
    cout << "Sumando Entero con Complejo..." << endl;
    shared_ptr<Numero> suma3 = num_entero->sumar(num_complejo);
    cout << suma3->toString() << "\n" << endl;
    // Resta:
    cout<<"Resta:   \n"<<endl;
    //Entero con Entero...
    cout << "Restando Entero con Entero..." << endl;
    shared_ptr<Numero> resta = num_entero->restar(num_entero);
    cout << resta->toString() << "\n" << endl;
    //Entero con Real...
    cout << "Restando Entero con Real..." << endl;
    shared_ptr<Numero> resta2 = num_entero->restar(num_real);
    cout << resta2->toString() << "\n" << endl;
    //Entero con Complejo...
    cout << "Restando Entero con Complejo..." << endl;
    shared_ptr<Numero> resta3 = num_entero->restar(num_complejo);
    cout << resta3->toString() << "\n" << endl;
    // Multiplicacion:
    cout<<"Multiplicacion:   \n"<<endl;
    //Entero con Entero...
    cout << "Multiplicando Entero con Entero..." << endl;
    shared_ptr<Numero> multiplicacion = num_entero->multiplicar(num_entero);
    cout << multiplicacion->toString() << "\n" << endl;
    //Entero con Real...
    cout << "Multiplicando Entero con Real..." << endl;
    shared_ptr<Numero> multiplicacion2 = num_entero->multiplicar(num_real);
    cout << multiplicacion2->toString() << "\n" << endl;
    //Entero con Complejo...
    cout << "Multiplicando Entero con Complejo..." << endl;
    shared_ptr<Numero> multiplicacion3 = num_entero->multiplicar(num_complejo);
    cout << multiplicacion3->toString() << "\n" << endl;

    //Operaciones Real...
    cout << "OPERACIONES CON REAL: \n" << endl;
    //Suma:
    cout<<"Suma:   \n"<<endl;
    //Real con Real...
    cout << "Sumando Real con Real..." << endl;
    shared_ptr<Numero> suma4 = num_real->sumar(num_real);
    cout << suma4->toString() << "\n" << endl;
    //Real con Entero...
    cout << "Sumando Real con Entero..." << endl;
    shared_ptr<Numero> suma5 = num_real->sumar(num_entero);
    cout << suma5->toString() << "\n" << endl;
    //Real con Complejo...
    cout << "Sumando Real con Complejo..." << endl;
    shared_ptr<Numero> suma6 = num_real->sumar(num_complejo);
    cout << suma6->toString() << "\n" << endl;
    // Resta:
    cout<<"Resta:   \n"<<endl;
    //Real con Real...
    cout << "Restando Real con Real..." << endl;
    shared_ptr<Numero> resta4 = num_real->restar(num_real);
    cout << resta4->toString() << "\n" << endl;
    //Real con Entero...
    cout << "Restando Real con Entero..." << endl;
    shared_ptr<Numero> resta5 = num_real->restar(num_entero);
    cout << resta5->toString() << "\n" << endl;
    //Real con Complejo...
    cout << "Restando Real con Complejo..." << endl;
    shared_ptr<Numero> resta6 = num_real->restar(num_complejo);
    cout << resta6->toString() << "\n" << endl;
    // Multiplicacion:
    cout<<"Multiplicacion:   \n"<<endl;
    //Real con Real...
    cout << "Multiplicando Real con Real..." << endl;
    shared_ptr<Numero> multiplicacion4 = num_real->multiplicar(num_real);
    cout << multiplicacion4->toString() << "\n" << endl;
    //Real con Entero...
    cout << "Multiplicando Real con Entero..." << endl;
    shared_ptr<Numero> multiplicacion5 = num_real->multiplicar(num_entero);
    cout << multiplicacion5->toString() << "\n" << endl;
    //Real con Complejo...
    cout << "Multiplicando Real con Complejo..." << endl;
    shared_ptr<Numero> multiplicacion6 = num_real->multiplicar(num_complejo);
    cout << multiplicacion6->toString() << "\n" << endl;


    //Operaciones Complejo...
    cout << "OPERACIONES CON COMPLEJO: \n" << endl;
    //Suma:
    cout<<"Suma:   \n"<<endl;
    //Complejo con complejo...
    cout << "Sumando Complejo con Complejo..." << endl;
    shared_ptr<Numero> suma7 = num_complejo->sumar(num_complejo);
    cout << suma7->toString() << "\n" << endl;
    //Complejo con Entero...
    cout << "Sumando Complejo con Entero..." << endl;
    shared_ptr<Numero> suma8 = num_complejo->sumar(num_entero);
    cout << suma8->toString() << "\n" << endl;
    //Complejo con Real...
    cout << "Sumando Complejo con Real..." << endl;
    shared_ptr<Numero> suma9 = num_complejo->sumar(num_real);
    cout << suma9->toString() << "\n" << endl;
    // Resta:
    cout<<"Resta:   \n"<<endl;
    //Complejo con Complejo...
    cout << "Restando Complejo con Complejo..." << endl;
    shared_ptr<Numero> resta7 = num_complejo->restar(num_complejo);
    cout << resta7->toString() << "\n" << endl;
    //Complejo con Entero...
    cout << "Restando Complejo con Entero..." << endl;
    shared_ptr<Numero> resta8 = num_complejo->restar(num_entero);
    cout << resta8->toString() << "\n" << endl;
    //Complejo con Real...
    cout << "Restando Complejo con Real..." << endl;
    shared_ptr<Numero> resta9 = num_complejo->restar(num_real);
    cout << resta9->toString() << "\n" << endl;
    // Multiplicacion:
    cout<<"Multiplicacion:   \n"<<endl;
    //Complejo con Complejo...
    cout << "Multiplicando Complejo con Complejo..." << endl;
    shared_ptr<Numero> multiplicacion7 = num_complejo->multiplicar(num_complejo);
    cout << multiplicacion7->toString() << "\n" << endl;
    //Complejo con Entero...
    cout << "Multiplicando Complejo con Entero..." << endl;
    shared_ptr<Numero> multiplicacion8 = num_complejo->multiplicar(num_entero);
    cout << multiplicacion8->toString() << "\n" << endl;
    //Complejo con Real...
    cout << "Multiplicando Complejo con Real..." << endl;
    shared_ptr<Numero> multiplicacion9 = num_complejo->multiplicar(num_real);
    cout << multiplicacion9->toString() << "\n" << endl;

}