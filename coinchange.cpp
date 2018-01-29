//https://practice.geeksforgeeks.org/problems/coin-change/0
//Coins Change problem

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lv;


int hasil(int arr[],int n,int idx,vector<lv> *memo){
    if (n==0)
        return 1;
    if (n<0)
        return 0;
    
    if(idx==0){
        return 0;
    }
    if((*memo)[n][idx]!=-1){
        return (*memo)[n][idx];
 
    } else{
        (*memo)[n][idx] = hasil(arr,n- arr[idx-1],idx,memo) + hasil(arr,n,idx-1,memo);
        return (*memo)[n][idx];
    }
    


}


int main(){
    int t;
    scanf("%d",&t);
    for(int pass = 0;pass<t;pass++){
         int m;
        scanf("%d",&m);
        int arr[m];
        for(int i=0;i<m;i++){
            cin>> arr[i];
        }
        int n;
        scanf("%d",&n);
        //////
        vector<lv> memo;
        for(int i=0;i<=n;i++){
            lv temp;
            for(int j=0;j<=m;j++){
                temp.push_back(-1);
            }
            memo.push_back(temp);
        }
        cout<<hasil(arr,n,m,&memo)<<endl;
        /////////////////////
  
    }


}