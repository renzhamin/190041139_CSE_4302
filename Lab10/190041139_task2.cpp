#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class foo{
public:
    foo(const foo& b){ 
        allocName(strlen(b.name));
        strcpy(name,b.name); 
    }
    foo& operator = (foo &b){
        allocName(strlen(b.name));
        strcpy(name,b.name);
        return *this;
    }

    char *name = NULL;

    foo(int n=10){ name = new char[n]; }
    
    void allocName(int n){
        name = new char[n];
    }
    
    void setName(char *n){
        if(sizeof(name) >= sizeof(n))
            strcpy(name,n);
    }
};

int main(){
    char n[] = "Hello";
    char n2[] = "World";

    foo a,b;
    a.setName(n2); // World

    b = a; // b - World
    
    foo c(a); // C - World

    a.setName(n); // a - Hello

    cout<<a.name<<"\n";
    cout<<b.name<<"\n";
    cout<<c.name<<"\n";
}
