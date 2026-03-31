/*
Leetcode - 424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

/*
Approach - 1
1. Brute force - generate all the subarrays and check maxlen till flips(length-maxfrequency) is lesser then or equal to k in this way you can get the length of longest substring with same repeating character

2. Better using hashing of sliding window - We have to use hashArray to store frequecy and we have to check and expand until the condition is true 
i.e (length-maxfrequency) is lesser then or equal to k and if it is greater then we have to shrink the window using left pointer and update the maxFrequency and flip.
*/

// Better Code 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int l=0, r=0, maxlen=0, maxfreq=0;
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq, hash[s[r]-'A']);
            int flips = (r-l+1)-maxfreq;

            while (flips>k){
                hash[s[l]-'A']--;
                l++;
                maxfreq = *max_element(hash, hash+26);
                flips = (r-l+1)-maxfreq;
            }
            if (flips<=k) maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};


// Optimal code:
class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int l=0, r=0, maxlen=0, maxfreq=0;
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq, hash[s[r]-'A']);
            int flips = (r-l+1)-maxfreq;

            if (flips>k){
                hash[s[l]-'A']--;
                l++;
            }
            if (flips<=k) maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};