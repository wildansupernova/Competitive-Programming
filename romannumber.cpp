//https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0
//Roman Number
//Twitter, Microsoft, Facebook, Amazon Problem
#include <bits/stdc++.h>
using namespace std;

int convert(string s,map <char,int> mep){
    int n =s.length();
    if(n==1){
        return mep[s[0]];
    } else{
        int total = 0;
        for(int i=1;i<=n;i++){
            if(i==n){
                total+=mep[s[i-1]];
            } else if(mep[s[i-1]]>=mep[s[i]]){
                total+=mep[s[i-1]];
            } else if(mep[s[i-1]]<mep[s[i]]) {
                total+=mep[s[i]]-mep[s[i-1]];
                i++;
            }
        }
        return total;
    }

}


int main() {
	int t;
    cin>>t;
    map <char,int> mep;
    mep['I']=1;
    mep['V']=5;
    mep['X']=10;
    mep['L']=50;
    mep['C']=100;
    mep['D']=500;
    mep['M']=1000;
    while(t){
        string s;
        cin>>s;
        cout<<convert(s,mep);
        cout<<endl;
       
        t--;
    }
	return 0;
}