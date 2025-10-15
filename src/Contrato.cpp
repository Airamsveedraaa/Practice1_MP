#include "Contrato.h"

int Contrato::contador=1;

Contrato::Contrato(const long int& dni,const Fecha& fechaContrato):fechaContrato(fechaContrato),idContrato(contador)
{
    contador++;
    this->dniContrato=dni;
    //ctor
}

Contrato::Contrato(const Contrato& c):fechaContrato(c.fechaContrato),idContrato(c.idContrato){

this->dniContrato=c.dniContrato;

}

void Contrato::ver(ostream& s)const{

s <<this->dniContrato << "(" << this->idContrato << "-";
 this->fechaContrato.ver();
s << ")";

}

ostream& operator<<(ostream& s,const Contrato& c){

c.ver(s);
return s;

}

int Contrato::getIdContrato(){

return contador;

}


long int Contrato::getDniContrato()const{

return this->dniContrato;

}

const Fecha& Contrato::getFechaContrato()const{

return this->fechaContrato;

}

void Contrato::setDniContrato(const long int& dni){

this->dniContrato=dni;

}

void Contrato::setFechaContrato(const Fecha& f){

this->fechaContrato.setFecha(f.getDia(),f.getMes(),f.getAnio());

}


Contrato::~Contrato()
{
    //dtor
}
