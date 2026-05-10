/*
Leetcode 90: Subsets II

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>
using namespace std;


// 1 Brute force 

class Solution0 {
public:
    void helper(int idx, vector<int>&ds, set<vector<int>>&ans, vector<int>&nums){

        if (idx==nums.size()){
            ans.insert(ds);
            return;
        }

        // pick 
        ds.push_back(nums[idx]);
        helper(idx+1, ds, ans, nums);
        ds.pop_back();

        // not pick
        helper(idx+1, ds, ans, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0, ds, ans, nums);
        vector<vector<int>>res(ans.begin(), ans.end());
        return res;
    }
};



// 2 Optimal 

class Solution {
public:
    void helper(int idx, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums){

        ans.push_back(ds);
        if (idx==nums.size()){
            return;
        }

        for (int i=idx;i<nums.size();i++){
            if (i>idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i+1, ds, ans, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>ds;
        helper(0, ds, ans, nums);
        return ans;
    }
};


int main(){

    vector<int>nums = {1,2,2};
    Solution obj;
    vector<vector<int>>ans = obj.subsetsWithDup(nums);
    for (int i=0;i<ans.size();i++){
        for (int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}