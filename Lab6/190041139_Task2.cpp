#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

class Float{
public:
    ld value;
    Float(ld v=0):value(v) {}
    operator int() {
        return int(value);
    }

    friend Float operator + (const Float&,const Float&);
    friend Float operator - (const Float&,const Float&);
    friend Float operator * (const Float&,const Float&);
    friend Float operator / (const Float&,const Float&);
};

Float operator + (const Float &a,const Float &b){
    return Float(a.value+b.value);
}

Float operator - (const Float &a,const Float &b){
    return Float(a.value-b.value);
}

Float operator * (const Float &a,const Float &b){
    return Float(a.value*b.value);
}

Float operator / (const Float &a,const Float &b){
    return Float(a.value/b.value);
}

int main(){
    Float f1(2.5),f2(1.5),f3(3.2);
    cout<<(f1+f2).value<<"\n";
    cout<<(f1-f2).value<<"\n";
    cout<<(f1*f3).value<<"\n";
    cout<<(f3/f1).value<<"\n";
}
