/*
Reverse a Stack:

The approach will be very simple we will use recursion to empty the stack first while storing the top elements and once the stack is empty we will backtrack and store the top element at the bottom of the stack.It includes two recursive function one for to empty the stack and other to insert at the bottom.
*/


#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&s,int x){
        if (s.empty()){
            s.push(x);
        }
        int top = s.top();
        s.pop();
        insertAtBottom(s,x);
        s.push(top);
}
void reverse(stack<int>&s){
    if (s.empty()) return;

    int top = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,top);
}


// TC: O(N^2) SC: O(N)

