#include"rectangle.h"
#include<iostream>
using namespace std;
rectangle::rectangle(){
    length=0;
    width=0;
}
rectangle::rectangle(double l,double w){
length=l;
width=w;
}
void rectangle::setdimensions(double l,double w){
    length=l;
    width=w;
}
double rectangle::area(){
    return length*width;
}
double rectangle::perimeter(){
    return 2*(length+width);
}
void rectangle::display(){
    cout<<"rectangle:"<<length<<"x"<<width<<endl;
    cout<<"area:"<<area()<<",perimeter:"<<perimeter()<<endl;
}
