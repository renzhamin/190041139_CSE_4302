#ifndef loanAccount_H
#define loanAccount_H
#include "Account.h"

class LoanAccount : public Account {
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 900;
	static int nextAccount;
	
	int nextAccountNo(){
		return ++nextAccount;
	}

public:

    LoanAccount(float ir=0,float mda=0){
        interestRate = ir;
        monthlyDepositAmount = mda;
        setAccountNo(to_string(accountPrefix),to_string(nextAccountNo()));
    }

    ~LoanAccount(){ nextAccount--; }

    float getInterest(){ return interestRate; }
    float getmonthlyDepositAmount() { return monthlyDepositAmount; }
    int getAccountPrefix(){ return accountPrefix; }

    void setInterestRate(float ir){  interestRate=ir; }
    void setmonthlyDepositAmount(float mda) {  monthlyDepositAmount=mda; }

    void show(){
        cout<<"Loan Account"<<"\n";
        Account::show();
        cout<<"Interest Rate : "<<interestRate<<"\n";
        cout<<"Monthly Deposit amount : "<<monthlyDepositAmount<<"\n";
        cout<<"Account Prefix : "<<accountPrefix<<"\n";
    }
};

#endif
