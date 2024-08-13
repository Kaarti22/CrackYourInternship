/*
Link: https://leetcode.com/problems/ones-and-zeroes/description/

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findLargestSubset(vector<string>& strs, int ind, int len, int m, int n, vector<vector<vector<int>>>& dp){
        if(ind >= len) return 0;
        if(dp[ind][m][n] != -1) return dp[ind][m][n];
        int ones = 0, zeroes = 0;
        for(auto it: strs[ind]){
            if(it == '0') zeroes++;
            else ones++;
        }
        if(ones <= n && zeroes <= m){
            return dp[ind][m][n] = max(1 + findLargestSubset(strs, ind + 1, len, m - zeroes, n - ones, dp), findLargestSubset(strs, ind + 1, len, m, n, dp));
        }
        return dp[ind][m][n] = findLargestSubset(strs, ind + 1, len, m, n, dp);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>>dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return findLargestSubset(strs, 0, len, m, n, dp);
    }
};