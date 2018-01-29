//http://codeforces.com/problemset/problem/469/A
// I Wanna Be the Guy


#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    bool lv[n];
    for(int i=0;i<n;i++){
        lv[i]=false;
    }
    int a;
    cin>>a;
    for(int i = 1;i<=a;i++){
        int temp ;
        cin>>temp;
        lv[temp-1]=true;
    }
    cin>>a;
    for(int i = 1;i<=a;i++){
        int temp ;
        cin>>temp;
        lv[temp-1]=true;
    }
    int bisa = true;
    for(int i=0;i<n;i++){
        if (!lv[i]){
            bisa=false;
            break;

        }
    }

    if(bisa){
        cout<<"I become the guy.";
    } else{
        cout<<"Oh, my keyboard!";
    }

    cout<<endl;
}