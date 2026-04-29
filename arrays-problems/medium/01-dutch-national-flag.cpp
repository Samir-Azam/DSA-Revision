
/*
Leetcode : 75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/


/*
1. We can solve it by counting zeros, ones and twos for that we need three variables and one loop to iterate over all elements. But this is a two pass solution to solve it in one pass we can use Dutch National Flag algorithm.
2. Direct implementation of dutch national algorithm is to use three pointers low, mid and high and keep swapping the elements.
index 0 to low-1 are 0s, index low to mid-1 are 1s and index mid to high-1 is unsorted part and high to n-1 are 2s.
*/


// code 
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