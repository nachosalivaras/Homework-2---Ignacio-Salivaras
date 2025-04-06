#include "Ejercicio1.hpp"

int MomentoTiempo::ChequearFormatoHora(int _hora) {
    while (_hora < 0 || _hora > 24) {
        std::cout << "Hora inválida. Debe estar entre 0 y 24.\n";
        std::cout << "Ingrese la hora nuevamente: ";
        std::cin >> _hora;
    }

    if (_hora == 24) {
        return 0;
    } else {
        return _hora;
    }
}
int MomentoTiempo::ChequearFormatoSegundosMinutos(int valor, const string& segundos_minutos) {
    while (valor < 0 || valor > 59) {
        std::cout << segundos_minutos << " inválido. Debe estar entre 0 y 59.\n";
        std::cout << "Ingrese " << segundos_minutos << " nuevamente: ";
        std::cin >> valor;
    }
    return valor;
}
MomentoTiempo::MomentoTiempo(){
    hora = 0;
    minutos = 0;
    segundos = 0;
}
MomentoTiempo::MomentoTiempo(int _hora){
    hora = ChequearFormatoHora(_hora);
    minutos = 0;
    segundos = 0;
}
MomentoTiempo::MomentoTiempo(int _hora, int _minutos){
    hora = ChequearFormatoHora(_hora);
    minutos = ChequearFormatoSegundosMinutos(_minutos, "Minutos");
    segundos = 0;
}
MomentoTiempo::MomentoTiempo(int _hora, int _minutos, int _segundos) {
    hora = ChequearFormatoHora(_hora);
    minutos = ChequearFormatoSegundosMinutos(_minutos, "Minutos");
    segundos = ChequearFormatoSegundosMinutos(_segundos, "Segundos");
}
MomentoTiempo::MomentoTiempo(int _hora, int _minutos, int _segundos, const string& _isam_) {
    hora = ChequearFormatoHora(_hora);
    minutos = ChequearFormatoSegundosMinutos(_minutos, "Minutos");
    segundos = ChequearFormatoSegundosMinutos(_segundos, "Segundos");
    if (_isam_ == "p.m."){
        esam = false;
    } else{
        esam = true;
    }
}
int MomentoTiempo::getHora() const { return hora; }
int MomentoTiempo::getMinutos() const { return minutos; }
int MomentoTiempo::getSegundos() const { return segundos; }
string MomentoTiempo::getEsam() const {
    if (esam)
        return "a.m.";
    else
        return "p.m.";
}
void MomentoTiempo::setHora(int h) { 
    hora = ChequearFormatoHora(h);
}
void MomentoTiempo::setMinutos(int m) {
    minutos = ChequearFormatoSegundosMinutos(m, "Minutos");
}
void MomentoTiempo::setSegundos(int s) { 
    segundos = ChequearFormatoSegundosMinutos(s, "Segundos");
}
void MomentoTiempo::setEsam(string formato) {
    while (formato != "a.m." && formato != "p.m.") {
        std::cout << "Formato inválido. Debe ser 'a.m.' o 'p.m.'\n";
        std::cout << "Ingrese el formato horario nuevamente: ";
        std::cin >> formato;
    }

    esam = (formato == "a.m.");
}
void MomentoTiempo::getTiempo() {
    cout << setfill('0') << setw(2) << hora << ":"
        << setfill('0') << setw(2) << minutos << ":"
        << setfill('0') << setw(2) << segundos <<
        (esam ? "a.m." : "p.m.") << endl;
}
void MomentoTiempo::mostrarhoraformatoespecial() const {
    cout << "Hora actual: ";
    if (hora < 10)
    cout << "0";
    cout << hora << ":";
    if (minutos < 10)
        std::cout << "0";
    cout << minutos << ":";
    if (segundos < 10)
        std::cout << "0";
    cout << segundos << endl;
}
