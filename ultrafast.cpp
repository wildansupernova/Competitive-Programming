//http://codeforces.com/problemset/problem/61/A
//Ultra-Fast Mathematician

#include <bits/stdc++.h>
using namespace std;


int main(){
    string s1,s2;

    cin>>s1>>s2;

    int panjang = s1.length();
    string baru;

    for(int i=0;i<panjang;i++){
        if(s1[i]!=s2[i]){
            baru.push_back('1');
        } else{
            baru.push_back('0');
        }
    }
    cout<<baru<<endl;

}