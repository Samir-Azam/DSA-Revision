/* Basic structure for c++


#include<bits/stdc++.h>
using namespace std;
int main(){
    return 0;
}
*/

/*Input and Output

1.Taking input 
int n;
cin>>n;

2.Taking array input

int arr[n];
for (int i=0;i<n;i++){
cin>>arr[i];
}

3.For vector

vector<int> v(n);
for (int i=0;i<n;i++){
cin>>v[i];
}

4.string s;
cin>>s;

5.To get whole line as input
getline(cin, s);

*/

/* Revision Question:
📌 Problem Statement

You are given an array of integers.

Your task is to compute the XOR of all possible subarrays of the given array.

🧠 What is a subarray?

A subarray is a contiguous part of the array.

For example:

Array: [1, 2, 3]

Subarrays are:

[1]
[2]
[3]
[1,2]
[2,3]
[1,2,3]
*/

// Code 

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (((i+1)*(n-i)&1)) ans ^= arr[i];
    }
    cout << ans << endl;
    return 0;
}




/*
Some important question for revision:

Get familiar with HackerRank UI

Practice most probable NVIDIA patterns
🥇 PHASE 1: MUST DO (Highest Priority)
⚡ Bit Manipulation (START HERE)
1. Lonely Integer (VERY IMPORTANT)

👉 https://www.hackerrank.com/challenges/lonely-integer/problem

Pure XOR concept
Must solve 💯
2. Maximizing XOR

👉 https://www.hackerrank.com/challenges/maximizing-xor/problem

Bit logic thinking
3. Sum vs XOR

👉 https://www.hackerrank.com/challenges/sum-vs-xor/problem

Pattern-based XOR
📊 Arrays + Hashing
4. Ice Cream Parlor (VERY IMPORTANT)

👉 https://www.hackerrank.com/challenges/icecream-parlor/problem

Two Sum pattern
High probability ⚡
5. Missing Numbers

👉 https://www.hackerrank.com/challenges/missing-numbers/problem

Frequency map
6. Sales by Match

👉 https://www.hackerrank.com/challenges/sock-merchant/problem

Hashing basics
🔥 Kadane’s Algorithm
7. Maximum Subarray

👉 https://www.hackerrank.com/challenges/maxsubarray/problem

Direct Kadane
VERY IMPORTANT
🥈 PHASE 2: HIGH PROBABILITY
🔍 Binary Search
8. Binary Search (Intro)

👉 https://www.hackerrank.com/challenges/binary-search/problem

9. Minimum Time Required

👉 https://www.hackerrank.com/challenges/minimum-time-required/problem

Answer-based binary search
🔄 Sliding Window
10. Subarray Division

👉 https://www.hackerrank.com/challenges/the-birthday-bar/problem

Window technique
11. Max Subarray Sum (mod)

👉 https://www.hackerrank.com/challenges/maximum-subarray-sum/problem

Slightly advanced
📈 Prefix Sum
12. Subarray Sum Equals K (similar concept)

👉 https://www.hackerrank.com/challenges/array-manipulation/problem

🥉 PHASE 3: BONUS (If time remains)
🔤 Strings
13. Pangrams

👉 https://www.hackerrank.com/challenges/pangrams/problem

14. Caesar Cipher

👉 https://www.hackerrank.com/challenges/caesar-cipher-1/problem

🌳 Basic Graph (optional)
15. BFS Short Reach

👉 https://www.hackerrank.com/challenges/bfsshortreach/problem

*/