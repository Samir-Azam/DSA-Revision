// fibonacci series - the brute force way is to use recursion becuase if we use recursion the time complexity will be exponential it will be approximately equals to O(2^n) and there will be O(n) space complexity also the optimal solution will be using loops it will solve the the problem in O(n) time complexity and O(1) space complexity.

#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if (n<=1) return n;

    int last = fibo(n-1);
    int secLast = fibo(n-2);

    return last + secLast;
}

int main(){

    cout<<fibo(1);
    return 0;
}