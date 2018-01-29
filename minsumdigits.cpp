//https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits/0
//Min sum formed by digits


#include <bits/stdc++.h>

using namespace std;


int hasil(int n, vector<int> temp){
    sort(temp.begin(),temp.end());
    int a = 0;
    for(int i=0;i<n;i=i+2){
        a = (a*10)+temp[i];
    }
    int b = 0;
    for(int i=1;i<n;i=i+2){
        b = (b*10)+temp[i];
    }
    return a+b;
}


int main(){


    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int> temp;
        for(int i=0;i<n;i++){  
            int tem;
            cin>>tem;
            temp.push_back(tem);
        }
        cout<<hasil(n,temp)<<endl;
        
        t--;
    }
}