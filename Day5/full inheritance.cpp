#include<iostream>
#include<string>
using namespace std;
class person{
    protected:
    string name;
    int age;
    public:
    person(string n, int a):name(n),age(a){}
    void display(){
        cout<<"name:"<<name<<",age:"<<age;
    }
};
class student:public person{//student inherits from person.
    protected:
    int rollno;
    public:
    student(string n,int a,int r):person(n,a),rollno(r){}
    void display(){
        person::display();
        cout<<",roll no:"<<rollno<<endl;
    }
};
class graduatestudent:public student{//graduatestudent inherits from student, which inherits from person.
    private:
    string thesistopic;
    public:
    graduatestudent(string n, int a, int r, string t)
    :student(n,a,r),thesistopic(t){}
    void display(){
        student::display();
            cout<<"thisis:"<<thesistopic<<endl;
        }
    };
    class teacher:public person{//Both student and teacher inherit from person.
        private:
        double salary;
        public:
        teacher(string n, int a, double s):person(n,a),salary(s){}
        void display(){
            person::display();
            cout<<".salary:$"<<salary<<endl;
        }
    };
    class teachingassistant:public student,public teacher{//teachingassistant inherits from both student and teacher.
        public:
        teachingassistant(string n, int a, int r, double s)
        :student(n,a,r),teacher(n,a,s){}
        void display(){
            cout<<"teaching assistant:"<<student::name<<endl;
            cout<<"age:"<<student::age<<",roll:"<<student::rollno<<endl;
        }
    };
    int main(){
        cout<<"==single inheritance==="<<endl;
        student s1("arjun",20,101);
        s1.display();
        cout<<"\n===multilevel inheritance==="<<endl;
        graduatestudent gs("priya",24,201,"machine learning");
        gs.display();
        cout<<"\n=== hierarchial inheritance==="<<endl;
        teacher t1("dr.sharma",45,80000);
        t1.display();
        return 0;
    };


