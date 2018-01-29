//Vasya and Socks
//http://codeforces.com/problemset/problem/460/A
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    int count=0;
    while(n!=0){
        count++;
        n--;
        if(count%m==0){
            n++;
        }
    }

    cout<<count<<endl;


}