/*
Leetcode - 1358 Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
*/

/*
Approach -
1. Brute Force - Generating all the substrings and check if all the characters ('a','b','c') are present or not if they are present add size-index to the count at the end return the count.

2. Better Solution : Use sliding window and two pointer keep a hashArray and check for valid window in the string by expanding at r once the condition becomes true add (size-r) to count and shrink the window to find more valid answers.

3. Optimal solution : maintain minimum valid window that contains all the characters and if you get one then all the characters present before the valid window can get added one by one to generate more valid substrings so add (current_index +1 to the count code is written below) 

*/

// Better code 
#include<unordered_map>

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,count=0;
        unordered_map<char, int> mp;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp.size()==3){
                count +=(s.size()-r);
                mp[s[l]]--;
                if (mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return count;
    }
};




// Optimal code 
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int hashArray[] = {-1, -1, -1};

        int count = 0;
        for (int i=0;i<s.size();i++){
            hashArray[s[i]-'a'] = i;
            if (hashArray[0]!=-1 && hashArray[1]!=-1 && hashArray[2]!=-1){
                int min = *min_element(hashArray, hashArray+3);
                count += (1+min);
            }
        }
        return count;
    }
};