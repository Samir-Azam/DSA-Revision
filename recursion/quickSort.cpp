    // Quick Sort : It is also very simple we just have to understand the algorithm first then the implementation becomes a little easier

    /* Algorithm: 
    1. Select an pivot element in our case it will be the first element
    2. Find its correct position ( which means all the smaller element will be at the left of pivot and all the greater element will be at the right of it )
    3. repeat the same process for the left and right halves
    */

    #include<bits/stdc++.h>
    using namespace std;

    int partition(int low, int high, vector<int>& nums){

    int pivot = nums[low];

    int left = low + 1;
    int right = high;

    while(left <= right){

        while(left <= high && nums[left] <= pivot)
            left++;

        while(right >= low && nums[right] > pivot)
            right--;

        if(left < right){
            swap(nums[left], nums[right]);
        }
    }

    swap(nums[low], nums[right]);

    return right;
    }

    void quickSort(int low, int high, vector<int>&nums){
        if (low>=high) return;
        int partitionIndex = partition(low, high, nums);
        quickSort(low, partitionIndex-1, nums);
        quickSort(partitionIndex+1, high, nums);
    }



    int main(){
        vector<int>nums = {5, 4, 3, 2, 1};
        quickSort(0, nums.size()-1, nums);

        for (int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        return 0;
    }