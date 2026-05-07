// This is very simple -> It is based on divide and merge technique where you have to divide the array (virtually) in two halves unless we only have a single element and after that you have to merge it 


#include<bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, vector<int>&nums){
    int left = low;
    int right = mid+1;
    vector<int>temp;
    while (left<=mid && right<=high){
        if (nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while (right<=high){
        temp.push_back(nums[right]);
        right++;
    }

    int idx = 0;
    for (int i=low;i<=high;i++){
        nums[i] = temp[idx];
        idx++;
    }
}

void mergeSort(int low, int high, vector<int>&nums){
    // Base Case
    if (low==high) return;
    int mid = (low+high)/2;
    mergeSort(low, mid, nums);
    mergeSort(mid+1, high, nums);
    merge(low, mid, high, nums);
}

int main(){

    vector<int>nums = {5,4,3,2,1};
    mergeSort(0, (nums.size()-1), nums);
    for (int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}


// T.C - O(n*logn) for every case and S.C = O(logn)