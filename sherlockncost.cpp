//https://www.hackerrank.com/challenges/sherlock-and-cost/problem
//Sherlock and Cost

#include <bits/stdc++.h>

using namespace std;


typedef vector<int> lv;

int pilihMax(int a, int b){
    if (a>=b)
        return a;
    return b;
}
int abso(int temp){
    if (temp<0){
        return 0-temp;
    } 
    return temp;
}

int terbesar(int arr[],int n, int sebelumnya,int panjangArr,vector<lv> *memo){
    if (n==0)
        return 0;
    if((*memo)[n][sebelumnya]!=-1)
        return (*memo)[n][sebelumnya];
    if(panjangArr==n){
        (*memo)[n][sebelumnya] = pilihMax(terbesar(arr,n-1,arr[n-1],panjangArr,memo),terbesar(arr,n-1,1,panjangArr,memo));
        return (*memo)[n][sebelumnya];
    }

    int a = abso(sebelumnya-arr[n-1]);
    int b = abso(sebelumnya-1);
    (*memo)[n][sebelumnya] =pilihMax(a+terbesar(arr,n-1,arr[n-1],panjangArr,memo),b+terbesar(arr,n-1,1,panjangArr,memo));
    return (*memo)[n][sebelumnya];
    
}
int main(){

    int  t;
    scanf("%d", &t);
    while(t){
        int n;
        scanf("%d",&n);
        int arr[n];
        vector<lv> memo;
        for(int i=0;i<=n;i++){
            lv temp;
            for(int j=0;j<=100;j++){
                temp.push_back(-1);
            }
            memo.push_back(temp);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        printf("%d\n",terbesar(arr,n,arr[n-1],n,&memo));
        t--;
    }
}