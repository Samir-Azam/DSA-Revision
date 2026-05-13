/*
Leetcode 17:Letter combination of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, string s, vector<string>&ans, string& digits, map<int, string> &mp){

        if (s.size()==digits.size()){
            ans.push_back(s);
            return;
        }
        
        int curr = int(digits[idx]-'0');
        int n = mp[curr].size();
        string alphabet = mp[curr];
        for (int i=0;i<n;i++){
            helper(idx+1, s+alphabet[i], ans, digits, mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int, string>mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string>ans;

        helper(0, "", ans, digits, mp);
        return ans;
    }
};