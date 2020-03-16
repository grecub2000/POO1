#include <iostream>
#include "Date.h"
using namespace std;

        void Polinom::citire(double coef[100], int grad)
        { int i;
            grad=n;
            for(i=0;i<=n;i++)
            {
                    coef[i]=v[i];
                }
        }
            
        void Polinom::afisare()
        { int i;
                cout<<v[0];
                for(i=1;i<=n;i++)
                {
                    if(v[i]>0)
                    {   if(v[i]!=1){
                            cout<<" + "<<v[i]<<"x^"<<i;
                        }
                        else{
                            if(v[i]==1){
                                cout<<" + "<<"x^"<<i;
                            }
                        }
                    
                    }
                    else{
                        if(v[i]<0){
                            if(v[i]!=-1){
                                cout<<" - "<<-v[i]<<"x^"<<i;
                            }
                            else{
                                if(v[i]==-1){
                                    cout<<" - "<<"x^"<<i;
                                }
                            }
                        }
                    }
                }
                cout<<"\n";
            }
            
        Polinom::Polinom(const Polinom &pol)
        {   n=pol.n;
                for(int i=0; i<=n;i++)
                {
                    v[i]=pol.v[i];
                }
                
            }
    
        Polinom& Polinom::operator=(const Polinom &q)
            {
                    if (this != &q){
                        this->n=q.n;
                        for(int i=0;i<=q.n;i++){
                            this->v[i]=q.v[i];
                        }
                    }
                    
                    return *this;
                }
        Polinom& Polinom::operator= (double x)
            {
                    if (this->n != x){
                        this->n=0;
                        this->v[0]=x;
                        }
                    
                    return *this;
    
                }
                
            
        double grad(Polinom p){
                return p.n;
            }
            
        double& Polinom::operator[](int i) {  
                    
                    return v[i]; 
                } 
            
        double Polinom::operator()(double i) {  
                    double suma=0;
                    double x;
                    for(int j=0;j<=n;j++){
                        double y=v[j];
                        x=1;
                        for(int k=1;k<=j;k++){
                            x=x*i;
                        }
                        suma=suma+y*x;
                    }
                    return suma;
                } 
                
        Polinom operator +(Polinom p,Polinom q){
                Polinom rez;
                double x=p.n;
                double y=q.n;
                if(x>=y){
                    rez.n=x;
                }
                else{
                    rez.n=y;
                }
                for(int i=0;i<=rez.n;i++){
                            if(y<i){
                            rez.v[i]=p.v[i];
                        }
                            else
                                if(x<i){
                                    rez.v[i]=q.v[i];
                                }
                                else{
                                     rez.v[i]=p.v[i]+q.v[i];
                                }
                        if((p.v[i]==0||q.v[i]==0)&&(y<i||x<i)){
                            rez.v[i]=0;
                        }
                }
                return rez; 
            }
            
        Polinom operator +(Polinom p){
                return Polinom(p.v,p.n);
            } 
            
        Polinom operator -(Polinom p,Polinom q){
                Polinom rez;
                double x=p.n;
                double y=q.n;
                if(x>=y){
                    rez.n=x;
                }
                else{
                    rez.n=y;
                }
                for(int i=0;i<=rez.n;i++){
                            if(y<i){
                            rez.v[i]=p.v[i];
                        }
                            else
                                if(x<i){
                                    rez.v[i]=-q.v[i];
                                }
                                else{
                                     rez.v[i]=p.v[i]-q.v[i];
                                }
                        if((p.v[i]==0||q.v[i]==0)&&(y<i||x<i)){
                            rez.v[i]=0;
                        }
                }
                
                while(rez.v[rez.n]==0)
                {
                    rez.n--;
                }
                return rez; 
            }
            
        Polinom operator -(Polinom p){
                for(int i=0;i<=p.n;i++){
                    p.v[i]=-p.v[i];
                }
                
                return Polinom(p.v,p.n);
            }
            
        Polinom operator *(Polinom p,Polinom q){
                Polinom rez;
                rez.n=p.n+q.n;
                for(int i=0;i<=rez.n;i++){
                    rez.v[i]=0;
                }
                for(int i=0;i<=p.n;i++){
                    for(int j=0;j<=q.n;j++){
                        rez.v[i+j]=rez.v[i+j]+p.v[i]*q.v[j];
                    }    
                        
                    
                }
                return rez; 
            }
            
        Polinom operator /(Polinom p,Polinom q){
                Polinom rez;
                Polinom aux;
                aux.n=p.n;
                rez.n=p.n-q.n;
                if(p.n<q.n){
                    return Polinom({0},0);
                }
                    else{
                        while(p.n>=q.n){
                            for(int i=0;i<=p.n;i++){
                                aux.v[i]=0;
                            }
                            aux[p.n-q.n]=p.v[p.n]/q.v[q.n];
                            rez=rez+aux;
                            p=p-aux*q;
                        }
                        
                    }
                    return rez;
            }
                    
        Polinom operator %(Polinom p,Polinom q){
            return p-q*(p/q);
        }    
        
        Polinom operator ^(Polinom p,int i){
            Polinom rez=p;
            for(int j=1;j<i;j++){
                rez=rez*p;
            }
            return rez;
        }
        
        Polinom& Polinom::operator +=(const Polinom &q){
                double x=n;
                double y=q.n;
                if(x<y){
                    n=y;
                }
                for(int i=0;i<=n;i++){
                            if(x<i){
                                v[i]=q.v[i];
                            }
                            else{
                                v[i]=v[i]+q.v[i];
                            }
                    if((v[i]==0||q.v[i]==0)&&(y<i||x<i)){
                        v[i]=0;
                    }
                }
                return *this; 
            }
        
        Polinom& Polinom::operator -=(const Polinom &q){
                double x=n;
                double y=q.n;
                if(x<y){
                    n=y;
                }
                for(int i=0;i<=n;i++){
                            if(x<i){
                                v[i]=-q.v[i];
                            }
                            else{
                                v[i]=v[i]-q.v[i];
                            }
                    if((v[i]==0||q.v[i]==0)&&(y<i||x<i)){
                        v[i]=0;
                    }
                }
                return *this; 
            }
        Polinom& Polinom::operator *=(const Polinom &q){
                Polinom rez;
                rez.n=n+q.n;
                for(int i=0;i<=rez.n;i++){
                    rez.v[i]=0;
                }
                for(int i=0;i<=n;i++){
                    for(int j=0;j<=q.n;j++){
                        rez.v[i+j]=rez.v[i+j]+v[i]*q.v[j];
                    }    
                        
                    
                }
                n=rez.n;
                for(int i=0;i<=n;i++){
                    v[i]=rez.v[i];
                }
                return *this; 
            }    
            
        Polinom& Polinom::operator /=(const Polinom &q){                          
                Polinom rez;
                Polinom aux;
                Polinom aux2;
                aux2.n=n;
                for(int i=0;i<=n;i++){                                  
                    aux.v[i]=v[i];
                }
                aux.n=n;
                rez.n=n-q.n;


                        while(aux2.n>=q.n){
                            for(int i=0;i<=aux2.n;i++){
                                aux.v[i]=0;
                            }
                            aux[aux2.n-q.n]=aux2.v[n]/q.v[q.n];
                            rez=rez+aux;
                            aux2=aux2-aux*q;
                        }
                        
                n=aux2.n;
                for(int i=0;i<=n;i++){
                    v[i]=aux2.v[i];
                }
                return *this; 
            }    
            
        bool operator ==(Polinom p, Polinom q){
                if(p.n!=q.n){
                    return 0;
                }
                else{
                    for(int i=0;i<=p.n;){
                        if(p.v[i]!=q.v[i]){
                            return 0;
                        }
                    }
                }
                return 1;
        }
        
        bool operator !=(Polinom p, Polinom q){
                if(p.n==q.n){
                    return 0;
                }
                else{
                    for(int i=0;i<=p.n;){
                        if(p.v[i]==q.v[i]){
                            return 0;
                        }
                    }
                }
                return 1;
            }
        
        bool operator !(Polinom p){
                if(p.n==0&&p.v[0]==0)
                return 0;
            }
        
        ostream& operator<<(ostream& out, const Polinom& p){
            out << p.v[0];
            for(int i = 1; i <= p.n; i++){
                out << ", " << p.v[i];
            }
            return out;
        }
        istream& operator>>(istream &in, Polinom& p){
            int n;
            cout<<"n = ";
            in>>n;
            p.n=n;
            for (int i = 0; i < n; i++){
                in>>p.v[i];
            }
            return in;
        }
        void citire_array(Polinom v[100],int n){
            cout<<"Elementele vectorului de obiecte\n";
            for(int i = 0; i <= n; i++){
                cout<<"Elementul "<<i+1<<"\n";
                cin>>v[i];
            }
            cout<<"\n";
            for(int i = 0; i < n; i++){
                cout<<v[i]<<"\n";
            }
        }    
