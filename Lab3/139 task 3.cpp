#include <iostream>
#include <cstring>
using namespace std;

class Product{
private:
    char name[100];
    double discountPercent,unitPrice;

public:
    Product():discountPercent(0.5),unitPrice(10) {}

    void assignName(const char *Name){
        strcpy(name,Name);
    }

    void setPrice(double price){
        if(price<0){
            cout<<"Price cant be negative"<<"\n";
            return;
        }
        unitPrice = price;
    }

    void setDiscPercent(double percent){
        if(percent<0 || percent>10){
            cout<<"invalid discount"<<"\n";
            return;
        }
        discountPercent = percent;
    }

    double getSellingPrice(int nos){
        return (unitPrice*(1-discountPercent/100))*nos;
    }

    void display(){
        cout<<name<<" has a unit price of BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%.\n";
    }

};

int main(){
    Product x;
    x.assignName("Cocola noodle");
    x.setPrice(100);
    x.setDiscPercent(9.5);
    x.display();
    cout<<x.getSellingPrice(1)<<"\n";
}
