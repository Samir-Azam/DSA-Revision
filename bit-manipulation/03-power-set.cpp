/*
Leetcode 78: Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

/*
 Approach is very simple there is a fact for an array of size n there are 2^n possible subsets and each subset will have size from 0 to n.
 These subsets can be represented as binary counting from 0 to 2^n-1. 
 Eg: for an array of size 3 there are 8 possible subsets and these can be represented as binary number from 0 to 7.
 0 0 0 
 0 0 1
 0 1 0
 0 1 1
 1 0 0
 1 0 1
 1 1 0
 1 1 1

 where one means we have include that element in the subset and zero means we have not included that element in the subset since the subset maximum size is n we have iterate till n. T.C - O(2^n*n)

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        int length = 1<<n;
        for (int i =0;i<length;i++){
            vector<int>res;
            for (int j=0;j<n;j++){
                if ((i&(1<<j))) res.push_back(nums[j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};