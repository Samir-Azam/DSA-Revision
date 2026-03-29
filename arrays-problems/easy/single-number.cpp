/*
Leetcode - 136 (Single Number)

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

 

*/


/* Unlike other problems there are  multiple methods to solve this question we will cover only optimal one and take overview of the other solution 

1. Brute force - Use two nested loops and check count of each number if a number has count = 1 , then we will return that tc-O(n^2) and sc-O(1)
2. Better Solution - We will use hashing we will store frequency of every number and then later on we will the frequency for each number number with frequency = 1 will be our answer. Tc - O(Nlogn) and Sc-O(n) worst case

3. Optimal one - use xor operator 
logic of xor 
0^any_number = number_itself
num^num = 0

so it will covert all the duplicate numbers to 0 and at the end xor will be containing the unique element
*/


#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i =0 ;i<nums.size();i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};