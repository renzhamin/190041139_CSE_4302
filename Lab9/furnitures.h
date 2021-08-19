#include <iostream>
#include <string>
using namespace std;

enum  Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    string productName;
    Material madeof;
public:

    Furniture(double p=0,double d=0,Material m=Material::Wood,string name="")
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setProductName(name);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setDiscountPercentage(double val){
        if(val>0)
            discount = val/100 * price;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void setProductName(string name)
    {
        productName = name;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }

    void setBasicDetails(double p,double d,Material m){
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }

    void showBasicDetails(){
        if(productName!="")
            cout<<"Product Name : "<<productName<<"\n";
        cout<<"Regular Price : "<<price<<"\n";
        cout<<"Discounted Price : "<<price-discount<<"\n";
        cout<<"Material : "<<getMadeof()<<"\n";
    }

    double getDiscount(){
        return discount;
    }

    virtual void productDetails() = 0;

};
