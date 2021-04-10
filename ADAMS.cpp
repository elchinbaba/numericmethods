#include<iostream>
using namespace std;

double f(double x, double y) {return x*x+y*y;}
double RK(double x, double y,double h)
{
    double newy,k1,k2,k3,k4;
    k1=f(x,y);
    k2=f(x+h/2,y+h/2*k1);
    k3=f(x+h/2,y+h/2*k2);
    k4=f(x+h,y+h*k3);
    newy=y+h/6*(k1+2*k2+2*k3+k4);
    return newy;
}

double ADAMS(double x, double y, double h)
{
    double x_0=x;
    double y_0=y;
    double x_1=x_0+h;
    double y_1=RK(x_0,y_0,h);
    cout<<"x_1="<<x_1<<" "<<"y_1"<<y_1<<endl;
    double x_2=x_1+h;
    double y_2=RK(x_1,y_1,h);
    cout<<"x_2="<<x_2<<" "<<"y_2"<<y_2<<endl;
    double x_3=x_2+h;
    double y_3=RK(x_2,y_2,h);
    cout<<"x_3="<<x_3<<" "<<"y_3"<<y_3<<endl;
    double y_4=y_3+h/24*(55*f(x_3,y_3)-59*f(x_2,y_2)+37*f(x_1,y_1)-9*f(x_0,y_0));
    return y_4;
}

int main()
{
    double x,y,newx,newy,h=0.1;
    cout<<"x="; cin>>x;
    cout<<"y="; cin>>y;
    newx=x+4*h;
    newy=ADAMS(x,y,h);
    cout<<"newx="<<newx<<" "<<"newy="<<newy<<endl;
    return 0;
}