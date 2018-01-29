//Longest Common Subsequence
// Problems : https://www.geeksforgeeks.org/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;
int pilihMaks(int a, int b){
    if(a>=b) 
        return a;
    return b;
}
typedef vector<int> lv;
int jawaban(string a,string b,int m, int n, vector<lv> *p){
    if( m==0 || n==0){
        return 0 ;
          
    } else{
        if((*p)[m][n]!=-1){
            return  (*p)[m][n];
        }
        if(a[m-1]==b[n-1] ){
            (*p)[m][n] = 1+jawaban(a,b,m-1,n-1,p); 
            return (*p)[m][n];
        } else{
            (*p)[m][n] = pilihMaks(jawaban(a,b,m-1,n,p),jawaban(a,b,m,n-1,p));
            return (*p)[m][n];
        }
    }
}

int main(){


    string a,b;
    cin>>a>>b;
    vector<lv> memo;
    for (int i=0;i<=a.length();i++){
        vector<int> temp;
        for(int j=0;j<=b.length();j++){
            
            temp.push_back(-1);

        }
        memo.push_back(temp);
    }

    
    cout<<"Terpanjangnya adalah : "<<jawaban(a,b,a.length(),b.length(),&memo)<<endl;
}