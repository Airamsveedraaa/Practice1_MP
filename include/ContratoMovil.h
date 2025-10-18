#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H
#include <Contrato.h>


class ContratoMovil : public Contrato
{
private:
    char* nacionalidad;
    float precio;
    int minutosHablados;
    public:
        ContratoMovil(const long int& dni,const Fecha& f,const float& p, const int& m, const char* nac);
        virtual ~ContratoMovil();
        ContratoMovil(const ContratoMovil& c);
        float getPrecioMinuto()const{return this->precio;};
        int getMinutosHablados()const{return this->minutosHablados;};
        const char* getNacionalidad()const{return this->nacionalidad;};
        void setPrecioMinuto(const float precioM){this->precio=precioM;};
        void setMinutosHablados(int m){this->minutosHablados=m;};
        void setNacionalidad(const char* nac);
        void ver()const;
        void ver(ostream& s) const;
        float factura() const;
        friend ostream& operator<<(ostream& s,const ContratoMovil& c);
};

    ostream& operator<<(ostream& s,const ContratoMovil& c);

#endif // CONTRATOMOVIL_H
