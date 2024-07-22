/*
Link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& vis){
        int n = grid.size(), m = grid[0].size();
        vis[x][y] = true;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i == 0 && j == 0) continue;
                int newX = x + i, newY = y + j;
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1' && !vis[newX][newY]){
                    dfs(grid, newX, newY, vis);
                }
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, i, j, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};