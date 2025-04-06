#include <iostream>
#include <iomanip>
#include <string>
#ifndef MOMENTOTIEMPO_H
#define MOMENTOTIEMPO_H
using namespace std;

class MomentoTiempo {
private:
    int hora;
    int minutos;
    int segundos;
    bool esam = true;
    static int ChequearFormatoHora(int _hora);
    static int ChequearFormatoSegundosMinutos(int _hora, const string& segundos_minutos);
public:
    MomentoTiempo();
    MomentoTiempo(int _hora);
    MomentoTiempo(int _hora, int _minutos);
    MomentoTiempo(int _hora, int _minutos, int _segundos); 
    MomentoTiempo(int _hora, int _minutos, int _segundos, const std :: string& _esam_);
    int getHora() const;
    int getMinutos() const;
    int getSegundos() const;
    string getEsam() const;
    void getTiempo(); 
    void setHora(int h);
    void setMinutos(int m);
    void setSegundos(int s);
    void setEsam(string formato);
    void mostrarhoraformatoespecial() const;


    // Podrías agregar otros métodos aquí si los necesitas
};
#endif