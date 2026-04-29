/*
Leetocode: 169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

/*
Discussion: 

This problem can be easily a frequency map where we have to store the frequency of each element and then return the element which has frequency more than n/2.
But since the follow up is asking to solve the question in O(1) space we have to use the Boyer-Moore Voting Algorithm.

where there are three steps:
1. if count is 0, assign the current element to candidate and set count to 1.
2. if the current element is the same as candidate, increment count.
3. if the current element is not the same as candidate, decrement count.

if the count is still greater than 0, then the element is the majority element.

Time Complexity: O(n)   
Space Complexity: O(1)
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while (mid<=high){
            if (nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if (nums[mid]==1) mid++;
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return;
    }
};