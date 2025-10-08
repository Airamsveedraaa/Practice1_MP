#include <iostream>
#include "Fecha.h"

int main()
{
Fecha f1(29,2,2001), f3(29,2,2004), f4(29,2,1900); //Fecha f5; //no permitido
 const Fecha f2=f1; //indica que metodo se esta ejecutando aqui
 f1.setFecha(f3.getDia()-3, f3.getMes()-2, 2007); //29-3/2-2/2007 --> f1=26/1/2007
 cout << "Fechas: "; f1.ver(); cout << ", "; f2.ver(); cout << ", ";
 f3.ver(); cout << ", "; f4.ver(); cout << endl;
 if (f3.bisiesto() && !f2.bisiesto() && f4.bisiesto()==false)
 cout << f3.getAnio() << " es bisiesto, " << f2.getAnio() << " y " << f4.getAnio() << " no\n";
 f4.setFecha(31, 12, 2000); //f4=31/12/2000
 f3=f4++; //indica que método/s se esta ejecutando aqui
 ++f4;
 f1=2+f2+3;
 cout << "Fechas: "; f1.ver(); cout << ", "; f2.ver(); cout << ", ";
 f3.ver(); cout << ", "; f4.ver(); cout << endl;

    return 0;
}
