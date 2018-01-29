#include <bits/stdc++.h>
using namespace std;
//http://codeforces.com/problemset/problem/474/A
//Keyboard

int main(){


    string temp,s;
    temp = "qwertyuiopasdfghjkl;zxcvbnm,./";

    char inp;
    cin>> inp;
    cin>>s;
    int panjang = s.length();
    if (inp=='R'){
        for(int i=0;i<panjang;i++){
            int fin = temp.find(s[i]);
            cout<<temp[fin-1];
        }
    }else{
        for(int i=0;i<panjang;i++){
            int fin = temp.find(s[i]);
            cout<<temp[fin+1];
        }
    }
    cout<<endl;
}