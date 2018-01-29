//https://leetcode.com/problems/longest-common-prefix/
//longest common prefix
#include <bits/stdc++.h>
using namespace std;


string LCP(vector<string>& strs,int idx, int min, int n){
    if(idx>=min){
        return "";
    }
    for(int i=0;i<=n-2;i++){
        if(strs[i][idx]!=strs[i+1][idx]){
            return "";
        }
    }
    string temp;
    temp.push_back(strs[0][idx]);

    return temp + LCP(strs,idx+1,min,n);
}


string longestCommonPrefix(vector<string>& strs) {
    
    int n=strs.size();
    if(n==0){
        return "";
    }
    int nmax=INT_MAX;
    for(int i=0;i<n;i++){
        int hasil = strs[i].length();
        if(hasil<nmax){
            nmax = hasil;
        }
    }
    return LCP(strs,0,nmax,n);
}

int  main(){
    
    int n;
    vector<string> temp;
    cin>>n;
    for(int i=0;i<n;i++){
        string tem;
        cin>>tem;
        temp.push_back(tem);
    }
    cout<<longestCommonPrefix(temp)<<endl;
}