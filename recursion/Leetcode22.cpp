/*
Leetcode 22: Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

*/


// This is very simple we just have to think about recursion from choices + decision tree

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void generate(int open, int closed, int n, string s, vector<string>&ans){
        if (open<0 || closed<0) return;

        if (open==0 && closed==0){
            ans.push_back(s);
            return;
        }

        // select open
        generate(open-1, closed, n, s+'(', ans);

        if (closed>open) generate(open, closed-1, n, s+')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(n, n, n, "", ans);
        return ans;
    }
};