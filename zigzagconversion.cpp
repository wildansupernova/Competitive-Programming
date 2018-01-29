//https://leetcode.com/problems/zigzag-conversion/description/
//Zig Zag conversion
#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if(numRows==1){
        return s;
    }
    vector<string> temp(numRows,"");
    int n  =s.length();    
    int now=0  ;
    bool down=true;
    for(int i=0;i<n;i++){
        temp[now].push_back(s[i]);
        if(down){
            if(now==numRows-1){
                down=false;
                now--;
            } else{
                now++;
            }
        } else{
            if(now==0){
                down=true;
                now++;
            } else{
                now--;
            }
        }
    }
    string temp2 = "";
    for(int i=0;i<numRows;i++){
        temp2 = temp2 + temp[i];
    }
    return temp2;
}


int main(){

    string s ; 
    cin>>s;
    int r;
    cin>>r;
    cout<<convert(s,r)<<endl;
}