#include<iostream>
using namespace std;

double f(double x, double y, double z) {return z;}
double g(double x, double y, double z) {return x*z/(2*x+1);}

int main()
{
    double x,y,z,newx,newy,newz,h=0.1,k1,k2,k3,k4,q1,q2,q3,q4;
    cout<<"x="; cin>>x;
    cout<<"y="; cin>>y;
    cout<<"z="; cin>>z;
    k1=f(x,y,z); q1=g(x,y,z);
    k2=f(x+h/2,y+h/2*k1,z+h/2*q1); q2=g(x+h/2,y+h/2*k1,z+h/2*q1);
    k3=f(x+h/2,y+h/2*k2,z+h/2*q2); q3=g(x+h/2,y+h/2*k2,z+h/2*q2);
    k4=f(x+h,y+h*k3,z+h*q3); q4=g(x+h,y+h*k3,z+h*q3);
    /*cout<<"k1="<<k1<<"\t"<<"q1="<<q1<<endl;
    cout<<"k2="<<k2<<"\t"<<"q2="<<q2<<endl;
    cout<<"k3="<<k3<<"\t"<<"q3="<<q3<<endl;
    cout<<"k4="<<k4<<"\t"<<"q4="<<q4<<endl;*/
    newx=x+h;
    newy=y+h/6*(k1+2*k2+2*k3+k4);
    newz=z+h/6*(q1+2*q2+2*q3+q4);
    cout<<"newx="<<newx<<endl<<"newy="<<newy<<endl<<"newz="<<newz<<endl;
    return 0;
}