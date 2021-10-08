#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[20];
    set <int> s;
    int j=0;
    for(int i=1;i<=20;i++){
        if(i&1)
            s.insert(i);
        else{
            arr[j++]=i;
        }
    }

    vector <int> v(20);
    merge(arr, arr+10, s.begin(), s.end(), v.begin());
    
    for(auto i:v){
        cout<<i<<" ";
    }

}
