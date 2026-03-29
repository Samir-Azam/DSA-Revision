/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.

NOTE: Elements in the union should be in ascending order.
*/

// Solution: to find the union we just need to all the elements that is present either in array1 or array2 and we have to make sure that every element is stored only once


#include<iostream>

#include<vector>
using namespace std;

vector<int>  findUnion(int arr1[], int arr2[], int n, int m){
    vector<int>res;
    int l=0,r=0;

    while(l<n && r<m){
        if (arr1[l]<=arr2[r]){
            if (res.empty() || res.back()!=arr1[l]) {
                res.push_back(arr1[l]);
            }
            l++;
        }else{
            if (res.empty() || res.back()!=arr2[r]) {
                res.push_back(arr2[r]);
            }
            r++;
        }
    }

    while(l<n){
    if (res.empty() || arr1[l] != res.back()){
        res.push_back(arr1[l]);
    }
    l++;
    }

    while(r<m){
    if (res.empty() || arr2[r] != res.back()){
        res.push_back(arr2[r]);
    }
    r++;
}

    return res;
}

int main(){

    int arr1[] = {1,1,2,3,4,5};
    int arr2[] = {1,2,3,7,8,9};

    vector<int>ans = findUnion(arr1, arr2, 6, 6);

    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}