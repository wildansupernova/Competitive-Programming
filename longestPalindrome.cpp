//https://leetcode.com/problems/longest-palindromic-substring/description/
//Longest Palindrome
#include <bits/stdc++.h>
using namespace std;

bool isPalin(string s, int front , int back){

    while(front<=back){
        if(s[front]!=s[back]){
            return false;
        }
        front++;
        back--;
    }
    return true;
}
typedef pair<int,int> pr;
typedef vector<pr> vpr;
typedef vector<vpr> vpr2d;
string longestPalindrome(string s) {
    int length = s.length();
    //bool dp[length][length];
    //Inisiasi Awal
    bool dp[length][length];
    memset(dp,0,sizeof(dp));
    int start = 0;
    int maxLength = 1;
    for(int i=0;i<length;i++){
        dp[i][i] = true;
    }
    for(int i=0;i<length-1;i++){
        
        if(s[i]==s[i+1]){
            dp[i][i+1] =true;
            start = i;
            maxLength = 2;
        }

    }
    for(int i=3;i<=length;i++){
        for(int j=0;j<=length-i;j++){
            
            int k = j+i-1;

            if(dp[j+1][k-1] && s[j]==s[k]){
                dp[j][k]=true;
                if(i>maxLength){
                    maxLength = i;
                    start = j;
                }
            }
        }

    }


    return s.substr(start,maxLength);
}

int main(){
    string temp;
    cin>>temp;

    cout<<longestPalindrome(temp)<<endl;
}

