//Longest Common Substring
//https://practice.geeksforgeeks.org/problems/longest-common-substring/0


#include <bits/stdc++.h>

using namespace std;

int pilihMax(int a, int b){
    if (a>=b)
        return a;
    return b;
}

typedef vector<int> lv;
int hitungPanjangCommon(string s1, string s2, int n, int m){
    if(n==0 || m==0)
        return 0;

    if (s1[n-1]==s2[m-1]){
        return 1+hitungPanjangCommon(s1,s2,n-1,m-1);
    } else{
        return 0;
    }
        
}
int longestSubStr(string s1, string s2,int n,int m,vector<lv> *memo){
    if (m==0)
        return 0;
    if (n==0)
        return 0;
    if((*memo)[n][m]!=-1)
        return (*memo)[n][m];
    if(s1[n-1]==s2[m-1]){
        int a = pilihMax(hitungPanjangCommon(s1,s2,n,m),longestSubStr(s1,s2,n-1,m-1,memo));
        int b = pilihMax(longestSubStr(s1,s2,n-1,m,memo),longestSubStr(s1,s2,n,m-1,memo));
        (*memo)[n][m] = pilihMax(a,b);
        return (*memo)[n][m];
    }

    (*memo)[n][m] = pilihMax(longestSubStr(s1,s2,n-1,m,memo),longestSubStr(s1,s2,n,m-1,memo));
    return (*memo)[n][m];

}


int main(){


    int t;
    scanf("%d",&t);

    while(t){
        int n,m;
        scanf("%d %d",&n,&m);
        string s1,s2;
        cin>>s1>>s2;
        vector<lv> memo;
        for(int i=0;i<=n;i++){
            lv temp;
            for(int j=0;j<=m;j++){
                temp.push_back(-1);
            }
            memo.push_back(temp);
        }
        cout<<longestSubStr(s1,s2,n,m,&memo)<<endl;
        t--;
    }
}