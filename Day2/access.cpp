#include<iostream>
using namespace std;
class bankaccount {
    private:
    double balance;
    string accountnumber;
protected :
string accountholdername;
public:
bankaccount(string name,string accno){
    accountholdername = name;
    accountnumber = accno;
    balance = 0.0;
}
void deposit(double amount){
    if (amount>0){
        balance +=amount;
        cout<<"deposited $"<<amount<<endl;
    }
}
void showbalance(){
    cout<<"balance:$"<<balance<<endl;
}
};
class savingsaccount : public bankaccount{
    public:
    savingsaccount(string name,string accno)
    :bankaccount(name,accno){}
    void showholder(){
        cout<<"account holder:"<<accountholdername<<endl;
    }
};
int main(){
    bankaccount acc("arjun","a1001");
    acc.deposit(1000);
    acc.showbalance();
    savingsaccount sav("priya","s2001");
    sav.showholder();
    return 0;
}