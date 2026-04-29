/*

Leetcode 54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.


Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

/*
Solution: It is very simple we just have to print the matrix in spiral order. So we will use four pointers (left, right, top and bottom) we will and we will initialize the left as 0, right as columns-1, top as 0 and bottom as row-1.And we will use a while loop which runs till (left<=right and top<=bottom) and we will print in the spiral order. Starting from left to right and then from top to bottom and then from right to left and then from bottom to top.

but while printing be aware of two edge cases first one is when we have single row so in that case check before printing right to left otherwise we will print the same row twice. Second is when we have single column so in that case check before printing bottom to top otherwise we will print the same column twice.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int left=0, right=columns-1, top=0, bottom=rows-1;

        vector<int>ans;
        while (left<=right && top<=bottom){

            // left to right 
            for (int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            // moving to next line
            top++;

            // top to bottom
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }

            // decrementing right to prevent duplication
            right--;

            // edge case when we have only one row
            if (top>bottom) break;
            // right to left
            for (int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            // decrementing bottom 
            bottom--;

            // edge case when we have only one column
            if (right<left) break;
            // bottom to top
            for (int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        return ans;
    }
};