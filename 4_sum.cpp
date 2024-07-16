/*
Link: https://leetcode.com/problems/4sum/description/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>s;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long remainingSum = (target * 1ll) - (nums[i] * 1ll) - (nums[j] * 1ll);
                int k = j+1, l = n-1;
                while(k < l){
                    long long sum = (nums[k] * 1ll) + (nums[l] * 1ll);
                    if(sum > remainingSum){
                        l--;
                    } else if(sum < remainingSum){
                        k++;
                    } else {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};