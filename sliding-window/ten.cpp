/*
Leetcode 76: Minimum window substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

*/

// Optimal Code - 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int arr[256] = {0};
        for (int i=0;i<t.size();i++){
            arr[t[i]]++;
        }
        int l=0, r=0, sIndex=-1, count=0, minLength=INT32_MAX;
        while(r<s.size()){
            if (arr[s[r]]>0) count++;
            arr[s[r]]--;
    
            while(count==t.size()){
                if (r-l+1<minLength){
                    minLength = min(minLength, r-l+1);
                    sIndex = l;
                }
                if (arr[s[l]]==0) count--;
                arr[s[l]]++;
                l++;
            }
            r++;
        }
        
        return sIndex==-1?"":s.substr(sIndex, minLength);
    }
};
