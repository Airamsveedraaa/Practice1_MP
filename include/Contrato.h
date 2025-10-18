#ifndef CONTRATO_H
#define CONTRATO_H
#include "Comun.h"
#include "Fecha.h"
class Contrato
{
private:
    static int contador;
    const int idContrato;
    long int dniContrato;
    Fecha fechaContrato;
    public:
        Contrato(const long int& dni,const Fecha &fechaContrato);
        Contrato(const Contrato &c);
        virtual ~Contrato();
        virtual void ver(ostream& s)const;
        virtual float factura()const=0;
        static int getIdContrato(){return Contrato::contador;};
        long int getDniContrato() const{return this->dniContrato;};
        const Fecha& getFechaContrato() const{return this->fechaContrato;};
        void setDniContrato(const long int& dni);
        void setFechaContrato(const Fecha& f);
        friend ostream& operator<<(ostream& s,const Contrato& c);

};
ostream& operator<<(ostream& s,const Contrato& c);
#endif // CONTRATO_H
