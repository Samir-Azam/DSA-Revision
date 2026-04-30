// Powerset: (Striver Recursion Playlist: Lecture 6) generate all the subsequences of a string there are another way of doing this problem that is using bitmasks but right now we are learning about recursion so it is purely implemented using recursion.

// Tc - O(2^n * n) -> where n is the size of the array
// Sc - O(n)

#include<bits/stdc++.h>
using namespace std;

void subsequence(int i, int n, vector<int>& v, int arr[]){
    if (i==n){
        for (int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
        return;
    }

    // not take - exclude element
    subsequence(i+1, n, v, arr);

    // take - include element
    v.push_back(arr[i]);
    subsequence(i+1, n, v, arr);
    v.pop_back();
}

int main(){

    int arr[] = {1,2,3};
    vector<int>v;
    subsequence(0, 3, v, arr);
    return 0;
}
