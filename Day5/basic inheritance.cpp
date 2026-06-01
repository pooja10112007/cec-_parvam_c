#include<iostream>
#include<string>
using namespace std;
class animal{
    protected:
    string name;
    int age;
    public:
    animal(string n,int a) : name(n),age(a){}
    void eat(){
        cout<<name<<"is eating."<<endl;
    }
    void sleep(){
        cout<<name<<"is sleeping."<<endl;
    }
};
class dog:public animal{
    private:
    string breed;
    public:
    dog(string n,int a,string b) : animal(n,a),breed(b){}
    void bark(){
        cout<<name<<"(the"<< breed<<") is barking!"<<endl;
    }
    void display(){
        cout<<"dog:"<<name<<",age:"<<age<<",breed:"<<breed<<endl;
    }
};
int main(){
    dog mydog("buddy",3,"golden retriever");
    mydog.eat();
    mydog.sleep();
    mydog.bark();
    mydog.display();
    return 0;
}
