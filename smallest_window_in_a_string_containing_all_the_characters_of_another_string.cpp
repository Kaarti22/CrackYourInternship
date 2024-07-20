/*
Link: https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(n) n = len(p)

 

Constraints: 
1 ≤ |S|, |P| ≤ 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(p.size() > s.size()) return "-1";
        vector<int>phash(26, 0), shash(26, 0);
        for(int i=0; i<p.size(); i++){
            phash[p[i] - 'a']++;
        }
        int curr = 0, i = 0, j = 0, st = -1, len = 0, minLength = INT_MAX;
        while(j < s.size()){
            shash[s[j] - 'a']++;
            if(phash[s[j] - 'a'] != 0 && shash[s[j] - 'a'] <= phash[s[j] - 'a']){
                curr++;
            }
            if(curr == p.size()){
                while(shash[s[i] - 'a'] > phash[s[i] - 'a'] || phash[s[i] - 'a'] == 0){
                    if(shash[s[i] - 'a'] > phash[s[i] - 'a']){
                        shash[s[i] - 'a']--;
                        i++;
                    }
                }
                len = j - i + 1;
                if(len < minLength){
                    st = i;
                    minLength = len;
                }
            }
            j++;
        }
        if(st == -1) return "-1";
        return s.substr(st, minLength);
    }
};