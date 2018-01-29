//https://practice.geeksforgeeks.org/problems/n-queen-problem/0
//N-Queen
#include <bits/stdc++.h>
using namespace std;



void printAll(vector<int>temp,int n){
    cout<<"[";
    for(int i=0;i<n;i++){
            cout<<temp[i]<< " ";
        
    }
    cout<<"]";
}

bool verticalCheck(vector<int> temp,int column){
    int n=temp.size();
    for(int i=0;i<n;i++){
        if(temp[i]==column){
            return false;
        }
    }
    return true;
}
bool diagonalCheck(vector<int> temp,int column){
    int n=temp.size();
    int now = n+1;
    for(int i=0;i<n;i++){
        if(temp[i]==column-(now-(i+1)) || temp[i]==column+(now-(i+1))){
            return false;
        }
    }
    return true;
}
void cari(int n,vector<int> temp, int idx,int *counter){
    if(idx==n){
        printAll(temp,n);
        (*counter)++;
        cout<<" ";
    } else{
        for(int i=1;i<=n;i++){
            if(diagonalCheck(temp,i) &&  verticalCheck(temp,i)){
                temp.push_back(i);
                cari(n,temp,idx+1,counter);
                temp.pop_back();
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int>temp;
        int counter=0;
        cari(n,temp,0,&counter);
        if(counter==0){
            cout<<-1;
        }
        cout<<endl;
        t--;
    }
}