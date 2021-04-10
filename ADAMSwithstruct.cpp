#include<iostream>
using namespace std;

struct coor
{
    double x,y;
};

double f(coor obj)
{
    double a=obj.x, b=obj.y; 
    return a*a+b*b;
}
double f(double x, double y)
    {return x*x+y*y;}

coor RK(coor obj,double h)
{
    double a=obj.x,b=obj.y,newx,newy,k1,k2,k3,k4;
    coor newobj;
    k1=f(a,b);
    k2=f(a+h/2,b+h/2*k1);
    k3=f(a+h/2,b+h/2*k2);
    k4=f(a+h,b+h*k3);
    newx=a+h;
    newy=b+h/6*(k1+2*k2+2*k3+k4);
    newobj.x=newx;
    newobj.y=newy;
    return newobj;
}

coor ADAMS(coor obj, double h)
{
    coor obj_0=obj;
    coor obj_1=RK(obj_0,h);
    cout<<"x_1="<<obj_1.x<<" "<<"y_1="<<obj_1.y<<endl;
    coor obj_2=RK(obj_1,h);
    cout<<"x_2="<<obj_2.x<<" "<<"y_2="<<obj_2.y<<endl;
    coor obj_3=RK(obj_2,h);
    cout<<"x_3="<<obj_3.x<<" "<<"y_3="<<obj_3.y<<endl;
    coor obj_4;
    obj_4.x=obj_3.x+h;
    obj_4.y=obj_3.y+h/24*(55*f(obj_3)-59*f(obj_2)+37*f(obj_1)-9*f(obj_0));
    return obj_4;
}

int main()
{
    double a,b,newx,newy,h=0.1;
    cout<<"x="; cin>>a;
    cout<<"y="; cin>>b;
    coor obj,newobj;
    obj.x=a;
    obj.y=b;
    newobj=ADAMS(obj,h);
    cout<<"newx="<<newobj.x<<" "<<"newy="<<newobj.y<<endl;
    return 0;
}