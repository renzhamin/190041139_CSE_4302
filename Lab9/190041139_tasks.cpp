#include <iostream>
#include "furnitures.h"
#define ll long long 
using namespace std;

enum class BedSize {Single,SemiDouble,Double};
enum class SofaSize {One,Two,Three,Four,Five};
enum class AlmirahSize {Two,Three,Four};

class Bed:public Furniture
{
    BedSize bedsize;
    public:
    Bed(double p=0,double d=0,Material m=Material::Wood,BedSize b=BedSize::Single){
        setBasicDetails(p,d,m);
        bedsize = b;
    }

    string getBedSize();

    void productDetails()
    {
        cout<<string(20,'-')<<'\n';
        showBasicDetails();
        cout<<"Bed Size : "<<getBedSize()<<"\n";
        cout<<string(20,'#')<<'\n';
    }
};

class Sofa:public Furniture
{
    SofaSize sofasize;
    public:
    Sofa(double p=0,double d=0,Material m=Material::Wood,SofaSize s=SofaSize::Three){
        setBasicDetails(p,d,m);
        sofasize = s;
    }

    string getSofaSize();

    void productDetails(){
        cout<<string(20,'-')<<'\n';
        showBasicDetails();
        cout<<"Number of seats : "<<getSofaSize()<<"\n";
        cout<<string(20,'#')<<'\n';

    }

};

class Almirah:public Furniture
{
    AlmirahSize almirahsize;
    public:
    Almirah(double p=0,double d=0,Material m=Material::Wood,AlmirahSize a=AlmirahSize::Two){
        setBasicDetails(p,d,m);
        almirahsize = a;
    }

    string getAlmirahSize();

    void productDetails(){
        cout<<string(20,'-')<<'\n';
        showBasicDetails();
        cout<<"Number of doors : "<<getAlmirahSize()<<"\n";
        cout<<string(20,'#')<<'\n';

    }
};

void sort_furniture_discount(Furniture** b, int n) {
    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n; j++) {

            if(b[i]->getDiscount() < b[j]->getDiscount()){
                Furniture *tmp=b[i];
                b[i] = b[j];
                b[j] = tmp;
            }

        }
    }
}



int main()
{
    Furniture* f_list[100];
    int n=0;
    f_list[n++] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[n++] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[n++] = new Almirah(13000,345,Material::Wood,AlmirahSize::Two);
    f_list[n++] = new Bed(10090,123,Material::Wood,BedSize::Single);


    f_list[2]->setDiscountPercentage(30);
    f_list[0]->setProductName("Bahari Bed");
    
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    sort_furniture_discount(f_list,n);
    for(int i=0; i<n; i++)
    {
//         f_list[i]->productDetails();
        cout<<f_list[i]->getDiscount()<<"\n";
    }

    for(int i=0;i<n;i++){
        delete f_list[i];
    } 
}


string Bed::getBedSize(){
    if(bedsize == BedSize::Single){
        return string("Single");
    } 
    else if(bedsize == BedSize::Double){
        return string("Double");
    } 

    else if(bedsize == BedSize::SemiDouble){
        return string("SemiDouble");
    } 

    else {
        return string("");
    }
}

string Sofa::getSofaSize(){
    if(sofasize==SofaSize::One)
        return string("One");
    else if(sofasize==SofaSize::Two)
        return string("Two");
    else if(sofasize==SofaSize::Three)
        return string("Three");
    else if(sofasize==SofaSize::Four)
        return string("Four");
    else if(sofasize==SofaSize::Five)
        return string("Five");
    else 
        return string("");
}


string Almirah::getAlmirahSize(){
    if(almirahsize==AlmirahSize::Two)
        return string("Two");
    else if(almirahsize==AlmirahSize::Three)
        return string("Three");
    else if(almirahsize==AlmirahSize::Four)
        return string("Four");
    else
        return string("");
}

