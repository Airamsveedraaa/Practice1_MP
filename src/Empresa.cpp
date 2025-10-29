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
    while(i<ncli && !existe)
    {
        if(this->clientes[i]->getDni()==dni)
        {
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
    if(pos1==-1)
    {
        //El cliente no ha sido dado de alta, se hace manualmente

        int dia,mes,anio;
        char nombre[100];
        Cliente *C;
        cout << "Dime el nombre del cliente a dar de alta: ";
        cin >> nombre;
        cout << "Dime el dia,mes y anio del contrato:";
        cin >> dia,mes,anio;
        C=new Cliente(dni,nombre,Fecha(dia,mes,anio));
        int pos2=this->altaCliente(C);

        if(pos2=!-1)
        {
            //Si la posicion es distinta de -1 quiere decir que se ha podido dar de alta en la posicion pos2
            //Pasamos a preguntar el tipo de contrato
            char contrato;
            cout << "Que tipo de contrato desea abrir, Tarifa Plana (T) o Movil (M)?";
            cin >> contrato;
            if(toupper(contrato)=='T')
            {
                int m,dia,mes,anio;
                ContratoTP *CP;
                cout << "Introduzca los minutos que quiere para llamadas: ";
                cin >> m;
                cout << "Introduzca el dia,mes y anio del contrato:";
                cin >> dia,mes,anio;
                CP=new ContratoTP(dni,Fecha(dia,mes,anio),m);

                //Reasignacion de tamano si esta lleno
                if(this->ncon==this->nmaxcon)
                {
                    nmaxcon*=2;
                    Contrato **Aux=new Contrato*[ncon*2];
                    for(int i=0; i<ncon; i++)
                    {
                        contratos[i]=Aux[i];
                    }

                    delete [] Aux;
                }
                this->contratos[ncon++]=CP;
            }
            else if (toupper(contrato)=='M')
            {
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
                if(this->ncon==this->nmaxcon)
                {
                    nmaxcon*=2;
                    Contrato **Aux2=new Contrato*[ncon*2];
                    for(int i=0; i<ncon; i++)
                    {
                        contratos[i]=Aux2[i];
                    }

                    delete [] Aux2;
                }
                this->contratos[ncon++]=CM;
            }
        }
    }
    else
    {
        cout << "El cliente ya ha sido dado de alta en el sistema";
    }
}


bool Empresa::cancelarContrato(int idContrato)
{

    bool encontrado=true;

    int i=0;

    while(i<ncon && !encontrado)
    {
        if(contratos[i]->getIdContrato()==idContrato)
        {
            encontrado=true;
            delete this->contratos[i];
            for(int j=i+1; j<ncon; j++)
            {
                contratos[j-1]=contratos[j];
            }
            ncon--;
        }
        i++;
    }

    if(ncon < nmaxcon/2)
    {
        nmaxcon/=2;
        Contrato **Aux=new Contrato*[nmaxcon];
        for(int i=0; i<ncon; i++)
        {
            Aux[i]=contratos[i];
        }
        delete [] this->contratos;
        contratos=Aux;
    }

    return encontrado;

}


bool Empresa::bajaCliente(long int dni)
{

    bool encontrado=false;
    int i=0;

    //primero dar de baja el contrato de dicho cliente
    while(i<ncon){
        if(contratos[i]->getDniContrato()==dni){
            cancelarContrato(contratos[i]->getIdContrato());
        }
        i++;
    }

    while(i<ncli && !encontrado)
    {
        if(clientes[i]->getDni()==dni)
        {
            encontrado=true;
            delete this->clientes[i];
            ncli--;
        }
        i++;
    }

    return encontrado;
}


int Empresa::nContratosTP()const{

int contador=0;

int i=0;

while(i<ncon){
    if(typeid(*contratos[i])==typeid(ContratoTP)){
        //si coincide quiere decir que el contrato es del tipo q busco
        //incrementar contador
        contador++;
    }
    i++;
}
return contador;
}


int Empresa::descuento(float porcentaje)const{


int contador=0;

porcentaje=1- porcentaje/100;

int i=0;
while(i<ncon){
    if(ContratoMovil *c= dynamic_cast<ContratoMovil*>(contratos[i])){
       c->setPrecioMinuto(c->getPrecioMinuto()*porcentaje);
       contador++;
       }
       i++;
    }
return contador;
}


void Empresa::cargarDatos() {
 Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
 this->clientes[0] = new Cliente(75547001, "Peter Lee", f1);
 this->clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));
 this->clientes[2] = new Cliente(37000017, "Luis Bono", f2);
 this->ncli=3;
 this->contratos[0] = new ContratoMovil(75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m
 this->contratos[1] = new ContratoMovil(75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m
 this->contratos[2] = new ContratoTP(37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)
 this->contratos[3] = new ContratoTP(75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)
 this->contratos[4] = new ContratoMovil(45999000, f2, 0.10, 202, "ESPAÑOL"); //habla 202m a 0.10/m
 this->contratos[5] = new ContratoMovil(75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m
 this->contratos[6] = new ContratoTP(45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)
 this->ncon=7;
}
