/*
Link: https://leetcode.com/problems/word-search/description/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int row, int col, int ind, int n, int m, vector<vector<char>>& board, string& word){
        if(ind == word.size()) return true;
        if(row < 0 || col < 0 || row >= n || col >= m || word[ind] != board[row][col]){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '\0';
        bool ans = dfs(row + 1, col, ind + 1, n, m, board, word) || dfs(row - 1, col, ind + 1, n, m, board, word) || dfs(row, col + 1, ind + 1, n, m, board, word) || dfs(row , col - 1, ind + 1, n, m, board, word); 
        board[row][col] = temp;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(i, j, 0, n, m, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};