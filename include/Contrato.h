#ifndef CONTRATO_H
#define CONTRATO_H
#include "Comun.h"
#include "Fecha.h"
class Contrato
{
private:
    static int idContrato;
    long int dniContrato;
    Fecha fechaContrato;
    public:
        Contrato(const long int &dni,const Fecha &fechaContrato);
        Contrato(const Contrato &c);
        static int getLimiteMniutos();
        static int getPrecio();
        virtual ~Contrato();
        virtual void ver() const=0;
        static int getIdContrato();

};

#endif // CONTRATO_H
