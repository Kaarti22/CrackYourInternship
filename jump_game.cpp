/*
Link: https://leetcode.com/problems/jump-game/description/

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n, false);
        dp[n-1] = true;
        for(int i=n-2; i>=0; i--){
            int jump = nums[i];
            for(int j=i+1; j<=(i+jump); j++){
                if(dp[j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};