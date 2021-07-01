#include <bits/stdc++.h>
#define ll long long 
using namespace std;

enum Types{
    Current,Savings
};

class BankAccount{
    int account_no;
    double cur_balance,min_balance;
    string holder_name;
    Types account_type;
public:
    BankAccount(string n,int no,double bal,double min_bal,Types t){
        holder_name = n;
        account_no = no;
        cur_balance = bal;
        min_balance = min_bal;
        account_type = t;
    }
    BankAccount(){min_balance = 0; cur_balance=0;}
    ~BankAccount(){
        cout<<"Account of "<<holder_name<<"with account no "<<account_no\
            <<"is destroyed with a balance BDT "<<cur_balance<<"\n";
    }

    void set_account_no(int no){account_no=no;}
    void set_holder_name(string n){holder_name=n;}
    void set_account_type(Types t){ account_type=t; }
    void set_cur_balance(double b){ update_balance(b); }
    void set_min_balance(double m){ min_balance=m; }

    bool update_balance(double change){
        if(cur_balance+change<min_balance){
            cout<<"Minimum Balance requirement not satisfied\nMinimum Balance is"<<min_balance<<"\n";
            return 0;
        }
        cur_balance += change;
        return 1;
    }

    void showBalance(){ cout<<"Balance : "<<cur_balance<<"\n"; }
    void deposit(double amount){
        update_balance(amount);
    }
    void withdraw(double amount){
        update_balance(-amount);
    }
    void giveInterest(double interest=2.5){
        update_balance(cur_balance*(interest/100)*0.9);
    }
};

int main(){
    BankAccount x;
    x.set_cur_balance(100);
    x.set_account_type(Types::Savings);
    x.giveInterest();
    x.deposit(.75);
    x.withdraw(3);
    x.showBalance();
}
