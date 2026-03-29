/*

Leetcode - 283

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/

// Approach - This is very easy question there can be multiple approach to solve this question my approach will solve this question in one iteration using two pointers we know that we have to move all the zeros at the end so we can maintain an index which will be initially at zeroth index and it will only store elements that is non zero and after storing non-zero element just increment it.

// leetcode solution code 

#include<vector>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // for storing unique elements
        int idx = 0;

        // storing unique elements 
        for (int i=0;i<n;i++){
            if (nums[i]!=0) nums[idx++]=nums[i];
        }

        // storing zeros
        for (int i = idx ;i<n;i++){
            nums[i] = 0; 
        }
    }
};

// TC - O(N), SC-O(1)