/* Leetcode 40: Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30 
*/

// Brute force 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx,int sum, int target, vector<int>&ds, set<vector<int>>&st, vector<int>&candidates){
        // Base Condition
        if (sum>target) return;
        if (idx==candidates.size()){
            if (sum==target){
                // sort
                vector<int>temp(ds.begin(), ds.end());
                sort(temp.begin(), temp.end());
                st.emplace(temp);
            }
            return;
        }

        // pick 
        ds.push_back(candidates[idx]);
        sum+=candidates[idx];
        helper(idx+1, sum, target, ds, st, candidates);
        sum-=candidates[idx];
        ds.pop_back();

        // not pick
        helper(idx+1, sum, target, ds, st, candidates);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>st;
        vector<int>v;
        helper(0, 0, target, v, st, candidates);
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};

// optimal solution: Instead of pick and non-pick we try to generate all the distinct subsequences


class Solution1 {
public:
    // try to generate all the subsequence
    void helper(int idx, int target, vector<int>&ds, vector<vector<int>>&ans , vector<int>& candidates){
        // base case 
        if (target==0){
            ans.push_back(ds);
            return;
        }
        

        for (int i=idx;i<candidates.size();i++){
          if (i>idx && candidates[i]==candidates[i-1]) continue;
          if (candidates[i]>target) break;

          if (candidates[i]<=target){
            ds.push_back(candidates[i]);
            helper(i+1, target-candidates[i], ds, ans, candidates);
            ds.pop_back();
          }
        }
        
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp(candidates.begin(), candidates.end());
        sort(temp.begin(), temp.end());
        vector<int>v;
        vector<vector<int>>ans; 
        helper(0, target, v, ans,temp);
        return ans;
    }
};

int main(){

    Solution S;
    vector<int>v = {2, 5, 2, 1, 2};
    vector<vector<int>>ans  = S.combinationSum2(v, 5);
    for (int i=0;i<ans.size();i++){
        for (int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}



