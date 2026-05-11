/*
Sort a stack using recursion:

*/


#include<bits/stdc++.h>
using namespace std;

void insertAtCorrectPlace(int x, stack<int>&s){
    if (s.empty()){
        s.push(x);
        return;
    }
    if (s.top()<=x){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insertAtCorrectPlace(x,s);
    s.push(temp);
}


void sort(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    sort(s);
    insertAtCorrectPlace(temp, s);
}


int main(){
    stack<int>st;
    st.push(1);
    st.push(3);
    st.push(2);
    st.push(4);
    sort(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}