#include<iostream>
using namespace std;
class bankaccount{
    private:
    double balance;
    string accountnumber;
    public:
    bankaccount(string accno,double bal)
    :accountnumber(accno),balance(bal){}
    friend void displayaccountinfo(const bankaccount& acc);
    friend class auditor;
};
void displayaccountinfo(const bankaccount& acc){
    cout<<"account:"<<acc.accountnumber<<endl;
    cout<<"balance:$"<<acc.balance<<endl;
}
class auditor{
    public: 
    void audit(const bankaccount& acc){
        cout<<"audit repport"<<endl;
        cout<<"account:"<<acc.accountnumber<<endl;
        cout<<"verified balance:$"<<acc.balance<<endl;
    }
};
int main(){
    bankaccount acc("acc-1001",50000);
    displayaccountinfo(acc);
    cout<<endl;
    auditor auditor;
    auditor.audit(acc);
    return 0;
}

