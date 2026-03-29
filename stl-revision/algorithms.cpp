// built in algorithms that can be used to save time

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>



using namespace std;

// custom comparator 

struct Compare{
    bool operator()(int a, int b){
        if (a>=b) return true;
        return false;
    }
};

struct Compare2{
    bool operator()(pair<int, int>&p1, pair<int, int> &p2){
        if (p1.first==p2.first){
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
};

int main(){

    // for searching an element you can use binary_search if element is present it will return 1 otherwise 0.

    int arr[] = {1,2,3,4,5,6};

    bool res = binary_search(arr, arr+6, 10);
    // cout<<res;

    // finding max element for two elements you can use max 
    // cout<<max(2,3);

    // finding max_element in the array or vector this will return an pointer 
    int *position = max_element(arr, arr+6);
    // cout<<*position;
    // alternative way if you need the element directly instead of its pointer , then just dereference it 
    int max_ele = *max_element(arr, arr+6);
    // cout<<max_ele;

    // for min element the syntax is almost same 

    vector<int> v = {1,2,3};
    int ele = *min_element(v.begin(), v.end());
    // cout << ele;

    // for reversing use reverse(start, end);
    // reverse(v.begin(), v.end());

    // next_permutation 
    string count = "123";

    next_permutation(v.begin(), v.end());
    next_permutation(count.begin(), count.end());

    // for (int i=0;i<3;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl<<count<<endl;

    // it will work for both string and vector 


    // sort an vector using custom comparator

    vector<int> v1 = {2,6,7,1,0,-1,8,8};
    sort(v1.begin(), v1.end(), Compare());
    // for (int i=0;i<v1.size();i++){
    //     cout<<v1[i]<<" ";
    // }


    vector<pair<int,int>> v2 = {{1,3}, {1,4}, {2,1}, {4,2}};
    // sort first in ascending order on the basis of their first element if they are same then sort on the basis of their second element in descending order

    sort(v2.begin(), v2.end(), Compare2());
    
    // for (int i=0;i<v2.size();i++){
    //     cout<<v2[i].first<<"->"<<v2[i].second<<endl;
    // }


    return 0;
}