#ifndef CONTRATOTP_H
#define CONTRATOTP_H
#include <Contrato.h>


class ContratoTP : public Contrato
{
private:
    static float precioTP;
    static int minutosTP;
    int minutosHablados;
    static const float precioExcesoMinutos;
    public:
        ContratoTP(const long int& dni,const Fecha& f,const int& m);
        virtual ~ContratoTP();


};

#endif // CONTRATOTP_H
