/*
Link: https://leetcode.com/problems/valid-palindrome-ii/description/

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        string t = s;
        int i = 0, j = n-1;
        int ind1 = -1, ind2 = -1;
        while(i <= j){
            if(s[i] != s[j]){
                ind1 = i;
                ind2 = j;
                break;
            }
            i++, j--;
        }
        if(ind1 == -1) return true;
        string one, two;
        for(int i=0; i<n; i++){
            if(i != ind1) one.push_back(s[i]);
            if(i != ind2) two.push_back(s[i]);
        }
        string reverseOne = one;
        string reverseTwo = two;
        reverse(reverseOne.begin(), reverseOne.end());
        reverse(reverseTwo.begin(), reverseTwo.end());
        if(one == reverseOne || two == reverseTwo) return true;
        return false;
    }
};