/*

Leetcode 1004: Max consecutive ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

/* Solution - Again there are multiple ways to solve this question
1. Brute force - generate all the subarrays and check maxlen till zeros is lesser then or equal to k in this way you can get the max consecutive ones count

2. Better and optimal - using sliding window and two pointer 

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, maxlen=0, count=0;
        while (r<nums.size()){
            if (nums[r]==0) count++;
            // instead of while we can write if here that will be more optimal
            while (count>k){
                if (nums[l]==0) count--;
                l++;
            }
            if (count<=k)maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};

int main(){
    vector<int> v = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    Solution obj;
    cout<<obj.longestOnes(v,3);
    return 0;
}