#include <bits/stdc++.h>
//https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
//Arrays -Left rotation
using namespace std;



int main(){

    int n,d;
    cin>>n>>d;
    queue<int> tab;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        tab.push(temp);
    }
    while(d){
        int temp = tab.front();
        tab.pop();
        tab.push(temp);
        d--;
    }

    while(!tab.empty()){
        cout<<tab.front()<<" ";
        tab.pop();
    }

    cout<<endl;


}