
/*
Leetcode 51: N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

// Approach is simple we have to place queens row by row and for each row we will try to place the columns in each of the row and if it is not getting attacked by any other queen then we will place queen in that column and we have to repeat this process until we reach at the last row and if we reach at the last row that means the solution is correct and we will store that solution afterwards.

// This solution is not optimal because everytime we are taking O(n) time complexity to check whether it is being attacked or not we will reduce this time complexity to O(1) in the next solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 

    bool beingAttacked(vector<string>&temp, int row, int n, int col){
        // check straight line keep col same decrement the row

        int r = row;
        int c = col;
        while (r>=0){
            if (temp[r][c]=='Q') return true;
            r--;
        }

        r = row;
        c= col;
        // check for diagonally right 
        while (r>=0 && c<n-1){
            if (temp[r][c+1]=='Q') return true;
            r--;
            c++;
        }

        r = row;
        c = col;
        // check for diagonally left 

        while(r>=0 && c>0){
            if (temp[r][c-1]=='Q') return true;
            r--;
            c--;
        }

        return false;
    }

    void solve(int idx, int n, string &s, vector<string>&temp, vector<vector<string>>&ans){
        if (idx==n){
            ans.push_back(temp);
            return;
        }

        for (int i=0;i<n;i++){
            if (!beingAttacked(temp, idx-1, n, i)){
                string helper = s;
                helper[i] = 'Q';
                temp.push_back(helper);
                solve(idx+1, n, s, temp, ans);
                temp.pop_back();
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>temp;

        string s(n,'.');
        
        solve(0, n, s, temp, ans);
        return ans;
    }
};

