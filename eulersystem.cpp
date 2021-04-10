#include<iostream>
using namespace std;

double f(double x, double y, double z) {return z;}
double g(double x, double y, double z) {return 2*x/(3*x*x-1)*z;}

int main()
{
    double x,y,z,newx,newy,newz,h=0.1;
    cout<<"x="; cin>>x;
    cout<<"y="; cin>>y;
    cout<<"z="; cin>>z;
    newx=x+h;
    newy=y+h*f(x,y,z);
    newz=z+h*g(x,y,z);
    cout<<"newy="<<newy<<endl<<"newz="<<newz<<endl;
    return 0;
}