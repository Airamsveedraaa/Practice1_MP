#include "ContratoTP.h"

float ContratoTP::precioTP=10;
int ContratoTP::minutosTP=300;
const float ContratoTP::precioExcesoMinutos=0.15;


ContratoTP::ContratoTP(const long int& dni,const Fecha& f,const int& m):Contrato(dni,f)
{
    this->minutosHablados=m;
    //ctor
}

ContratoTP::ContratoTP(const ContratoTP& c):Contrato(c.getDniContrato(),c.getFechaContrato())
{

    this->minutosHablados=c.minutosHablados;

}

float ContratoTP::factura()const
{

    float exceso=0;
    if(minutosHablados > minutosTP)
        exceso=(minutosHablados-minutosTP)*precioExcesoMinutos;
    return precioTP + exceso;

}

void ContratoTP::ver()const{

ver(cout);

}

void ContratoTP::ver(ostream& s)const
{

    Contrato::ver(s);
    s<<" " << minutosHablados << "m, " << minutosTP << "(" << precioTP << ")";

}

ostream& operator<<(ostream& s,const ContratoTP& c){

s << (Contrato &)c;
s << " - " << c.factura() << "€";
return s;

}

ContratoTP::~ContratoTP()
{
    //dtor
}
