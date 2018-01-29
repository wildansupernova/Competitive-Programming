//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/18/problems/74/
//Brankas Terkunci


#include <bits/stdc++.h>

using namespace std;


void printVector(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<arr[i];
        } else{
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

void printAll(vector<int> permut,int n,int k){
    if(permut.size()==k){
        printVector(permut);
    } else{
        int panjang = permut.size();
        if(panjang==0){
            for(int i=1;i<=n;i++){
                //if(!isDipakai[i]){
                    //isDipakai[i] = true;
                    permut.push_back(i);
                    printAll(permut,n,k);
                    permut.pop_back();
                    //isDipakai[i] = false;                
                //}
            }            
        } else{
            int sebelumnya = permut[panjang-1];
            for(int i=sebelumnya+1;i<=n;i++){
                //if(!isDipakai[i]){
                    //isDipakai[i] = true;
                    permut.push_back(i);
                    printAll(permut,n,k);
                    permut.pop_back();
                    //isDipakai[i] = false;                
                //}
            }
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    //bool isDipakai[n+1]; 
    vector<int> awal;
    printAll(awal,n,k);

}