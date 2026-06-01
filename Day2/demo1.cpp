#include <iostream>
using namespace std;
int value = 100;
class demo{
    public:
    int value;
    void setvalue(int value){
        this->value=value;
    }
    void printall(){
        int value=50;
        cout<<"local value:"<<value<<endl;
        cout<<"member value:"<<this->value<<endl;
        cout<<"global value:"<<::value<<endl;
    }
};
int main(){
    demo d;
    d.setvalue(200);
    d.printall();
    return 0;
}
