#include <bits/stdc++.h>
using namespace std;


//http://codeforces.com/problemset/problem/144/A
// Arrival of the General
int main(){
    int n;
    cin>>n;
    int a[n];
    int idxmax = 0;
    int idxmin = 0;
    
    for(int i =0;i<n;i++){
        cin>>a[i];
        if(a[i]>a[idxmax]){
            idxmax = i;
        }
        if(a[i]<=a[idxmin]){
            idxmin = i;
        }

    }
    if(idxmin<idxmax){
        cout<<idxmax+(n-1-idxmin)-1;
    }   else{
        cout<<idxmax+(n-1-idxmin);
    }
    cout<<endl;

}
