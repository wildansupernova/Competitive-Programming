#include <bits/stdc++.h>
using namespace std;

int abso(int temp){
    if (temp<0){
        return 0-temp;
    } 
    return temp;
}

int main(){


    

    int t;
    cin>>t;
    int daftarsolusi[t];
    for(int i=0;i<t;i++){
        int n;
        cin >>n;
        int sumganjil=0,sumgenap=0;
        int tab[n];
        
        for(int j=0;j<n;j++){
            cin>>tab[j];
        }
        for(int j=1;j<n;j++){
            if (j%2==0){
                sumganjil+=abso(1-tab[j-1]);
                sumgenap+=abso(tab[j]-1);
            } else{
                sumgenap+=abso(1-tab[j-1]);
                sumganjil+=abso(tab[j]-1);
            }
        }
        cout<<sumgenap<<" "<<sumganjil<<endl;
        if (sumgenap>=sumganjil){
            daftarsolusi[i]= sumgenap;
        } else{ 
            daftarsolusi[i]= sumganjil;
        }
    }

    for(int i=0;i<t;i++){
        cout<<daftarsolusi[i]<<endl;
    }
}