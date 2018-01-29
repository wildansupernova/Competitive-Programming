//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
//Largest Sum contiguous subarray

#include <bits/stdc++.h>
using namespace std;

int pilihMax(int a,int b){
    if(a>=b) {return a;}

    return b;
}   

void largestSum( int tab [],int n,int *sumSebelum, int *maxnow){
    if(n==1){
        *maxnow = tab[0];
        *sumSebelum = tab[0];
    } else{
         int p,maxnya;
         largestSum(tab,n-1,&p,&maxnya);
         *sumSebelum = pilihMax(tab[n-1],p+tab[n-1]);
         if (*sumSebelum>maxnya){
            *maxnow = *sumSebelum;
         } else{
             *maxnow = maxnya;
         }
    }
}
int main(){


    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        
        int n;
        scanf("%d",&n);
        int temp[n];
        for(int j=0;j<n;j++){
            scanf("%d",&temp[j]);
        }
        int p,c;
        largestSum(temp,n,&p,&c);
        printf("%d\n",c);
    }
}