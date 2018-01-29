//Path in Matrix
//https://practice.geeksforgeeks.org/problems/path-in-matrix/0


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lv;
int pilihMaks(int a, int b){
    if(a>=b) 
        return a;
    return b;
}

bool isLegal(int i, int j, int n){
    return (i>=0 && i<n) && (j>=0 && j<n);
}

int hasil(vector<lv> tab,int i,int j,int n,vector<lv> *memo){
    if (!isLegal(i,j,n)){
        return -1;
    }
    if((*memo)[i][j] != -1){
        return (*memo)[i][j];
    }
    if(n-1==i){
        (*memo)[i][j]=tab[i][j];
        return tab[i][j];
    } else{

        int a = hasil (tab,i+1,j,n,memo);
        int b = hasil (tab,i+1,j+1,n,memo);
        int c = hasil (tab,i+1,j-1,n,memo);
        int d[3]={a,b,c};
        int maksnya = -1;
        for(int passi=0;passi<3;passi++){
            if (d[passi]>maksnya){
                maksnya= d[passi];
            }
        }
        if(maksnya==-1){
            (*memo)[i][j] = tab[i][j];
            return (*memo)[i][j];
        } else{
            (*memo)[i][j] = maksnya + tab[i][j];
            return (*memo)[i][j];
        }
    }

}

int cobaSemuaAtasnya(vector<lv> tab,int n){
    int maksnya = -1;
    vector <lv> memo;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(-1);
        }
        memo.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int temp = hasil(tab,0,i,n,&memo);
        if(temp>maksnya){
            maksnya = temp;
        }
    }

    return maksnya;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector <lv> tab;
        for(int j=0;j<n;j++){
            lv temp;
            for(int k=0;k<n;k++){
                int tmp;
                scanf("%d",&tmp);
                temp.push_back(tmp);
            }
            tab.push_back(temp);
        }
        //Code goes here
        cout<< cobaSemuaAtasnya(tab,n)<<endl;
    }

    
}