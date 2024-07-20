/*
Link: https://leetcode.com/problems/reverse-words-in-a-string/submissions/1327005516/

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string t = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(t != ""){
                    ans += t;
                    ans += " ";
                    t = "";
                }
            } else {
                t += s[i];
            }
        }
        if(t != ""){
            ans += t;
            ans += " ";
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        int st = 0, end = -1;
        for(int i=0; i<ans.size(); i++){
            if(ans[i] == ' '){
                end = i;
                reverse(ans.begin() + st, ans.begin() + end);
                st = i+1;
            }
        }
        st = -1;
        for(int i=ans.size()-1; i>=0; i--){
            if(ans[i] == ' '){
                st = i;
                break;
            }
        }
        reverse(ans.begin() + st + 1, ans.end());
        return ans;
    }
};