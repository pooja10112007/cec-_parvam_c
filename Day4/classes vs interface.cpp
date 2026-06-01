#include<iostream>
#include<string>
using namespace std;
class shape{
    protected:
    string color;
    public:
    shape(string c):color(c){}
    virtual double area() const=0;
    virtual void draw() const=0;
    string getcolor()const {return color;}
    virtual~shape(){}
};
class circle:public shape{
    private:
    double radius;
    public:
    circle(string c, double r):shape(c),radius(r){}
    double area() const override{
        return 3.14159*radius*radius;
    }
    void draw() const override{
        cout<<"drawing a"<<color<<"circle(area:"<<area()<<")"<<endl;
    }
};
class rectangle:public shape{
    private:
    double length;
    double width;
    public:
    rectangle(string c, double l,double w):shape(c),length(l),width(w){}
    double area() const override{
        return length*width;
    }
    void draw() const override{
        cout<<"drawing a"<<color<<"rectangle(area:"<<area()<<")"<<endl;
    }
};
int main(){
    shape*shapes[2];
    shapes[0]=new circle("red",5.0);
    shapes[1]=new rectangle("blue",4.0,6.0);
    for(int i=0; i<2;i++){
        shapes[i]->draw();
        for(int i=0;i<2;i++){
            delete shapes[i];
        }
        return 0;
    } 
}
