/*
Link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

Example:

Input: S = “geeksforgeeks”
Output:

e, count = 4
g, count = 2
k, count = 2
s, count = 2

Explanation: e,g,k,and s are characters which are occured in string in more than one times.
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
    void method(string& s){
        unordered_map<int, int>m;
        for(auto it: s){
            m[it]++;
        }
        for(auto it: m){
            if(it.second > 1){
                cout<<it.first<<", count = "<<it.second<<endl;
            }
        }
    }
};

int main(){
    string s;
    cin>>s;
    Kaarti *ob = new Kaarti;
    ob->method(s);
    return 0;
}