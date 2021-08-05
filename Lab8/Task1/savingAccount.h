#ifndef savingAccount_H
#define savingAccount_H
#include "Account.h"

class SavingsAccount : public Account {
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 200;
	static int nextAccount;
	
	int nextAccountNo(){
		return ++nextAccount;
	}

public:

    SavingsAccount(float ir=0,float mda=0){
        interestRate = ir;
        monthlyDepositAmount = mda;
        setAccountNo(to_string(accountPrefix),to_string(nextAccountNo()));
    }

    ~SavingsAccount(){ nextAccount--; }

    float getInterest(){ return interestRate; }
    float getmonthlyDepositAmount() { return monthlyDepositAmount; }
    int getAccountPrefix(){ return accountPrefix; }

    void setInterestRate(float ir){  interestRate=ir; }
    void setmonthlyDepositAmount(float mda) {  monthlyDepositAmount=mda; }

    void show(){
        cout<<"Savings Account"<<"\n";
        Account::show();
        cout<<"Interest Rate : "<<interestRate<<"\n";
        cout<<"Monthly Deposit amount : "<<monthlyDepositAmount<<"\n";
        cout<<"Account Prefix : "<<accountPrefix<<"\n";
    }
};

#endif
