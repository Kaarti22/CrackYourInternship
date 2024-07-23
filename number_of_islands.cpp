/*
Link: https://leetcode.com/problems/number-of-islands/description/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m){
        queue<pair<int,int>>q;
        q.push({r, c});
        vis[r][c] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int newRow = row + dir[k][0];
                int newCol = col + dir[k][1];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0){
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    ans++;
                    bfs(i, j, vis, grid, n, m);
                }
            }
        }
        return ans;
    }
};