
#include <bits/stdc++.h>
using namespace std;
//Test Bukalapak 1

void printvector( vector<int> tab){
    for(int i=tab.size()-1;i>=0;i--){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void printRekur(int arr[],int n,int angkaTujuan,vector<int> simpen){
    if(angkaTujuan==1 && simpen.size()>0){
        if (simpen.size()==1){
            simpen.push_back(1);
        }
        printvector(simpen);
    } else if (n>0){
        if((angkaTujuan%arr[n-1]!=0)){
            printRekur(arr,n-1,angkaTujuan,simpen);
        } else{
            printRekur(arr,n-1,angkaTujuan,simpen);
            simpen.push_back(arr[n-1]);
            printRekur(arr,n-1,angkaTujuan/arr[n-1],simpen);
            simpen.pop_back();
        }
    }
}

int main(){

    int n,angkaTujuan;
    cin>>n>>angkaTujuan;
    int arr [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> permulaan;
    printRekur(arr,n,angkaTujuan,permulaan);
}