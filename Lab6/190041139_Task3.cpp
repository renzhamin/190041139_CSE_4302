#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class ZooAnimal{
    string nameOfAnimal;
    int birthYear,cageNo,height;
    double weight;
public:
    ZooAnimal(string name="Monkey",int by=2021,int cn=1,double w=10,int h=20){
        nameOfAnimal = name;
        birthYear = by;
        cn = cageNo;
        weight = w;
        height = h;
    }
    void set_birthYear(int b=2021){
        if(b>2021){
            cout<<"birthYear cant be more than 2021"<<"\n";
            return;
        }
        birthYear = b;
    }
    void set_cageNo(int b){birthYear = b;}
    void set_height(int h){height = h;}
    void set_weight(double w){weight = w;}
    
    int get_birthYear(){return birthYear;}
    int get_cageNo() { return cageNo; }
    int get_height() { return height; }
    double get_weight() { return weight; }
    int getAge(){ return 2021-birthYear; }
    
    void getInformation(){
        cout<<"Name of Animal : "<<nameOfAnimal<<"\n";
        cout<<"Year of birth : "<<birthYear<<"\n";
        cout<<"Cage No : "<<cageNo<<"\n";
        cout<<"Weight : "<<weight<<"\n";
        cout<<"Height : "<<height<<"\n";
    }
    // --- Lab 6 ---- \\

    int operator == (int w){
        return (weight==w);
    }

    void operator -- (int dec){
        weight--;
    }

    void operator -=(int dec){
        weight-=dec;
    }

};

int main(){
    ZooAnimal x;
    x--;
    x-=4;
//     x.getInformation();
    if(x==5){
        cout<<"weight is 5"<<"\n";
    }
}
