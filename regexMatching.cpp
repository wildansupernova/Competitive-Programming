//Regular Expression Matching
//https://leetcode.com/problems/regular-expression-matching/description/
#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector< vb > vbb;

bool isSame(char a, char pattern){
    if(pattern=='.'){
        return true;
    } else{
        return a==pattern;
    }
}

bool isMatchUtil(string s, string p, int idxs, int idxp, vbb &dp){
    
    if(dp[idxs][idxp]){
        return dp[idxs][idxp];
    }
    if(idxs==0 && idxp==0){
        dp[idxs][idxp] = true;
        return dp[idxs][idxp];
    }

    if(idxs==0){
        if(p[idxp-1]=='*'){
            dp[idxs][idxp] = isMatchUtil(s,p,idxs,idxp-2,dp);
        } else{
            dp[idxs][idxp] = false;
        }
            
        
        return dp[idxs][idxp];
    }

    if(idxp==0){
        dp[idxs][idxp] = false;
        return dp[idxs][idxp];
    }

    switch(p[idxp-1]){
        case '*':
                if(!isSame(s[idxs-1],p[idxp-2])){
                    dp[idxs][idxp] = isMatchUtil(s,p,idxs,idxp-2,dp);
                } else{
                    dp[idxs][idxp] = isMatchUtil(s,p,idxs,idxp-2,dp) || isMatchUtil(s,p,idxs-1,idxp,dp);
                }
                return  dp[idxs][idxp];
                break;

        case '.' :
                dp[idxs][idxp] =isMatchUtil(s,p,idxs-1,idxp-1,dp);
                return dp[idxs][idxp];
                break;
        default : 
                if(s[idxs-1]==p[idxp-1]){
                    dp[idxs][idxp] = isMatchUtil(s,p,idxs-1,idxp-1,dp);
                    return dp[idxs][idxp];
                } else{
                    dp[idxs][idxp] = false;
                    return dp[idxs][idxp];
                }
    }
}


bool isMatch(string s, string p) {
    vb temp(1001,false);
    vbb dp (1001,temp);
    return isMatchUtil(s,p,s.length(),p.length(),dp);    
}


int main(){
    vector<int> temp (10,1);
    vector< vector<int> > vpr (10,temp);


    string s1,s2;
    cin>>s1>>s2;
    if(isMatch(s1,s2)){
        cout<<"YES";
    } else{
        cout<<"NO";
    }

    cout<<endl;
}