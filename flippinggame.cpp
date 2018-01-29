//http://codeforces.com/problemset/problem/327/A
//Flipping Game

#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int hitung1 = 0,hitung0=0,hitung0max = -1;

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;

        if(temp==1){
            hitung1++;
            if(hitung0>0){
                hitung0--;
            }
        } else{
            hitung0++;
            if(hitung0>hitung0max){
                hitung0max = hitung0;
            }
        }
    }

    cout<<hitung1+hitung0max<<endl;


}