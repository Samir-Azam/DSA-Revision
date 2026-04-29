/*
53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

/*
We can generate all the subarrays and and check for the sum and update the maxsum
or we can use kadane's algorithm which is the optimal approach to solve this problem in one pass - approach: We have to keep track of two variables maxSum and currentSum intially they both will first element in the array(present at 0th index) and then currentSum will be updates as per this condition 
currentSum = max(currentSum + nums[i], nums[i]);

maxSum = max(currentSum, maxSum);
at the end return maxSum
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        for (int i=1;i<nums.size();i++){
            currSum = max(nums[i], currSum+nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

// A Little follow up - If i have to find the starting and ending index in that case we have to modify the code a little 


class Solution1{
    public:

    // we will be returning maxSum, startIndex and endIndex
    vector<int> kadane(vector<int> &nums){
        int currSum = nums[0], maxSum = nums[0], start = 0, end = 0, tempStart = 0;

        for (int i=1;i<nums.size();i++){
            
            if (nums[i]>currSum+nums[i]){
                tempStart = i;
                currSum = nums[i];
            }else{
                currSum += nums[i];
            }

            if (currSum > maxSum){
                start = tempStart;
                maxSum = currSum;
                end = i;
            }
        }

        return {start, end, maxSum};
    }
};


int main(){

    vector<int> arr1 = {5,4,-1,7,8};
    vector<int> arr2 = {-2,1,-3,4,-1,2,1,-5,4};

    Solution1 obj;
    vector<int>res1 = obj.kadane(arr1);
    vector<int>res2 = obj.kadane(arr2);


    int start = res1[0], end = res1[1], maxSum = res1[2];
    for (int i = start; i<=end;i++){
        cout<< arr1[i]<< " ";
    }
    cout<<"\n"<<maxSum<<"\n";

    int start2 = res2[0], end2 = res2[1], maxSum2 = res2[2];
    for (int i = start2; i<=end2;i++){
        cout<< arr2[i]<< " ";
    }
    cout<<"\n"<<maxSum2<<"\n";
    return 0;
}
