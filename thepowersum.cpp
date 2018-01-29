//https://www.hackerrank.com/challenges/the-power-sum/problem
//The Power Sum


#include <bits/stdc++.h>

using namespace std;


typedef long long gede;
long long power(long long x,  long long y)
{
    long long temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}


gede cekrekur(gede x,gede n ,gede i,gede sum){

    gede hasil=0;
    gede cek = power(i,n);
    while(cek + sum<x){
         hasil += cekrekur(x,n,i+1,sum+cek);
         i++;
         cek = power(i,n);
    }

    if(cek+sum==x){
        hasil++;
    }
    return hasil;
}
int main(){


    int x,n;
    cin>>x>>n;
    cout<< cekrekur(x,n,1,0)<<endl;

}