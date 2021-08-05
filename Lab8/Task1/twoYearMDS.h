#ifndef twoYearMDS_H
#define twoYearMDS_H
#include "monthlyDepositScheme.h"

class TwoYearMDS:public MonthlyDepositScheme{
    int maximuminterest;
public:
    TwoYearMDS(int mx=0){
        MonthlyDepositScheme();
        maximuminterest = mx;
    }
    int getMaximumInterest(){
        return maximuminterest;
    }

    void setMaximumInterest(int mx){
        maximuminterest = mx;
    }

    void show(){
        cout<<"Two Year Deposit Scheme"<<"\n";
        MonthlyDepositScheme::show();
        cout<<"Maximum Interest : "<<maximuminterest<<"\n";
    }

};
#endif
