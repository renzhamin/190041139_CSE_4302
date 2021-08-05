#include "monthlyDepositScheme.h"

class InitialDepositMDS:public MonthlyDepositScheme{
    int maximuminterest;
    int initialDepositAmont;
public:
    InitialDepositMDS(int mxi=0,int init=0){
        MonthlyDepositScheme();
        maximuminterest = mxi;
        initialDepositAmont = init;
    }
    int getMaximumInterest(){
        return maximuminterest;
    }

    int getInitialDepositAmont(){
        return initialDepositAmont;
    }

    void setInitialDepositAmont(int init) {
        initialDepositAmont = init;
    }

    void setMaximumInterest(int mx){
        maximuminterest = mx;
    }

    void show(){
        cout<<"Initial Deposit Scheme"<<"\n";
        MonthlyDepositScheme::show();
        cout<<"Initial Deposit Amount : "<<initialDepositAmont<<"\n";
        cout<<"Maximum Interest : "<<maximuminterest<<"\n";
    }

};
