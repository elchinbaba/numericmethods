#include<iostream>
using namespace std;

double* qovma(double a[], double b[], double c[], double d[], int n)
{
    double x[n];
    double p[n+1],q[n+1];
    p[0]=0; q[0]=0;
    bool r=true,t=true;
    for(int i=0;i<n;i++)
    {
        if(b[i]!=a[i]*p[i])
        {
            p[i+1]=c[i]/(b[i]-a[i]*p[i]);
            q[i+1]=(a[i]*q[i]-d[i])/(b[i]-a[i]*p[i]);
        }
        else { r=false; cout<<"method is not correct."<<endl; break; }
        if(t && p[i+1]>1) { t=false; cout<<"method is not sustainable."<<endl; }
    }
    double *y;
    y=new double[n+1];
    y[n]=0;
    if(r)
    for(int i=n-1;i>=0;i--)
    {
        y[i]=p[i+1]*y[i+1]+q[i+1];
    }
    return y;
}
double p(double x)
    {return -2/(x*x*(x+1));}

double q(double x)
    {return 0;}

double f(double x)
    {return 0;}
double* finite_dif(double (*F)(double x),double (*P)(double x),double (*Q)(double x),double aa,double bb,double a_0,double a_1,double A,double b_0,double b_1,double B)
{
    double x=aa,h=0.2;
    int n=(bb-aa)/h;
    double a[n+1],b[n+1],c[n+1],d[n+1];
    a[0]=0; b[0]=a_1-h*a_0; c[0]=a_1; d[0]=h*A;
    x+=h;
    for (int i=1; i<n; i++, x+=h)
    {
        a[i]=1/(h*h)-P(x)/(2*h);
        b[i]=2/(h*h)-Q(x);
        c[i]=1/(h*h)+P(x)/(2*h);
        d[i]=F(x);
    }
    a[n]=-b_1; b[n]=-(h*b_0+b_1); c[n]=0; d[n]=h*B;
    double *y=new double[n+2];
    y=qovma(a,b,c,d,n+1);
    return y;
}

int main()
{
    double aa,bb;
    cout<<"a="; cin>>aa;
    cout<<"b="; cin>>bb;
    double x=aa,h=0.2, a_0,a_1,A,b_0,b_1,B;
    int n=(bb-aa)/h;
    cout<<"alfa_0="; cin>>a_0;
    cout<<"alfa_1="; cin>>a_1;
    cout<<"A="; cin>>A;
    cout<<"betta_0="; cin>>b_0;
    cout<<"betta_1="; cin>>b_1;
    cout<<"B="; cin>>B;
    double *y=finite_dif(f,p,q,aa,bb,a_0,a_1,A,b_0,b_1,B);
    for (int i=0;i<=n;i++)
    {
        cout<<"y_"<<i<<"="<<y[i]<<endl;
    }
    return 0;
}
