//Kefa and First Steps
//http://codeforces.com/problemset/problem/580/A


#include <bits/stdc++.h>
using namespace std;


int main(){
    int n ;
    cin >>n;
    int tab[n];
    for(int i=0;i<n;i++){
        cin>>tab[i];
    }
    bool memo[n];
    for(int i=0;i<n;i++){
        memo[i]=false;
    }
    int max=0;
    int i=0;
    while(i<n){
        if(memo[i]==false){
            int pembanding = tab[i];
            int count =0; 
            for(int j  = i;j<n;j++){
                if(tab[j]>=pembanding){
                    count++;
                    pembanding = tab[j];
                    memo[j]=true;
                } else{
                    break;
                }
            }
            if(count >=max){
                max = count;
            }
        }        
        i++;

        
    }

    cout<<max<<endl;
}