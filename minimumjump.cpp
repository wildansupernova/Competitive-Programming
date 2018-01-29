//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
//Minimum number of jumps


#include <bits/stdc++.h>
using namespace std;

int pilihMin(int a, int b){
    if(a<=b) 
        return a;
    return b;
}

int minJump(int arr[],int n,int idx,int memo[]){
    if(n-1==idx)
        return 0;
    int min = 1000000000;
    int i =idx+1;
    if(memo[idx]!=-1){
        return memo[idx];
    }
    while(i<=idx+arr[idx] && i<=n-1){
        if(arr[i]!=0){
            min = pilihMin(min,1+minJump(arr,n,i,memo));
        } else{
            if(n-1==i){
                min = pilihMin(min,1+minJump(arr,n,i,memo));
            }
        }
        i++;
    }
    memo[idx] = min;
    return min;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t){

        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int memo[n+1];
        memset(memo,-1,sizeof(memo));
        int hasil =minJump(arr,n,0,memo);
        if(hasil>=1000000000){
            cout<<-1<<endl;
        } else{
            cout<<hasil<<endl;
        }
        
        

        t--;
    }
}