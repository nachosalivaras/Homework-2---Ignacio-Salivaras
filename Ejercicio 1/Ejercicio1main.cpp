#include "Ejercicio1.hpp"

void verificarMomentoTiempo() {
    MomentoTiempo tiempo;
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n=== MENÚ DE VERIFICACIÓN MOMENTO TIEMPO ===\n";
        cout << "1. Crear MomentoTiempo sin parámetros (0h, 0m, 0s, a.m.)\n";
        cout << "2. Crear con hora\n";
        cout << "3. Crear con hora y minutos\n";
        cout << "4. Crear con hora, minutos y segundos\n";
        cout << "5. Crear con hora, minutos, segundos y a.m./p.m.\n";
        cout << "6. Cambiar hora, minutos, segundos o a.m./p.m.\n";
        cout << "7. Mostrar hora en formato 24 hs\n";
        cout << "8. Mostrar hora, minutos, segundos y a.m./p.m. individualmente\n";
        cout << "9. Mostrar todo el tiempo junto \n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        int h, m, s;
        string formato;

        switch (opcion) {
            case 1:
                tiempo = MomentoTiempo(); // constructor sin parámetros
                break;
            case 2:
                cout << "Ingrese hora (0-24): ";
                cin >> h;
                tiempo = MomentoTiempo(h);
                break;
            case 3:
                cout << "Ingrese hora: ";
                cin >> h;
                cout << "Ingrese minutos: ";
                cin >> m;
                tiempo = MomentoTiempo(h, m);
                break;
            case 4:
                cout << "Ingrese hora: ";
                cin >> h;
                cout << "Ingrese minutos: ";
                cin >> m;
                cout << "Ingrese segundos: ";
                cin >> s;
                tiempo = MomentoTiempo(h, m, s);
                break;
            case 5:
                cout << "Ingrese hora: ";
                cin >> h;
                cout << "Ingrese minutos: ";
                cin >> m;
                cout << "Ingrese segundos: ";
                cin >> s;
                cout << "Ingrese formato (a.m. o p.m.): ";
                cin >> formato;
                tiempo = MomentoTiempo(h, m, s, formato);
                break;
            case 6:
                cout << "Ingrese nueva hora: ";
                cin >> h;
                tiempo.setHora(h);
                cout << "Ingrese nuevos minutos: ";
                cin >> m;
                tiempo.setMinutos(m);
                cout << "Ingrese nuevos segundos: ";
                cin >> s;
                tiempo.setSegundos(s);
                cout << "Ingrese nuevo formato (a.m. o p.m.): ";
                cin >> formato;
                tiempo.setEsam(formato);
                break;
            case 7:
                tiempo.mostrarhoraformatoespecial();
                break;
            case 8:
                cout << "Hora: " << tiempo.getHora() << endl;
                cout << "Minutos: " << tiempo.getMinutos() << endl;
                cout << "Segundos: " << tiempo.getSegundos() << endl;
                cout << "Formato: " << tiempo.getEsam() << endl;
                break;
            
            case 9:
                tiempo.getTiempo();  
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    }
}

int main(){
    verificarMomentoTiempo();
    return 0;
}