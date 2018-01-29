#include <bits/stdc++.h>

using namespace std;

//https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0
//Google-CountABC

int dp[1001][2][3];

int hasil(int n,int b, int c){
    if(n==0){
        return 1;
    }
    if(dp[n][b][c]!=-1)
        return dp[n][b][c];
    if(b==0 && c==0){
            return 1;
    }

    if(b==0){
        dp[n][b][c] = hasil(n-1,b,c-1) + hasil(n-1,b,c);
        return dp[n][b][c];
    }
    if(c==0){
        dp[n][b][c] =hasil(n-1,b-1,c) + hasil(n-1,b,c);;
        return dp[n][b][c];
    }
    dp[n][b][c] = hasil(n-1,b,c-1) + hasil(n-1,b,c) + hasil(n-1,b-1,c);
    return  dp[n][b][c];


}
int main(){
    int t;
    scanf("%d",&t);


    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    dp[i][j][k]= -1;
                }
            }
        }
        cout<<hasil(n,1,2)<<endl;
    }


}