#include <bits/stdc++.h>
#define ll long long 
using namespace std;

template<class T>
class Stack {
    public:
        class Empty{};
        class Full{};

        int cur,n;
        T *arr;
        Stack (int _n){
            cur=0;
            arr = new T[_n];
            n = _n;
        }
        bool empty(){
            return !cur;
        }
        int size(){
            return cur;
        }
        void pop(){
            if(cur==0){
                throw Empty();
            }
            cur--;
        }
        void push(int x){
            if(cur>=n) throw Full();
            arr[cur++] = x; 
        }
        T peek(){
            if(cur==0) throw Empty();
            return arr[cur-1];
        }
        int& operator[](int index){
            return arr[index];
        }
};


int main(){
    Stack<ll>st(3);
    try{
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
    } catch (Stack<ll>::Full){
        cout<<"Stack is Full"<<"\n";
    }

    cout<<st.peek()<<"\n";

    Stack<char>st2(3);
    st2.push('a');
    cout<<st2.peek()<<"\n";

    try{
        st2.pop();
        st2.pop();
    } catch(Stack<char>::Empty){
        cout<<"Stack Empty"<<"\n";
    }

}
