//Petak Menarik
//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/15/problems/58/

#include <bits/stdc++.h>

using namespace std;



int main(){
    int n,m,k;
    cin>>n>>m>>k;

    int arr[n+2][m+2];

    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            arr[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    //Susur kolom
    int x=n+10,y=m+10;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int atas = arr[i-1][j];
            int bawah = arr[i+1][j];
            int kiri = arr[i][j-1];
            int kanan = arr[i][j+1];
            int menarik = atas*bawah*kiri*kanan;
            if(menarik==k){
                if(j<y){
                    y=j;
                    x=i; 
                    
                }
            }
        }
    }
    if((x==n+10) && (y==m+10)){
        cout<<"0 0"<<endl;
    
    } else{ 

        for(int i=1;i<=n;i++){
            int atas = arr[i-1][y];
            int bawah = arr[i+1][y];
            int kiri = arr[i][y-1];
            int kanan = arr[i][y+1];
            int menarik = atas*bawah*kiri*kanan;  

            if(menarik==k){
                if(i<x){
                    x=i;
                }
            }         
        }
        cout<<x<<" "<<y<<endl;
    }
}