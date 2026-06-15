/*
Problem Statement: Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1). Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).
The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

Input: n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
Output: ["DDRDRR" , "DRDDRR"]
Explanation: The rat has two different path to reach (3, 3).
The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).
*/


// Approach - we will first check if the path is valid or not (condition to check for path valid or not - for moving up we have to check if row-1>0 for moving down we have to check for row+1<n for moving left col-1>0 for moving right col+1<n) and if path is valid then we will call the function again for next path and if we reach at row-1 and col-1 then we will push the path into the vector and return .


// Time Complexity - O(3^n)
// Space Complexity - O(n^2)

#include<bits/stdc++.h>
using namespace std;

void findPath(int row, int col, int n, vector<vector<int>>&grid, string s, vector<string>&ans){
    if (row==n-1 && col==n-1){
        ans.push_back(s);
        return;
    }

    // for down 
    if (row+1<n && grid[row+1][col]==1){
        grid[row+1][col] = 0;
        findPath(row+1, col, n, grid, s+'D', ans);
        grid[row+1][col] = 1;
    }

    // for left
    if (col-1>=0 && grid[row][col-1]==1){
        grid[row][col-1] = 0;
        findPath(row, col-1, n, grid, s+'L', ans);
        grid[row][col-1] = 1;
    }

    // for right
    if (col+1<n && grid[row][col+1]==1){
        grid[row][col+1] = 0;
        findPath(row, col+1, n, grid, s+'R', ans);
        grid[row][col+1] = 1;
    }

    // for up
    if (row-1>=0 && grid[row-1][col]==1){
        grid[row-1][col] = 0;
        findPath(row-1, col, n, grid, s+'U', ans);
        grid[row-1][col] = 1;
    }
}

int main(){

    vector<string>ans;
    vector<vector<int>> grid = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};

    findPath(0, 0, grid.size(), grid, "", ans);

    for (int i =0;i<ans.size();i++) cout<<ans[i]<<" ";

    return 0;
}
