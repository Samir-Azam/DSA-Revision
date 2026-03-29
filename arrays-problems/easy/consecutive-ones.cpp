/*
Leetcode 485. Max Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1's in the array.


Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
*/

// Approach - It is very simple i will keep track of current count and also update the maximum count always the count will be increased if i will get another one otherwise it will become 0.


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = INT32_MIN;
        int count = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==1) count++;
            if (nums[i]==0) count = 0;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

int main(){
    vector<int>v = {1,1,0,0,0,1,1,1};

    Solution s;
    cout<<s.findMaxConsecutiveOnes(v)<<endl;

    return 0;
}