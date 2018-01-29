//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
//	Find the number of islands (Function Problem)
#include <bits/stdc++.h>

using namespace std;

const int MAX= 10;

bool isValid(int n, int m , int idxi, int idxj){
    return idxi>=0 && idxi<n && idxj>=0 && idxj<m;
}

void fillKosong(int A[MAX][MAX], int idxi, int idxj,int n, int m){
    if(isValid(n,m,idxi,idxj) && A[idxi][idxj] ==1){
        A[idxi][idxj] = 0;
        fillKosong(A,idxi-1,idxj,n,m);
        fillKosong(A,idxi+1,idxj,n,m);
        fillKosong(A,idxi,idxj-1,n,m);
        fillKosong(A,idxi,idxj+1,n,m);
        fillKosong(A,idxi-1,idxj-1,n,m);
        fillKosong(A,idxi-1,idxj+1,n,m);
        fillKosong(A,idxi+1,idxj-1,n,m);
        fillKosong(A,idxi+1,idxj+1,n,m);
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
//Your code here
    int counter=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]==1){
                //cout<<"halo";
                fillKosong(A,i,j,N,M);
                counter++;
            }
        }
    }
    return counter;

}
int main(){
    int n, m;
    cin>>n>>m;
    int arr[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            //cout<<arr[i][j];
        }
    }

    cout<<findIslands(arr,n,m)<<endl;
}


