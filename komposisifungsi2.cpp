//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/17/problems/68/
//Komposisi Fungsi II
#include <bits/stdc++.h>

using namespace std;
int absolut(int x){
    if(x<0)
        return 0-x;
    return x;
}


int functionCompose(int a, int b,int x, int n){
    if(n==1){
        return absolut((a*x)+b);
    } else{
        return absolut((a*functionCompose(a,b,x,n-1))+b);
    }
}

int main(){

    int a,b,k,x;
    cin>>a>>b>>k>>x;
    cout<<functionCompose(a,b,x,k)<<endl;
}