//https://www.hackerrank.com/challenges/ctci-ransom-note/problem
//Hash Tables: Ransom Note

#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    map<string,int> tab;


    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        tab[s]++;
    }
    bool bisa =true;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        map<string,int>::iterator itr;
        itr = tab.find(s);
        if(itr!=tab.end()){
            if (itr->second >0){
                (itr->second)--;

            } else{
                bisa=false;
            }
        } else{
            bisa=false;
        }
    }

    if(bisa){
        cout<<"Yes";
    } else{
        cout<<"No";
    }

    cout<<endl;
}