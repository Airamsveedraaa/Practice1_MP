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
bool existe=false;
while(i<ncli && !existe){
    if(this->clientes[i]->getDni()==dni){
        pos=i;
        existe=true;
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

void Empresa::crearContrato()
{
    long int dni;
    cout << "Introduzca el dni del cliente a dar de alta: " << endl;
    cin >> dni;

    int pos1=buscarCliente(dni);
    if(pos1==-1){

        int dia,mes,anio;
        char nombre[100];
        Cliente *C;
        cout << "Dime el nombre del cliente a dar de alta: ";
        cin >> nombre;
        cout << "Dime el dia,mes y anio del contrato:";
        cin >> dia,mes,anio;
        C=new Cliente(dni,nombre,Fecha(dia,mes,anio));
        int pos2=this->altaCliente(C);

        if(pos2=!-1){
        char contrato;
        cout << "Que tipo de contrato desea abrir, Tarifa Plana (T) o Movil (M)?";
        cin >> contrato;
        if(toupper(contrato)=='T'){
            int m,dia,mes,anio;
            ContratoTP *CP;
            cout << "Introduzca los minutos que quiere para llamadas: ";
            cin >> m;
            cout << "Introduzca el dia,mes y anio del contrato:";
            cin >> dia,mes,anio;
            CP=new ContratoTP(dni,Fecha(dia,mes,anio),m);

            //Reasignacion de tamano si esta lleno
            if(this->ncon==this->nmaxcon){
                nmaxcon*=2;
                Contrato **Aux=new Contrato*[ncon*2];
                for(int i=0; i<ncon;i++){
                    contratos[i]=Aux[i];
                }

                delete [] Aux;
            }
            this->contratos[ncon++]=CP;
        }
        else if (toupper(contrato)=='M'){
            float precio;
            int m,dia,mes,anio;
            char* nacionalidad;

            cout << "Dime el precio del contrato: ";
            cin >> precio;
            cout << "Dime el dia,mes y anio del contrato:";
            cin >> dia,mes,anio;
            cout << "Dime los minutos hablados:";
            cin >> m;
            cin.ignore();
            cout << "Dime la nacionalidad del cliente:";
            cin.getline(nacionalidad,100);

            ContratoMovil *CM;
            CM=new ContratoMovil(dni,Fecha(dia,mes,anio),precio,m,nacionalidad);
 //Reasignacion de tamano si esta lleno
            if(this->ncon==this->nmaxcon){
                nmaxcon*=2;
                Contrato **Aux2=new Contrato*[ncon*2];
                for(int i=0; i<ncon;i++){
                    contratos[i]=Aux2[i];
                }

                delete [] Aux2;
            }
            this->contratos[ncon++]=CM;
        }
    }
    }
    else{
        cout << "El cliente ya ha sido dado de alta en el sistema";
    }
}
