//https://practice.geeksforgeeks.org/problems/min-cut-square/0
//Min Cut square

#include <bits/stdc++.h>

using namespace std;




int minimum(int a,int b){
    if(a<=b)
        return a;
    return b;
}

int memo[101][101];
int hasil(int a, int b){
    if(memo[a][b]!=-1){
        return memo[a][b];
    }
    if(a==b)
        return 1;
    int minver = INT_MAX;
    int minhor = INT_MAX;
    for(int i=1;i<=a/2;i++){
        minver = minimum(minver,hasil(i,b)+ hasil(a-i,b)); 
    }

    for(int j=1;j<=b/2;j++){
        minhor = minimum(minhor,hasil(a,j)+hasil(a,b-j));
    }
    memo[a][b] = minimum(minver,minhor); 
    return memo[a][b];

}






int main(){

    int t;
    scanf("%d",&t);
    while(t){
        int a,b;
        scanf("%d %d",&a,&b );
        memset(memo,-1,sizeof(memo[0][0])*101*101);
        printf("%d\n",hasil(a,b));
        t--;
    }


}