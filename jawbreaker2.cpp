//https://training.ia-toki.org/training/curriculums/1/courses/11/chapters/52/problems/233/
//Jawbreaker 2
#include <bits/stdc++.h>
using namespace std;

int tab[25][25];

bool isValid(int m, int n,int x,int y){
    return x>=0 && x<m && y>=0 && y<n;
}

int hasil(int warna, int x,int y,int m, int n){
    if(tab[x][y]!=warna)
        return 0;
    tab[x][y] =0;
    int sum=1;
    if(isValid(m,n,x+1,y)){
        sum+= hasil(warna,x+1,y,m,n);
    }
    if(isValid(m,n,x-1,y)){
        sum+= hasil(warna,x-1,y,m,n);
    }
    if(isValid(m,n,x,y+1)){
        sum+= hasil(warna,x,y+1,m,n);
    }
    if(isValid(m,n,x,y-1)){
        sum+= hasil(warna,x,y-1,m,n);
    }
    return sum;
}
int main(){
    //Inisiasi;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>tab[i][j];
        }
    }
    int maxi=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(tab[i][j]!=0){
                int t=hasil(tab[i][j],i,j,m,n);
                t=t*(t-1);
                if(t>maxi){
                    maxi=t;
                }
            }
            
        }
    }
    cout<<maxi<<endl;
    
    
}