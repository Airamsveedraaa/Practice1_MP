#include "ContratoMovil.h"

ContratoMovil::ContratoMovil(const long int&dni,const Fecha& f,const float& p,const int& m,const char* nac):Contrato(dni,f)
{
    this->precio=p;
    this->minutosHablados=m;
    this->nacionalidad=new char[strlen(nac)+1];
    strcpy(this->nacionalidad,nac);
    //ctor
}

ContratoMovil::ContratoMovil(const ContratoMovil& c):Contrato(c)
{

delete [] this->nacionalidad;
this->nacionalidad=new char[strlen(c.nacionalidad)+1];
strcpy(this->nacionalidad,c.nacionalidad);
this->precio=c.precio;
this->minutosHablados=c.minutosHablados;

}


float ContratoMovil::factura()const{

return this->precio*this->minutosHablados;

}

void ContratoMovil::ver()const{

Contrato::ver();

cout << " " << this->minutosHablados << "m, " << this->nacionalidad << " " << this->precio;

}

void ContratoMovil::ver(ostream& s)const{

s << this->getDniContrato() << "(" << this->getIdContrato() << " - ";
this->getFechaContrato().ver(s);
s << ") " << this->minutosHablados << "m, " << this->nacionalidad
  << " " << fixed << setprecision(2) << this->precio << " - "
  << this->factura() << "€";

}

void ContratoMovil::setNacionalidad(const char* nac){

delete [] this->nacionalidad;

this->nacionalidad=new char(strlen(nac)+1);
strcpy(this->nacionalidad,nac);

}

ostream& operator<<(ostream& s,const ContratoMovil& c){

c.ver(s);
return s;


}

ContratoMovil::~ContratoMovil()
{
    delete [] this->nacionalidad;
    //dtor
}
