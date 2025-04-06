#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#ifndef Numero_HPP
#define Numero_HPP
using namespace std;

class Numero{
    public:
    virtual shared_ptr<Numero> sumar (const shared_ptr<Numero>& otronum) const = 0;
    virtual shared_ptr<Numero> restar (const shared_ptr<Numero>& otronum) const = 0;
    virtual shared_ptr<Numero> multiplicar(const shared_ptr<Numero>& otronum) const = 0;
    virtual string toString() const = 0;
    virtual ~Numero() {};
};



#endif