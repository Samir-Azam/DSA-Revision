/*
Given a string s, find the length of the longest substring without duplicate characters.
 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

/* To solve this question you can use multiple approaches 
1. Brute force -  we can generate all the subarrays and check for duplicates and we will update the maximum length 
2. Better using hashing of characters (character concept)
*/

// 2. Better Solution Code 

// #include<iostream>
// #include<vector>
// #include<string>
// #include<unordered_map>
// using namespace std;

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<int, int>mp;
//         int l=0,r=0,maxLen=0;
//         while(r<s.size()){
//             mp[s[r]]++;
//             while(mp[s[r]]>1){
//                 mp[s[l]]--;
//                 l++;
//             }
//             maxLen = max(maxLen, r-l+1);
//             r++;
//         }
//         return maxLen;
//     }
// };


// int main(){
//     string s = "cadbzabcd";
//     Solution obj;
//     cout<<obj.lengthOfLongestSubstring(s);
//     return 0;
// }


// Optimal Solution - Instead of storing the frequency you can store the index so that you can directly jump to the next index avoiding unique characters 

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int l=0, r=0, maxlen = 0;
        while (r<s.size()){
            if (mp.find(s[r])!=mp.end() && l<=mp[s[r]]){
                l = mp[s[r]]+1;
            }
            mp[s[r]] = r;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};


int main(){
    string s = "cadbzabcd";
    Solution obj;
    cout<<obj.lengthOfLongestSubstring(s);
    return 0;
}