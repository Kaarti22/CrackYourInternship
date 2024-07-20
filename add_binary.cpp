/*
Link: https://leetcode.com/problems/add-binary/description/

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.size(), m = b.size();
        int carry = 0, i = n-1, j = m-1;
        while(i >= 0 && j >= 0){
            int sum = carry + (a[i] - '0') + (b[j] - '0');
            if(sum <= 1){
                ans += to_string(sum);
                carry = 0;
            } else if(sum == 3) {
                ans += "1";
                carry = 1;
            } else {
                ans += "0";
                carry = 1;
            }
            i--, j--;
        }
        while(i >= 0){
            int sum = carry + (a[i] - '0');
            if(sum <= 1){
                ans += to_string(sum);
                carry = 0;
            } else if(sum == 3) {
                ans += "1";
                carry = 1;
            } else {
                ans += "0";
                carry = 1;
            }
            i--;
        }
        while(j >= 0){
            int sum = carry + (b[j] - '0');
            if(sum <= 1){
                ans += to_string(sum);
                carry = 0;
            } else if(sum == 3) {
                ans += "1";
                carry = 1;
            } else {
                ans += "0";
                carry = 1;
            }
            j--;
        }
        if(carry == 1) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};