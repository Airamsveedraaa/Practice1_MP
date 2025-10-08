#include "Fecha.h"


Fecha::Fecha(const int &dia,const int &mes,const int &anio)
{
    setFecha(dia,mes,anio);
    //ctor
}

Fecha::getAnio()const
{

    return this->anio;

}

Fecha::getDia()const
{

    return this->dia;

}

Fecha::getMes()const
{

    return this->mes;

}

void Fecha::setFecha(const int &dia,const int &mes,const int &anio)
{

    int dmax,diaMes[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    this->anio=anio;
    if(this->bisiesto())
        diaMes[2]=29;
    if(mes<1)
        this->mes=1;
    else if(mes>12)
        this->mes=12;
    else
        this->mes=mes;
    dmax=diaMes[this->mes];

    if(dia>dmax)
        this->dia=dmax;
    else if(dia<1)
        this->dia=1;
    else
        this->dia=dia;
}

void Fecha::ver()const
{
    if(this->dia <10 )
        cout << "0";
    cout << this->dia << "/";
    if(this->mes <10)
        cout << "0";
    cout << this->mes << "/" << this->anio;


}

bool Fecha::bisiesto()const
{

    if(this->anio%400==0 || this->anio%4==0 && this->anio%100!=0)
        return true;
    else
        return false;

}

Fecha Fecha::operator++(int)
{

    Fecha incr=*this;
    ++*this;
    return incr;

}

Fecha& Fecha::operator++()
{

    int dmax,diaMes[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->bisiesto())
        diaMes[2]=29;
    dmax=diaMes[this->mes];
    this->dia++;
    if(this->dia > dmax)
    {
        this->dia=1;
        this->mes++;
        if(this->mes > 12)
        {
            this->mes=1;
            this->anio++;
        }
    }
    return *this;
}

Fecha Fecha::operator+(int x)const
{

    Fecha incr=*this;
    int diaMes[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0; i<x; i++)
    {
        if(incr.bisiesto())
            diaMes[2]=29;
        else
            diaMes[2]=28;
        int dMax=diaMes[incr.mes];
        incr.dia++;
        if(incr.dia > dMax)
        {
            incr.dia=1;
            incr.mes++;
            if(incr.mes > 12)
            {
                incr.mes=1;
                incr.anio++;
            }
        }
    }
    return incr;
}

Fecha Fecha::operator+(const Fecha& f)const{

Fecha incr=*this;
incr.dia+=f.dia;
incr.mes+=f.mes;
incr.anio+=f.anio;

return incr;

}

Fecha operator+(int x,const Fecha& f)
{
    return f+x;
}
Fecha::~Fecha()
{
    //dtor
}
