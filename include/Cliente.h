#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h"

class Cliente
{
private:
    long int dni;
    char* nombre;
    Fecha f;
    public:
        Cliente(const long int& dni,const char* nombre,const Fecha& f);
        void setNombre(char* nombre);
        long int getDni()const;
        char* getNombre()const;
        Fecha getFecha()const;
        void setFecha(const Fecha& f);
        Cliente operator=(const Cliente& c);
        bool operator==(const Cliente& c) const;
        friend ostream& operator<<(ostream& s,const Cliente& c);
        virtual ~Cliente();

};

ostream& operator<<(ostream& s,const Cliente& c);

#endif // CLIENTE_H
