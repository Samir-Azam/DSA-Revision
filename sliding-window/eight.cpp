/*

Leetcode 930. Binary Subarrays With Sum
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/

/*
Thing to remember when we are required to find number of subarrays with exact sum then we can't determine when to expand and when to shrink so for that case what we have to do is we have to think for an alternative option the solutions are given below 

1. Brute force - we are going to generate each subarray and we will check if sum equal to the target or not if it is equal then we will increase the count otherwise we will break out 

2. Better - Use prefix Sum + hashing

3. Optimal - Sliding window instead of counting subarrays with sum==goal we will count the subarrays with sum<=k and substract it with count where sum<=k-1 as (sum==k) = (sum<=k)-(sum<=k-1)
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

    // Brute force Code
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;

        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for (int j=i;j<nums.size();j++){
                sum += nums[j];
                if (sum>goal) break;
                if (sum==goal) count++;
            }
        }
        return count;
    }
    // Better code starts


    int numSubarraysWithSumBetter(vector<int>& nums, int goal){
        unordered_map<int, int>mp;
        int sum = 0, count = 0;
        mp[0] = 1;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum - goal;
            if (mp.find(rem)!=mp.end()){
                count += mp[rem];
            }
            mp[sum]++;
        }
        return count;
        
    }


    // Optimal Code starts

    int numSubarraysWithSumLesserOrEqual(vector<int>& nums, int goal){
        if (goal<0) return 0;
        int count=0, sum=0, l=0, r=0;
        while (r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;

    }

    int numSubarraysWithSumOptimal(vector<int>& nums, int goal){
        
        return numSubarraysWithSumLesserOrEqual(nums, goal) - numSubarraysWithSumLesserOrEqual(nums, goal-1);
    }
};







int main(){

    vector<int>nums = {0,0,0,0,0};
    vector<int>nums1 = {1,0,1,0,1};

    Solution obj;
    int res1 = obj.numSubarraysWithSum(nums,0);
    int res2 = obj.numSubarraysWithSum(nums1,2);
    int res3 = obj.numSubarraysWithSumBetter(nums1,2);
    int res4 = obj.numSubarraysWithSumBetter(nums,0);
    cout<<res1<<" "<<res2<<endl;
    cout<<res3<<" "<<res4<<endl;
    return 0;
}