//http://codeforces.com/problemset/problem/189/A
//Cut Ribbon

#include <bits/stdc++.h>
using namespace std;



int main(){

    int n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<int> tab;
    tab.push_back(a);
    tab.push_back(b);
    tab.push_back(c);
    sort(tab.begin(),tab.end());
    int d,e,f;
    d=n/tab[0];
    e=n/tab[1];
    f=n/tab[2];
    int maks = 0;
    int maks2 = 0;
    int yes = 0;
    for(int i =d;i>=0;i--){
        for(int j=0;j<=e;j++){
            int temp = (tab[0]*i)+(tab[1]*j);
            if(temp==n){
                maks2= i+j;
                yes=1;break;
            }
        }
        if(yes==1){
            break;
        }
    }
    yes=0;
    for(int i=d;i>=0;i--){
        for(int j=0;j<=e;j++){
            for(int k=0;k<=f;k++){
                int temp = (tab[0]*i)+(tab[1]*j)+(tab[2]*k);
                if (temp==n){
                    //cout<<i<<" "<<j<<" "<<k<<endl;
                    maks= max(maks,i+j+k);
                    yes = 1;
                    break;
                }
            }
            if (yes==1){
                break;
            }
        }
        if (yes==1){
                break;
        }
    }
    cout<<max(maks,maks2)<<endl;
}