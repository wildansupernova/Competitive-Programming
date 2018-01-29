//Longest Increasing Subsequence
//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int pilihMaks(int a, int b){
    if(a>=b) 
        return a;
    return b;
}

typedef vector<int> lv;
int hasil(int arr[],int n,int sebelumnya ,vector< lv > *tab){
    if(n==0){
        return 0;
    } else{

        if((*tab)[n][sebelumnya]!=-1){

            return (*tab)[n][sebelumnya];
        }
        if(arr[n-1]<sebelumnya){
            int a = 1+hasil(arr,n-1,arr[n-1],tab);
            int b = hasil(arr,n-1,sebelumnya,tab);
             (*tab)[n][sebelumnya]= pilihMaks(a,b);
            return (*tab)[n][sebelumnya];
        } else{
            (*tab)[n][sebelumnya] = hasil(arr,n-1,sebelumnya,tab);
            return (*tab)[n][sebelumnya];
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int arr[n];

        vector <lv> memo; 
        for (int o=0;o<=n+2;o++){
            vector<int> temp;
            for(int j=0;j<=302;j++){
                
                temp.push_back(-1);

            }
            memo.push_back(temp);
        }
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        printf("%d\n",hasil(arr,n,302,&memo));
        memo.clear();
    }
}