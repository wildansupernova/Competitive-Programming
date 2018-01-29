//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/18/problems/72/
//Menggambar Pegunungan

#include <bits/stdc++.h>

using namespace std;

void gambarGunung(int n){
    if(n==1){
        cout<<"*"<<endl;
    } else{
        gambarGunung(n-1);
        for(int i=1;i<=n;i++){
            cout<<"*";
        }
        cout<<endl;
        gambarGunung(n-1);
    }
}

int main(){
    int n;
    cin>>n;
    gambarGunung(n);
}

