//https://practice.geeksforgeeks.org/problems/unique-bsts/0
//Unique BST'BST


#include <bits/stdc++.h>

using namespace std;
bool tanda[17];

bool cekSemuaTrue(int n){
    int semua=true;
    for(int i=1;i<=n;i++){
        if(!tanda[i]){
            semua=false;
        }
    }
    return semua;
}

int hasil(int n,int parent=-1,int direction=-1){
    //Direction 1 is right and direction 0 is left
    if(parent==-1 && direction==-1){
        int total=0;
        for(int i=1;i<=n;i++){
            tanda[i]=true;
            int kiri = hasil(n,i,0);
            int kanan = hasil(n,i,1);
            tanda[i]=false;
            int c = kiri*kanan;
            total+=c;
        }
        return total;
    } else if(direction==0){
        int i=parent-1;
        if(tanda[i] || i==0){
            return 1;
        }
        int total=0;
        while(i>=1){
            if(tanda[i]){
                break;
            } else{
                tanda[i]=true;
                int kiri = hasil(n,i,0);
                int kanan = hasil(n,i,1);
                tanda[i]=false;
                int c= kiri*kanan;                    
                total+=c;
            }
            i--;
        }
        return total;
    } else if(direction==1){
        int i=parent+1;
        if(tanda[i]==true || i==n+1){
            return 1;
        }
        int total=0;
        while(i<=n){
            if(tanda[i]){
                break;
            } else{
                tanda[i]=true;
                int kiri = hasil(n,i,0);
                int kanan = hasil(n,i,1);
                tanda[i]=false;
                int c= kiri*kanan;
                //cout<<c<<endl;                    
                total+=c;
            }
            i++;
        }
        return total;
    }
}


int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        for(int i=0;i<=16;i++){
            tanda[i]=false;
        }
        cin>>n;
        cout<<hasil(n)<<endl;
        t--;
    }



}