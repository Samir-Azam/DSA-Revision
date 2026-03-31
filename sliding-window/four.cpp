/*
Leetcode 904 : Fruits into basckets

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/

/* Solution : We can collect only two types of fruits so for keeping track of it we have to use a hashmap or hashset.

1.Brute force: Generate all the possible subarrays that be our answer using four loops if the type is 2 and update the maxlen
2.Better and optimal : Use sliding window and pointers approach where we will expand the window if the size of hasmap is lesser than or equal to 2 , if it greater then we will shrink it size using left pointer and at any point count of a type becomes 0 we will delete it from the hashmap.
*/


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l=0, r=0, maxlen=0;
        while (r<fruits.size()){
            mp[fruits[r]]++;
            if (mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2) maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};