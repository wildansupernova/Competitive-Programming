//http://codeforces.com/problemset/problem/82/A
//Double Cola

#include <bits/stdc++.h>
using namespace std;



int main(){
    string s[5]  ={"Sheldon","Leonard","Penny","Rajesh","Howard"};

    int low=0;
    int high=5;
    int n;
    cin>>n;
    while(n>high){
        int sisa=high-low;
        low=high;
        high=high + (sisa*2);
        //cout<<"dsa";
    }

    int sisa = high-low;
    int pembagi = sisa/5;
    int sisan = n-low;

    if(sisan%pembagi==0){
        cout<<s[(sisan/pembagi)-1]<<endl;
    } else{
        cout<<s[sisan/pembagi]<<endl;
    }



}