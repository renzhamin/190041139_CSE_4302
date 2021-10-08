#include <bits/stdc++.h>
#define ll long long

using namespace std;

template <class T>
T amax (T* arr, int sz,int n) {
    sort(arr,arr+sz,greater<T>());
    return arr[n-1];
}

int main() {
    int arr[] = {9, 8, 6, 1, 5, 4};
    int sz = sizeof(arr)/sizeof(arr[0]);
    cout<<amax(arr,sz,2)<<"\n";

    ll arr1[] = {5, 11, 3, 10, 6, 4};
    sz = sizeof(arr1)/sizeof(arr1[0]);
    cout<<amax(arr1,sz,3)<<"\n";
}
