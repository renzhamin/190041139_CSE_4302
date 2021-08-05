#ifndef CurrentAccount_H
#define CurrentAccount_H
#include "Account.h"

class CurrentAccount : public Account {
	const static int serviceCharge = 100;
	const static int accountPrefix = 100;
	static int nextAccount;
    int nextAccountNo(){
        return ++nextAccount;
    }

public:
	CurrentAccount() {
        setAccountNo(to_string(accountPrefix),to_string(nextAccountNo()));
	}

	~CurrentAccount() {
		nextAccount--;
	}

	void setNextAccount(int val) {
		nextAccount = val;
	}
	int getServiceCharge() const {
		return serviceCharge;
	}
	int getAccountPrefix() const {
		return accountPrefix;
	}
	int getNextAccount() const {
		return nextAccount;
	}

    void show(){
        cout<<"Current Account: "<<"\n";
        Account::show();
        cout<<"Service Charge : "<<serviceCharge<<"\n";
        cout<<"Account Prefix : "<<accountPrefix<<"\n";
    }
};
#endif
