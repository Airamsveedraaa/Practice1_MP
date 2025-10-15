#include "Cliente.h"

Cliente::Cliente(const long int& dni,const char* nombre, const Fecha& f):f(f)
{
    this->dni=dni;

    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
    //ctor
}

Cliente::Cliente(const Cliente& c):f(c.f){

this->dni=c.dni;
this->nombre=new char[strlen(c.nombre)+1];
strcpy(this->nombre,c.nombre);

}

void Cliente::setNombre(const char* nombre){

delete [] this->nombre;
this->nombre=new char[strlen(nombre)+1];
strcpy(this->nombre,nombre);

}

long int Cliente::getDni()const{

return this->dni;

}

const char* Cliente::getNombre()const{

return this->nombre;

}

Fecha Cliente::getFecha()const{

return this->f;

}

void Cliente::setFecha(const Fecha& f){

this->f.setFecha(f.getDia(),f.getMes(),f.getAnio());

}

Cliente Cliente::operator=(const Cliente& c){

if(this!=&c){
    //si no es el mismo cliente hago la igualdad
    this->dni=c.dni;
    delete [] this->nombre;
    this->nombre=new char[strlen(c.nombre)+1];
    strcpy(this->nombre,c.nombre);
    this->f=c.f;
}

return *this;

}


bool Cliente::operator==(const Cliente& c) const{

if(this->dni!=c.dni)
    return false;
if(strcmp(this->nombre,c.nombre)!=0)
    return false;
if(this->f.getDia()!=c.f.getDia() || this->f.getMes()!=c.f.getMes() || this->f.getAnio()!=f.getAnio())
    return false;
return true;

}

ostream& operator <<(ostream& s,const Cliente& c){

s << c.getNombre() << "(" << c.getDni() << " - ";
c.getFecha().ver(s);
s << ")";

return s;
}

Cliente::~Cliente()
{
    delete [] this->nombre;
    //dtor
}
