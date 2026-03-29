/*

Similar question leetcode 189

Problem Statement: Given an integer array nums, rotate the array to the left by one.

Note: There is no need to return anything, just modify the given array.

Examples
Example 1:
Input:
 nums = [1, 2, 3, 4, 5]  
Output:
 [2, 3, 4, 5, 1]  
Explanation:
 Initially, nums = [1, 2, 3, 4, 5]  
Rotating once to the left results in nums = [2, 3, 4, 5, 1].

Example 2:
Input:
 nums = [-1, 0, 3, 6]  
Output:
 [0, 3, 6, -1]  
Explanation:
 Initially, nums = [-1, 0, 3, 6]  
Rotating once to the left results in nums = [0, 3, 6, -1].
*/

// it is very simple we just need to store the first element in a variable and then shift the array to the left by one and then put the first element in the last position.

#include<iostream>

#include<vector>
using namespace std;

int main(){


    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    // storing the first element 
    int first = arr[0];

    // shifting all the elements by one place left
    for (int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }

    // last element will be previous first element 
    arr[n-1] = first;

    // printing the elements
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



// for shifting k elements to the right 


class Solution {
public:
// you can replace this part and use built in reverse method
    void reverseArray(vector<int>& nums, int start, int end){
        int l = start;
        int r = end-1;
        while (l<r){
            // swapping logic
            int temp = nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
            r--;

        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverseArray(nums,0,  nums.size());
        reverseArray(nums, 0, k);
        reverseArray(nums, k, nums.size());
    }
};

