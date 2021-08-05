#ifndef Account_H
#define Account_H
#include <iostream>
using namespace std;

class Account {
	string accountNo;
	string accountName;
	float balance=0;

public:
	Account(string str = "") : accountName(str){}

	void setAccountName(string str) {
		accountName = str;
	}

	void setAccountNo(string prefix, string str) {
		accountNo = prefix + str;
	}

	void setBalance(float balance) {
		balance = balance;
	}
	
	string getAccountNmae() {
		return accountName;
	}

	string getAccountNo() {
		return accountNo;
	}
	float getBalance() {
		return balance;
	}

    void show(){
        cout<<"Account No : "<<accountNo<<"\n";
        cout<<"Account Name : "<<accountName<<"\n";
        cout<<"Balance : "<<balance<<"\n";
    }
};
#endif
