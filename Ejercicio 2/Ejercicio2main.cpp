#include "Ejercicio2Estudiante.hpp"
#include "Ejercicio2Curso.hpp"

//Ejercicio 2 a), b), c), d)


/*
b) v.
    Copia:
    ¿Como la implemento?
    Para relizar la copia del objeto curso decidi utilizar shallow copy de la siguiente manera,
    "Curso curso2 = curso1;" Copiando esto en el main ya se crea una shallow copy de forma
    adecuada, ya que c++ genera automaticamente el constructor de copia y todos los atributos
    de mi clase tienen tienen sobrecargado el operador "=". Me refiero a que el tipo "vector"
    y el tipo "shared_ptr" ya tienen ese operador sobrecargado, entonces el compilador interpreta el
    "=" de forma correcta y se realiza la shallow copy de forma adecuada. 
    ¿Porque elegí shallowcopy?
    Eleji shallow copy porque quiero copiar los punteros a los objetos de tipo estudiantes de
    forma exactamente igual, es decir que mi nueva copia de el tipo curso contenga en su vector
    exactamente las mismas direcciones de memoria a los estudiantes que contiene el vector
    del curso que estoy copiando. Como son shared pointers mis punteros se copian sin problemas,
    y ahora en vez de tener un puntero que apunta a un determinado estudiante, tengo 2. Yo eleji 
    esta forma de hacerlo tambien porque yo quiero que cuando modifique un estudiante que contiene
    mi curso1, tambien quiero que se modifique en mi curso2. Por ejemplo, si yo quiero agregar una 
    materia que esta cursando mi estudiante, yo quiero que esta materia se agregue en el vector del
    curso 1 y del curso 2, de forma conjunta. Y cuando quiero elimiar el estudiante de algun curso,
    no tengo problema ya que son shared pointers, y mientras un puntero este referenciado a una
    direccion de memoria, esta no va a desaparecer, entonces si yo elimino un estudiante de 
    "Matematicas", no implica que mi estudiante se elimine en "Ciencias", ya que todavia hay
    un puntero, en este caso el vector de ciencias, que apunta a mi estudiante.
    En conclusion los cambios de los estudiantes se modifican en conjunto, y las eliminaciones no, 
    ya que son shared pointers. Es exactamente lo que buscaba.

c)
    La relacion que existe entre objetos los objetos de tipo curso y tipo estudiante puede
    ser una composicion o una agregacion segun mi opinion, ya que nuestro objeto curso contiene 
    punteros a objetos de tipo estudiante, y los estudiantes pueden ser controlados a partir del
    objeto curso. Hay una fuerte relacion entre ambos pero se puede llegar a ver como una composiocion.
    Caso Composicion: En el caso en el que la relacion se comporta como una composicion es cuando yo 
    solo contengo un shared_ptr a mi estudiante, es decir cuando mi estudiante esta en un solo curso.
    Esto sucede ya que a partir de mi objeto curso yo puedo controlar mi objeto esudiante y cuando 
    elimino el todo es decir el curso, se me elimina el estudiante (si e estudiante fue crado cuando
    se agrego al curso)
    Caso Agregacion: En el caso en el que la relacion se comporta como una agregacion es cuando yo 
    tengo el estudiante en mas de un curso, ya que cuando lo elimino de un curso, este no se elimina
    por completo, el estudiante sigue "vivo" pero en otro curso. El otro caso en el que la relacion se
    comporta como una agregacion es cundo yo creo mi puntero a mi objeto en el main, ya que cuando 
    elimine mi curso el estudiante no va a desaparecer por completo ya que todavia existe un puntero
    al estudiante en el main.


*/

void mostrarmenu(){
    cout << "\n========== MENÚ PRINCIPAL ==========\n";
    cout << "1. Agregar curso al perfil del estudiante\n";
    cout << "2. Obtener nombre completo del estudiante\n";
    cout << "3. Obtener legajo del estudiante\n";
    cout << "4. Obtener promedio del estudiante\n";
    cout << "5. Agregar estudiante al curso\n";
    cout << "6. Eliminar estudiante del curso\n";
    cout << "7. Chequear si el estudiante esta en el curso\n";
    cout << "8. Imprimir lista de estudiantes ordenada\n";
    cout << "9. Esta el curso completo\n";
    cout << "10. Salir\n";
    cout << "Seleccione una opción: ";
}
void menu(){
    Curso curso1;
    shared_ptr<Estudiante> numero1 = make_shared<Estudiante>("Ines ",1345);
    shared_ptr<Estudiante> numero2 = make_shared<Estudiante>("Nacho ",1245);
    string value;
    bool cursosAgregados = false;
    while (true) {
        mostrarmenu();
        int opcion;
        cin >> opcion;
        switch(opcion) {
            case 1:
            cout << "Agregando Matematica y Ciencias...\n" << endl;
            numero1->agregarCurso("Matematica", 8.6);
            numero1->agregarCurso("Ciencias", 4.3);
            numero2->agregarCurso("Matematica", 7.5);
            numero2->agregarCurso("Ciencias", 8.0);
            cursosAgregados = true;
            cout << "✅ \n" << endl;
            break;
            case 2:
            cout << "Obteniendo nombre objeto1 y objeto2... \n"<< endl;
            cout << "Objeto numero1 nombre: " << numero1->getnombrecompleto() << "\n"<< endl;
            cout << "Objeto numero2 nombre: " << numero2->getnombrecompleto() << "\n"<< endl;
            cout << "✅ \n"<< endl;
            break;
            case 3:
            cout << "Obteniendo legajo objeto1 y objeto2...\n"<< endl;
            cout << "Objeto numero1 legajo: " << numero1->getlegajo() << "\n"<< endl;
            cout << "Objeto numero2 legajo: " << numero2->getlegajo() << "\n"<< endl;
            cout << "✅ \n"<< endl;
            break;
            case 4:
            if (!cursosAgregados) {
                cout << "⚠️ Primero agregá cursos desde la opción 1.\n";
                break;
            }
            cout << "Obteniendo promedio objeto1 y objeto2...\n"<< endl;
            cout << "Promedio objeto1: " << numero1->getpromedio() << "\n"<< endl;
            cout << "Promedio objeto2: " << numero2->getpromedio() << "\n"<< endl;
            cout << "✅ \n"<< endl;
            break;
            case 5:
            cout << "Agregando estuidantes al curso...\n"<< endl;
            curso1.agregarestudiante(numero1);
            curso1.agregarestudiante(numero2);
            cout << "✅ \n"<< endl;
            break;
            case 6:
            cout << "Elminando estuidante numero1 del curso...\n"<< endl;
            curso1.eliminarestudiante(numero1);
            cout << "✅ \n"<< endl;
            break;
            case 7:
            cout << "AVISO:: TENGA EN CUENTA QUE EL CURSO ARRANCA VACIO (EJERCUTAR OPCION 5 SI QUIERE AGREGAR LOS ESTUDIANTES)" << endl;
            int legajo;
            cout << "Introduzca el legajo: \n"<< endl;
            cin >> legajo; 
            cout << "Buscando...\n";
            if (curso1.esta_en_la_lista(legajo)){
                cout << "True" << endl;
                break;;
            } else {
                cout << "False" << endl;
                break;
            }
            cout << "✅ \n";
            break;
            case 8:
            cout << "Imprimiendo en orden alfabetico...\n"<< endl;
            curso1.imprimir_en_orden_alfabetico();
            cout << "✅ \n"<< endl;
            break;
            case 9:
            cout << "Anaizando si esta el curso completo...\n"<< endl;
            if (curso1.curso_completo()){
                value = "True";
            } else{
                value = "False";
            };
            cout << value << endl;
            cout << "✅ \n"<< endl;
            break;
            case 10:
            cout << "Saliendo...\n";
            return; // o break + salir del while
            default:
                cout << "Opción inválida\n";
        }
    }
}
int main(){
    menu();
       
    return 0;

}
