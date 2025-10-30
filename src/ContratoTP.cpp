#include "ContratoTP.h"

float ContratoTP::precioTP=10;
int ContratoTP::minutosTP=300;
const float ContratoTP::precioExcesoMinutos=0.15;

ContratoTP::ContratoTP(const long int& dni,const Fecha& f,const int& m):Contrato(dni,f)
{
    this->minutosHablados=m;
}

ContratoTP::ContratoTP(const ContratoTP& c):Contrato(c)
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

void ContratoTP::ver()const
{
    Contrato::ver();
    cout << " " << this->minutosHablados << "m, " << ContratoTP::minutosTP
         << "(" << ContratoTP::precioTP << ")";
}

void ContratoTP::ver(ostream& s)const
{
    s << this->getDniContrato() << " (" << this->getIdContrato() << " - ";
    this->getFechaContrato().ver(s);
    s << " ) " << this->minutosHablados << "m, " << ContratoTP::minutosTP
      << "(" << fixed << setprecision(2) << ContratoTP::precioTP << ") - "
      << this->factura() << "€";
}

ostream& operator<<(ostream& s,const ContratoTP& c)
{
    c.ver(s);
    return s;
}

ContratoTP::~ContratoTP()
{
}
