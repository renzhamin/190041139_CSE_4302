#include <iostream>
using namespace std;

namespace scope1{
    int var = 0;
}

namespace scope2{
    string var = "Hello world";
}

int main(){
    cout<<scope1::var<<"\n";
    cout<<scope2::var<<"\n";
}
