/*
Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        unordered_map<int, int>m;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(prefixSum[i] == k){
                ans++;
            }
            if(m.find(prefixSum[i] - k) != m.end()){
                ans +=m[prefixSum[i] - k];
            }
            m[prefixSum[i]]++;
        }
        return ans;
    }
};