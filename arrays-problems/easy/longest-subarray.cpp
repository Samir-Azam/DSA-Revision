/*
Longest Subarray with given Sum K(Positives)

Problem Statement: Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
*/

/* It can be solved using three approaches 
1. Brute force -  we can generate all the subarrays and check for sum if sum == k and we will update the maximum length 
2. Better using hashing of prefixSum (prefixSum concept)
3. Since it has all the positive integers then we can use sliding window shrink if condition is invalid extend if it is valid 
*/
#include<iostream>
#include<vector>

using namespace std;

int longestSubarrayLength(vector<int> &nums, int k){
    int sum = 0;
    int l=0,r=0;
    int maxLen = 0;
    while (r<nums.size()){
        sum += nums[r];
        while (sum > k){
            sum -= nums[l];
            l++;
        }
        if (sum==k) {
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}


int main(){
    vector<int>v = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout<<longestSubarrayLength(v, k);
    return 0;
}