/*
Link: https://leetcode.com/problems/maximum-product-of-three-numbers/

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int prod = nums[0] * nums[1] * nums[2];
        if(nums[n-1] < 0 && nums[n-2] < 0){
            prod = max(prod, nums[0] * nums[n-1] * nums[n-2]);
        }
        return prod;
    }
};