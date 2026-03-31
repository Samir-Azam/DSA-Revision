/*

Leetcode 1248: Count number of nice subarrays

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

*/

/*
Solution: It is kind of similar to the eighth question instead of sum == k we have to check for k odd numbers we can solve it in the exact same way by converting odd as 1 (odd%2==1) and even to 0 (even%2==0).
*/

// Optimal Code 
#include<vector>
using namespace std;



class Solution {
public:
    int helper(vector<int>& nums, int k){
        if (k<0) return 0;
        int l=0, r=0, oddCount=0, res=0;
        while(r<nums.size()){
            oddCount += (nums[r]%2);
            while (oddCount>k){
                oddCount -= (nums[l]%2);
                l++;
            }
            res += (r-l+1);
            r++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k)-helper(nums, k-1);
    }
};