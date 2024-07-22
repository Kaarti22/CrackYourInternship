/*
Link: https://www.geeksforgeeks.org/problems/word-wrap1646/1

Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

Example 1:

Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.
Example 2:

Input: nums = {3,2,2}, k = 4
Output: 5
Explanation: Given a line can have 4 
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 2
Line number 3: From word no. 3 to 3
Same explaination as above total cost
= (4 - 3)2 + (4 - 2)2 = 5.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function solveWordWrap() which takes nums and k as input paramater and returns the minimized total cost.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 ≤ n ≤ 500
1 ≤ nums[i] ≤ 1000
max(nums[i]) ≤ k ≤ 2000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int memoization(int ind, int rem, vector<int>& nums, int k){
        if(ind == nums.size()) return 0;
        if(dp[ind][rem] != -1) return dp[ind][rem];
        if(nums[ind] > rem){
            dp[ind][rem] = (rem + 1) * (rem + 1) + memoization(ind + 1, k - nums[ind] - 1, nums, k);
        } else {
            int choice1 = (rem + 1) * (rem + 1) + memoization(ind + 1, k - nums[ind] - 1, nums, k);
            int choice2 = memoization(ind + 1, rem - nums[ind] - 1, nums, k);
            dp[ind][rem] = min(choice1, choice2);
        }
        return dp[ind][rem];
    }

public:

    int dp[501][2001];

    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp, -1, sizeof(dp));
        return memoization(0, k, nums, k);
    } 
};