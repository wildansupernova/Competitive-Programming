//https://leetcode.com/problems/longest-palindromic-substring/description/
//Longest Palindrome
#include <bits/stdc++.h>
using namespace std;

pair<int,int> dp[1001][1001]; 

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



pair<int,int> longestPalinDP(string s ,int front, int back){

    if(dp[front][back].first!=-1 && dp[front][back].second!=-1){
        return dp[front][back];
    }
    if(isPalin(s,front,back)){
        dp[front][back] = {front,back};
        return dp[front][back];
    }
    pair<int,int> t = longestPalinDP(s,front+1,back);
    pair<int,int> p = longestPalinDP(s,front,back-1);
    if(p.second-p.first>=t.second-t.first){
        dp[front][back] = p;
    } else{
        dp[front][back] = t;
    }

    return dp[front][back];
}

string longestPalindrome(string s) {
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            dp[i][j] = {-1,-1};
        }
    }
    pair<int,int> hasil = longestPalinDP(s,0,s.length()-1);
    string temp;
    for(int i=hasil.first;i<=hasil.second;i++){
        temp.push_back(s[i]);
    }
    return temp;
}

int main(){
    string temp;
    cin>>temp;

    cout<<longestPalindrome(temp)<<endl;
}
