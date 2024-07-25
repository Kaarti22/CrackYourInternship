/*
Link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        int ans = 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int i=0; i<n+1; i++){
            dp[i][0] = 0;
        }
        for(int i=0; i<m+1; i++){
            dp[0][i] = 0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
