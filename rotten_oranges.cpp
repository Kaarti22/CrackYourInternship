/*
Link: https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        queue<pair<int,int>>temp;
        while(!q.empty()){
            queue<pair<int,int>>t = q;
            bool f = 0;
            while(!t.empty()){
                pair<int,int>p = t.front();
                t.pop();
                vis[p.first][p.second] = 1;
                for(auto d: dir){
                    int x = p.first + d[0];
                    int y = p.second + d[1];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                        if(vis[x][y] == 0){
                            vis[x][y] = 1;
                            grid[x][y] = 2;
                            temp.push({x, y});
                            f = 1;
                        }
                    }
                }
            }
            if(f){
                ans++;
                f = 0;
            } else {
                break;
            }
            q = temp;
            queue<pair<int,int>>e;
            temp = e;
        }
        bool f = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    f = 1;
                    break;
                }
            }
        }
        if(f) ans = -1;
        return ans;
    }
};