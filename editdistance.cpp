//https://practice.geeksforgeeks.org/problems/edit-distance/0
//Edit Distance


#include <bits/stdc++.h>
using namespace std;

int pilihMin(int a, int b){
    if(a<=b) 
        return a;
    return b;
}
typedef vector<int> lv;
int minimumSteps(string s1,string s2,int n,int m, vector<lv> *memo){
    if(n==0)
        return m;
    if(m==0)
        return n;
    
    if((*memo)[n][m]!=-1){
        return (*memo)[n][m];
    }

    if(s1[n-1]==s2[m-1]){
        (*memo)[n][m] = minimumSteps(s1,s2,n-1,m-1,memo);
        return (*memo)[n][m];
    }
    (*memo)[n][m] = 1+pilihMin(minimumSteps(s1,s2,n-1,m-1,memo) //Replace
        ,pilihMin(minimumSteps(s1,s2,n-1,m,memo)//Hapus
        ,minimumSteps(s1,s2,n,m-1,memo)));
    return  (*memo)[n][m];//Add
    

    
}

int main(){



    int t;
    scanf("%d",&t);
    while(t){


        int n,m;
        scanf("%d %d",&n,&m);
        string s1,s2;
        cin>>s1>>s2;
        vector<lv> memo;
        for(int i=0;i<=n;i++){
            lv temp;
            for(int j=0;j<=m;j++){
                temp.push_back(-1);
            }
            memo.push_back(temp);
        }
        cout<<minimumSteps(s1,s2,n,m,&memo)<<endl;


        t--;
    }
}