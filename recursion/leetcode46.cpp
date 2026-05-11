/*
Leetcode 46: Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
 
*/


// Approach one - with the help of visited array

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void helper(int idx,vector<int>& visited, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums){
        if (idx==nums.size()){
            ans.push_back(ds);
            return;
        }

        for (int i =0;i<nums.size();i++){
            if (!visited[i]){
                visited[i] = 1;
                ds.push_back(nums[i]);
                helper(idx+1, visited, ds, ans, nums);
                ds.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>visited(nums.size(), 0);
        vector<vector<int>>ans;
        vector<int>ds;

        helper(0, visited, ds, ans, nums);
        return ans;
    }
};


// This is otimal because we are not using visited array
class Solution1 {
public:
    void helper(int idx, vector<vector<int>>&ans, vector<int>&nums){
        if (idx == nums.size()-1) {
            ans.push_back(nums);
            return;
        }

        for (int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            helper(idx+1, ans, nums);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    
        vector<vector<int>>ans;
        

        helper(0, ans, nums);
        return ans;
    }
};
