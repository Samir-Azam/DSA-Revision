// this file has three common factors that are used to solve problem related to subsequences

// 1: Print all the subsequences whose sum == k 


#include<bits/stdc++.h>
using namespace std;

// print all subsequence whose sum==k
void printAll(int idx, int n, int sum, int k, vector<int>&ds, int arr[]){
    // Base Condition

    if (idx==n){
        if (sum==k){
            for (int i: ds) cout<<i<<" ";
            cout<<endl;
            return;
        }
        return;
    }

    // Pick 
    ds.push_back(arr[idx]);
    sum+=arr[idx];
    printAll(idx+1, n, sum, k, ds, arr);
    ds.pop_back();
    sum-=arr[idx];

    // not pick 
    printAll(idx+1, n, sum, k, ds, arr);
}


// 2: print only one subsequence whose sum==k

bool printOne(int idx, int n, int sum, int k, vector<int>&ds, int arr[]){
    // Base Condition
    if (idx==n){
        if (sum==k){
            for (int i: ds) cout<<i<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    // Pick 
    ds.push_back(arr[idx]);
    sum+=arr[idx];
    if (printOne(idx+1, n, sum, k, ds, arr)==true) return true;
    ds.pop_back();
    sum-=arr[idx];

    // not pick 
    return printOne(idx+1, n, sum, k, ds, arr);
}

// total count of subsequence whose sum==k

int subsequenceCount(int idx, int n, int sum, int k, vector<int>&ds, int arr[]){
    // Base Condition

    if (idx==n){
        if (sum==k){
            return 1;
        }
        return 0;
    }

    // Pick 
    ds.push_back(arr[idx]);
    sum+=arr[idx];
    int include = subsequenceCount(idx+1, n, sum, k, ds, arr);
    ds.pop_back();
    sum-=arr[idx];

    // not pick 
    int exclude = subsequenceCount(idx+1, n, sum, k, ds, arr);
    return include+exclude;
}


int main(){

    int arr[] = {1,3,1};
    vector<int>v = {};
    
    printAll(0, 3, 0, 2, v, arr);
    printOne(0, 3, 0, 2, v, arr);
    cout<<subsequenceCount(0, 3, 0, 2, v, arr)<<endl;
    return 0;
}