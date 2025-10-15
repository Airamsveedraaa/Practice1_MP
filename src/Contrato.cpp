#include "Contrato.h"

int Contrato::idContrato=0;

Contrato::Contrato(const long int& dni,const Fecha& fechaContrato):fechaContrato(fechaContrato)
{
    idContrato++;
    this->dniContrato=dni;
    //ctor
}

Contrato::Contrato(const Contrato& c):fechaContrato(c.fechaContrato){


}

Contrato::~Contrato()
{
    //dtor
}
