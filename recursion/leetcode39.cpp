// combination sum - you have to print all the subsequence whose sum==k but you can take same element twice


#include<bits/stdc++.h>
using namespace std;
// set<vector<int>>st;

void combinationSum(int idx, int n,int sum, int k, vector<int>&ds, int arr[]){
    // Base Case 
    if (sum>k) return;
    
    if (idx==n){
        if (sum==k){
            for (auto it: ds) cout<<it<<" ";
            // st.insert(ds);
            cout<<endl;
        }
        return;
    }

    // pick - you can pick multiple times
    sum+=arr[idx];
    ds.push_back(arr[idx]);
    combinationSum(idx, n, sum, k, ds, arr);
    sum-=arr[idx];
    ds.pop_back();

    // not pick
    combinationSum(idx+1, n, sum, k, ds, arr);
}

int main(){
    int arr[] = {1,1,2,4};
    vector<int>v;
    combinationSum(0, 4, 0, 4, v, arr);
    // for (auto it : st){
    //     for (int i=0;i<it.size();i++){
    //         cout<<it[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}