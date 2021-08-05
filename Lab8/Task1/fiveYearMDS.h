#include "monthlyDepositScheme.h"

class FiveYearMDS:public MonthlyDepositScheme{
    int maximuminterest;
public:
    FiveYearMDS(int mx=0){
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
        cout<<"Five Year Deposit Scheme"<<"\n";
        MonthlyDepositScheme::show();
        cout<<"Maximum Interest : "<<maximuminterest<<"\n";
    }
};
