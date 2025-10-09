#include "Cliente.h"

Cliente::Cliente(const long int& dni,char* nombre, const Fecha& f):f(f.getDia(),f.getMes(),f.getAnio())
{
    //ctor
}

Cliente::~Cliente()
{
    //dtor
}
