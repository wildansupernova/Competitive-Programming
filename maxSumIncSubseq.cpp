//Maximum sum increasing subsequence
//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;


typedef vector<int> lv;
int pilihMax(int a, int b){
    if(a>=b)
        return a;
    return b;
}

int theFunction(int tab[],int n,int sebelumnya,vector<lv> *memo){
    if (n==0) //Kasus kalo udah sampe nol ngebalikin  nilai 0
        return 0;

    if((*memo)[n][sebelumnya]!=-1){ //Bagian DP, kalau nilai sudah dikomputasikan
            return (*memo)[n][sebelumnya];// kembalikan lagi nilai yang sudah ada
    }
    if(tab[n-1]>=sebelumnya){ //jika n-1ebih besar dari sebelumnya langsung lewat aja
        (*memo)[n][sebelumnya] = theFunction(tab,n-1,sebelumnya,memo);
        return (*memo)[n][sebelumnya];
    } else{ //Jika tidak jangan langsung lewat cobain yang ditambah tab[n-1]
        (*memo)[n][sebelumnya] = pilihMax(tab[n-1]+ theFunction(tab,n-1,tab[n-1],memo),
        theFunction(tab,n-1,sebelumnya,memo));
        return (*memo)[n][sebelumnya];
    }
    
    
}



int main(){

    int t;
    scanf("%d",&t);
    while(t){
        int n;
        scanf("%d",&n);
        int arr[n];


        for(int i=0;i<n;i++){
            cin>>arr[i];
        }


        vector<lv> memo;

        for(int i=0;i<=n;i++){
            lv temp;
            for(int  j=0;j<=1500;j++){
                temp.push_back(-1);
            }
            memo.push_back(temp);
        }
        cout<<theFunction(arr,n,1500,&memo)<<endl;
        t--;
    }
}