#include "Empresa.h"

Empresa::Empresa():nmaxcli(100)
{
    this->ncli=0;
    this->ncon=0;
    this->contratos=new Contrato*[10];
    this->nmaxcon=10;
    //ctor
}

Empresa::~Empresa()
{
    for(int i=0; i<this->ncon; i++)
    {
        delete this->contratos[i];
    }
    delete [] this->contratos;

    for(int i=0; i<this->ncli; i++)
    {
        delete this->clientes[i];
    }
    //dtor
}


int Empresa::buscarCliente(long int dni)const
{

int pos=-1;
int i=0;
while(i<nmaxcli && this->clientes[i]!=NULL){
    if(this->clientes[i]->getDni()==dni){
        pos=i;
    }
    i++;
}
return pos;
}

int Empresa::altaCliente(Cliente *c)
{

    int pos=-1;
    if(this->ncli<nmaxcli)
    {
        this->clientes[this->ncli]=c;
        pos=this->ncli;
        this->ncli++;
    }
    else
        cout << "Lo siento, cupo de clientes lleno";
             pos=-1;

    return pos;
}
