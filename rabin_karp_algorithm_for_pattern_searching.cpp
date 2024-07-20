/*
Link: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

Given a text T[0. . .n-1] and a pattern P[0. . .m-1], write a function search(char P[], char T[]) that prints all occurrences of P[] present in T[] using Rabin Karp algorithm. You may assume that n > m.

Examples: 

Input:  T[] = “THIS IS A TEST TEXT”, P[] = “TEST”
Output: Pattern found at index 10

Input:  T[] =  “AABAACAADAABAABA”, P[] =  “AABA”
Output: Pattern found at index 0
              Pattern found at index 9
              Pattern found at index 12
*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ll long long
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int madd(int a,int b) {
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

class Kaarti{
public:
    void method(string& text, string& pattern){
        int q = INT_MAX;
        int n = text.size(), m = pattern.size();
        int i, j;
        int p = 0; // hash value for pattern
        int t = 0; // hash value for text
        int h = 1, d = 256;
        // the value of h would be pow(d, m-1) % q
        rep(i,0,m-1){
            h = (h * d) % q;
        }
        // calculate the hash value of pattern and first window of text
        rep(i,0,m){
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }
        // slide the pattern over text one by one
        rep(i,0,n-m+1){
            // Check the hash values of current window of text and pattern. If the hash values match then only check for characters one by one
            if(p == t){
                // check for characters one by one
                j = 0;
                while(j < m){
                    if(text[i + j] != pattern[j]){
                        break;
                    }
                    j++;
                }
                if(j == m){
                    cout<<"Pattern found at index "<<i<<endl;
                }
            }
            // calculate hash value for next window of text: removing leadinf digit, add trailing digit
            if(i < n - m){
                t = (d * (t - text[i] * h) + text[i + m]) % q;
                // we might get negative value of t, converting it to positive
                if(t < 0){
                    t = (t + q);
                }
            }
        }
    }
};

int main(){
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    Kaarti *ob = new Kaarti;
    ob->method(text, pattern);
    return 0;
}