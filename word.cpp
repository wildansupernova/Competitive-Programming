#include <bits/stdc++.h>
using namespace std;

//http://codeforces.com/problemset/problem/59/A
//Word


bool islower(char b){
    return b>='a' && b<='z';
}
int main(){

    string s;
    cin>>s;
    int cUp=0,cLow=0;

    for(int i=0;i<s.length();i++){
        if(islower(s[i])){
            cLow++;
        } else{
            cUp++;
        }
    }
    string temp;
    if(cLow>=cUp){
        for(int i=0;i<s.length();i++){
            if(islower(s[i])){
                temp.push_back(s[i]);
            } else{
                temp.push_back(s[i]-'A'+'a');
            }
        }
    } else{
        for(int i=0;i<s.length();i++){
            if(islower(s[i])){
                temp.push_back(s[i]-'a'+'A');
            } else{
                temp.push_back(s[i]);
            }
        }
    }

    cout<< temp<<endl;

    
}
