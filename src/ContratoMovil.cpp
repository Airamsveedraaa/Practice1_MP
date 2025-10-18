#include "ContratoMovil.h"

ContratoMovil::ContratoMovil(const long int&dni,const Fecha& f,const float& p,const int& m,const char* nac):Contrato(dni,f)
{
    this->precio=p;
    this->minutosHablados=m;
    this->nacionalidad=new char[strlen(nac)+1];
    strcpy(this->nacionalidad,nac);
    //ctor
}

ContratoMovil::ContratoMovil(const ContratoMovil& c):Contrato(c.getDniContrato(),c.getFechaContrato())
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

ver(cout);

}

void ContratoMovil::ver(ostream& s)const{

Contrato::ver(s);

s << " " << this->minutosHablados << "m, " << this->nacionalidad << " " << this->precio;

}

void ContratoMovil::setNacionalidad(const char* nac){

delete [] this->nacionalidad;

this->nacionalidad=new char(strlen(nac)+1);
strcpy(this->nacionalidad,nac);

}

ostream& operator<<(ostream& s,const ContratoMovil& c){

s << (Contrato &)c;
s << " " << c.getMinutosHablados() << "m, " << c.getNacionalidad() << " " << c.getPrecioMinuto() << " - " ;
s << c.factura() << "€";
return s;


}

ContratoMovil::~ContratoMovil()
{
    //dtor
}
