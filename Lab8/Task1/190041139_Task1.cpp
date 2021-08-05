#include "Account.h"
#include "currentAccount.h"
#include "savingAccount.h"
#include "monthlyDepositScheme.h"
#include "loanAccount.h"
#include "twoYearMDS.h"
#include "fiveYearMDS.h"
#include "initialDepositMDS.h"

int CurrentAccount::nextAccount=0;
int SavingsAccount::nextAccount=0;
int MonthlyDepositScheme::nextAccount=0;
int LoanAccount::nextAccount=0;



int main(){
    CurrentAccount c;
    SavingsAccount s;
    LoanAccount l;
    TwoYearMDS t;
    FiveYearMDS f;
    InitialDepositMDS i;

    c.show();
    cout<<"-------------------------------------"<<"\n";
    
    s.show();
    cout<<"-------------------------------------"<<"\n";
    
    t.show();
    cout<<"-------------------------------------"<<"\n";

    f.show();
    cout<<"-------------------------------------"<<"\n";

}
