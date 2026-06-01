#include<iostream>
using namespace std;
int main(){
    int x= 42;
    int*ptr;
    ptr=&x;
    cout<<"value of x:"<<x<<endl;
    cout<<"address of x:"<<&x<<endl;
    cout<<"value of ptr(address it holds):"<<ptr<<endl;
    cout<<"value at address ptr:"<<ptr<<endl;
    *ptr = 100;
    cout<<"x after *ptr = 100:"<<x<<endl;
    int* ptr2 = nullptr;
    return 0;
}
