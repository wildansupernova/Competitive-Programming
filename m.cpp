#include <bits/stdc++.h>

//https://www.hackerrank.com/challenges/grid-challenge/problem
//Grid Challenge


using namespace std;

bool isCanSorted(vector<string> tab){
    int panjang = tab.size();
    
    //Lakukan SOrting terlebih dahulu terhadap setiap elemen colom
    for(int i=0;i<panjang;i++){
        sort(tab[i].begin(),tab[i].end());
    }
    /*for(int i=0;i<panjang;i++){
        cout<<tab[i]<<endl;
    } */   
    //Cek bisa sorted barisnya
    bool bisa =true;
    
    for(int j=0;j<panjang;j++){
        char cek = (tab[0])[j];
        for(int i=0;i<panjang;i++){
            if ((tab[i])[j]<cek){
                bisa=false;
                break;
            } else{
                cek = (tab[i])[j];
            }
        }
    }

    return bisa;
}

int main(){
    int t;
    cin >>t;
    bool daftarsolusi[t];
    
    for(int i=0;i<t;i++){
        int n;
        cin >>n;
        vector<string> tab;
        for(int j=0;j<n;j++){
            string temp;
            cin>>temp;
            tab.push_back(temp);
        }
        daftarsolusi[i] = isCanSorted(tab);

        tab.clear();


    }


    for(int i=0;i<t;i++){
        if (daftarsolusi[i]){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
}