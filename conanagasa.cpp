//http://codeforces.com/contest/914/problem/B

#include <bits/stdc++.h>
using namespace std;



int main(){
    map<int,int> hasil;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        hasil[temp]++;
    }
    bool conan = true;
    while(!hasil.empty()){
        if(conan)
            conan=false;
        else   
            conan=true;
        map<int,int> ::iterator itr = hasil.end();
        itr--;
        itr->second --;
        if(itr->second==0){
            hasil.erase(itr->first);
        }
        int now =itr->first;
        for(int i=0;i<now;i++){
            hasil.erase(i);
        }
    }
    if(conan){
        cout<<"Agasa"<<endl;
    } else
    {
         cout<<"Conan"<<endl;       
    }
}