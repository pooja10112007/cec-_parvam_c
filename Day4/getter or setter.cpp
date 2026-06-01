#include<iostream>
#include<string>
using namespace std;
class student {
    private:
    string name;
    int age;
    double cgpa;
    public:
    string getname() const {return name;}
    int getage() const { return age;}
    double getcgpa() const { return cgpa;}
    void setname(const string& n) {name=n;}
    void setage(int a) {
        if (a>0 && a<150) {
            age=a;
        } else {
            cout<<"Invalid age!"<<endl;
        }
    }
    void setcgpa(double c) {
        if (c>=0.0 && c<=0.0){
            cgpa=c;
        }
        else{
            cout<<"invalid cgpa! must be between 0.0. and 10.0 "<<endl;
        }
        }
        
    };
