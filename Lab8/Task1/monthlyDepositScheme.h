#ifndef monthlyDepositScheme_H
#define monthlyDepositScheme_H
#include "Account.h"

class MonthlyDepositScheme : public Account {
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 300;
	static int nextAccount;
	
	int nextAccountNo(){
		return ++nextAccount;
	}

public:

    MonthlyDepositScheme(float ir=0,float mda=0){
        interestRate = ir;
        monthlyDepositAmount = mda;
        setAccountNo(to_string(accountPrefix),to_string(nextAccountNo()));
    }
    ~MonthlyDepositScheme(){ nextAccount--; }

    float getInterest(){ return interestRate; }
    float getmonthlyDepositAmount() { return monthlyDepositAmount; }
    int getAccountPrefix(){ return accountPrefix; }

    void setInterestRate(float ir){  interestRate=ir; }
    void setmonthlyDepositAmount(float mda) {  monthlyDepositAmount=mda; }

    void show(){
        cout<<"Monthly Deposit Scheme"<<"\n";
        Account::show();
        cout<<"Interest Rate : "<<interestRate<<"\n";
        cout<<"Monthly Deposit amount : "<<monthlyDepositAmount<<"\n";
        cout<<"Account Prefix : "<<accountPrefix<<"\n";
    }

};

#endif
