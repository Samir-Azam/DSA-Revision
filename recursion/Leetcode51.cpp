
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

/* 
optimal ways to check if it is being attacked or not for that we will create three vectors 
1. upwards (to check for is it column safe or not) 
2. up_right (to check for diagonally upwards right direction) - use(row+col) and its size should be 2*n-1
3. up_left (to check for diagonally upwards left direction) - use((n-1) - (row-col)) and its size should be 2*n-1

*/
// T.C - N! (Optimal code below)


class SolutionOptimal {
public:

    void solve(int row, int n, vector<string>&board, vector<vector<string>>&ans, vector<int> &upwards,vector<int>&up_right, vector<int>&up_left){

        if (row==n){
            ans.push_back(board);
            return;
        }

        for (int col=0;col<n;col++){
            if (upwards[col]==0 && up_right[row+col]==0 && up_left[(n-1)-(row-col)]==0){
                board[row][col] = 'Q';
                upwards[col] = 1;
                up_right[row+col] = 1;
                up_left[(n-1)-(row-col)] = 1;
                solve(row+1, n, board, ans, upwards, up_right, up_left);
                board[row][col] = '.';
                upwards[col] = 0;
                up_right[row+col] = 0;
                up_left[(n-1)-(row-col)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        string s(n, '.');

        // creating the board
        for (int i=0;i<n;i++){
            board.push_back(s);
        }

        vector<vector<string>>ans;

        vector<int> upwards(n, 0);
        vector<int>up_right(2*n-1, 0);
        vector<int>up_left(2*n-1, 0);

        solve(0, n, board, ans, upwards, up_right, up_left);
        return ans;

    }
};


