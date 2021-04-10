#include<iostream>
using namespace std;

double p(double x)
    {return -2/(x*x*(x+1));}

double q(double x)
    {return 0;}

double f(double x)
    {return 0;}

int main()
{
    double aa,bb;
    cout<<"a="; cin>>aa;
    cout<<"b="; cin>>bb;
    double x=aa,h=0.2, a_0,a_1,A,b_0,b_1,B;
    int n=(bb-aa)/h;
    double a[n],b[n],c[n],d[n];
    cout<<"alfa_0="; cin>>a_0;
    cout<<"alfa_1="; cin>>a_1;
    cout<<"A="; cin>>A;
    cout<<"betta_0="; cin>>b_0;
    cout<<"betta_1="; cin>>b_1;
    cout<<"B="; cin>>B;
    double chi_1,mu_1,chi_2,mu_2, xi[n],eta[n];
    chi_1=a_1/(a_1-h*a_0); mu_1=h*A/(h*a_0-a_1);
    xi[0]=chi_1; eta[0]=mu_1;
    a[0]=0; c[n]=0; x+=h;
    bool r=true,t=true;
    for(int i=0;i<n;i++,x+=h)
    {
        //if(i!=0)
        a[i]=1/(h*h)-p(x)/(2*h);
        b[i]=2/(h*h)-q(x);
        //if(i!=n)
        c[i]=1/(h*h)+p(x)/(2*h);
        d[i]=f(x);
    }
    for(int i=0;i<n-1;i++)
    {
        if(b[i]!=a[i]*xi[i])
        {
            xi[i+1]=c[i]/(b[i]-a[i]*xi[i]);
            eta[i+1]=(a[i]*eta[i]-d[i])/(b[i]-a[i]*xi[i]);
        }
        else { r=false; cout<<"usul korrekt deyil."<<endl; break; }
        if(t && xi[i+1]>1) { t=false; cout<<"usul dayaniqli deyil."<<endl; }
    }
    double y[n+1];
    chi_2=b_1/(b_1+h*b_0); mu_2=h*B/(h*b_0+b_1);
    y[n]=(mu_2+chi_2*eta[n-1])/(1-chi_2*xi[n-1]);
    cout<<"y_"<<n<<"="<<y[n]<<endl;
    if(r)
    for(int i=n-1;i>=0;i--)
    {
        y[i]=xi[i]*y[i+1]+eta[i];
        cout<<"y_"<<i<<"="<<y[i]<<endl;
    }
    return 0;
}