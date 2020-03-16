#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    int n=2;
    double v[]={1,2,1};
    Polinom pol1(v,n);
    cout<<"Primul polinom: ";
    pol1.afisare();
    int n2=1;
    double v2[]={0,1};
    Polinom pol2(v2,n2);
    cout<<"Al doilea polinom: ";
    pol2.afisare();
    
    Polinom pol3;
    pol3=pol1;
    cout<<"Atribuire polinom: ";
    pol3.afisare();
    
    Polinom pol4;
    double x=321;
    pol4=x;
    cout<<"Atribuire polinom cu double: ";
    pol4.afisare();
    
    cout<<"grad:"<<grad(pol1)<<"\n";
    
    cout<<pol1[7]<<"\n";
    pol1[7]=3;
    cout<<pol1[7]<<"\n";
    x=pol1[7];
    cout<<x<<"\n";
    cout<<"elem 7: "<<pol1[7]<<"\n"<<"Al doilea polinom: ";
    pol2.afisare();
    pol3=pol2-pol1;
    cout<<"scadere: ";
    pol3.afisare();
    pol3=pol1+pol2;
    cout<<"adunare: ";
    pol3.afisare();
    
    pol3=-pol2;
    cout<<"apelare -=: ";
    pol3.afisare();
    pol3=pol1*pol2;
    cout<<"inmultire: ";
    pol3.afisare();
    pol3=pol1/pol2;
    cout<<"impartire: ";
    pol3.afisare();
    pol3=pol1%pol2;
    cout<<"rest ";
    pol3.afisare();
            
}
