/*
Link: https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Example 1:

Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 
Example 2:

 

Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(vector<vector<char>>& mat, int x, int y){
        int n = mat.size(), m = mat[0].size();
        if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] != 'O') return;
        mat[x][y] = '*';
        for(auto d: dir){
            int newX = x + d[0], newY = y + d[1];
            dfs(mat, newX, newY);
        }
    }

public:

    vector<vector<int>>dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(mat[i][j] = 'O'){
                        dfs(mat, i, j);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                } else if(mat[i][j] == '*'){
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};