/*

128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

/*
Solution: 
Brute Force: We will sort the array [100,4,200,1,3,2] and  [1, 2, 3, 4, 100, 200] then we will start iterating from first index we will check if current element is 1 greater than the previous one if it is we will increase the count (initially count will be 1) otherwise we will start the count from 1 again.At the end we will return the maximum count. Time complexity for this would be O(nlogn) and space complexity would be O(1).
*/

// brute force code
#include<bits/stdc++.h>
using namespace std;


int longestConsecutive(vector<int>& nums) {
    if (nums.size()<=1) return nums.size();
    sort(nums.begin(),nums.end());
    int count=1,maxCount=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]+1) count++;
        else count=1;
        maxCount = max(maxCount,count);
    }
    return maxCount;
}

/*
Optimal Solution: We will use a hashset we will put every number into it.And we will check for the starting number only if it is find then only we will iterate and update the count otherwise we will not do anything. Time complexity for this would be O(n) and space complexity would be O(n).
*/

// Optimal code 

class Solution1{

    int longestConsecutive(vector<int>&nums){

        unordered_set<int>st(nums.begin(),nums.end());

        int longest = 0;

        for (int num: nums){
            if (st.find(num-1)==st.end()){
                int currentNum = num;
                int count = 1;
                while (st.find(currentNum+1)!=st.end()){
                    currentNum++;
                    count++;
                }
                longest = max(longest, currentNum-num);
            }
        }
        return longest;
    }
};