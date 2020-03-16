#include <iostream>
#ifndef DATE_H
#define DATE_H
using namespace std;

class Polinom
{
        private:
            int n;                                                              //gradul polinomului
            double v[100];                                                      //vector de coeficienti
        public:
            double *get_coef(){return v;};         
            int get_n(){return n;};         
            void set_coef(double w[]){for(int i=0;i<=n;i++)w[i]=v[i];}
            void set_n(int m){m=n;};
            void citire(double coef[100],int grad);                             //functie de citire
            void afisare();                                                     //functie de afisare
            Polinom(){n=-1;};                                                   //constructor vid
            Polinom(double v1[],int n1) {n=n1; for(int i=0;i<=n;i++)v[i]=v1[i];}//constructor de initializare
            Polinom(const Polinom &pol);                                        //constructor de copiere
            Polinom(double i) {v[0]=i;n=0;}                                     //constructor de copiere pentru double
            Polinom& operator =(const Polinom &q);                              //supraincarcare operator =
            Polinom& operator =(double x);                                      //supraincarcare operator = pentru double
            friend double grad(Polinom p);                                      //functie pentru grad
            double& operator[](int i);                                          //supraincarcare operatori
            double operator()(double i);                                       
            friend Polinom operator +(Polinom q,Polinom p);                     
            friend Polinom operator +(Polinom p);                              
            friend Polinom operator -(Polinom q,Polinom p);                     
            friend Polinom operator -(Polinom p);                              
            friend Polinom operator *(Polinom p,Polinom q);                    
            friend Polinom operator /(Polinom p,Polinom q);                     
            friend Polinom operator %(Polinom p,Polinom q);                     
            friend Polinom operator ^(Polinom p,Polinom q);                     
            Polinom & operator += (double &);                                   
            Polinom & operator += (const Polinom &);
            Polinom & operator -= (const Polinom &);
            Polinom & operator *= (const Polinom &);
            Polinom & operator /= (const Polinom &);                            //aici am avut niste probleme si a trebuit sa folosesc 3 obiecte diferite pe langa cele necesare
            friend bool operator== (Polinom p, Polinom q);
            friend bool operator!= (Polinom p, Polinom q);
            friend bool operator! (Polinom p);
            friend ostream& operator<<(ostream&, const Polinom&);
            friend istream& operator>>(istream&, Polinom&);
        };
        
#endif
