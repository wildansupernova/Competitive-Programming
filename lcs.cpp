//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
//Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int maxx(int a, int b){
    if(a>b)
        return a;
    return b;
}

int lcs(string s1,string s2,int m,int n){
    if(dp[m][n]!=-1)
        return dp[m][n];
    int solusi;
    if(m==0||n==0){
        dp[m][n] = 0;
        return dp[m][n];
    }
        
    if(s1[m-1]==s2[n-1]){
        dp[m][n] = 1+ lcs(s1,s2,m-1,n-1);
        
        return dp[m][n];

    }
    dp[m][n] = maxx(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    return dp[m][n];
}

int main(){
    int t;
    cin>>t;
    while(t){
        int m,n;
        cin>>m>>n;
        string s1, s2;
        cin>>s1>>s2;
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                dp[i][j]=-1;
            }
        }
        cout<<lcs(s1,s2,m,n)<<endl;
        t--;
    }
}