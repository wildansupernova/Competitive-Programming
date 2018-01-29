#include <bits/stdc++.h>
using namespace std;


int abso(int temp){
    if (temp<0){
        return 0-temp;
    } 
    return temp;
}


int selisih(int a,int b){
    return abso(a-b);
}

void bangkitkan(vector<int> a,vector<int>simpanSeq, vector< vector<int> > *hasil){
    int panjang = simpanSeq.size();
    if(panjang==a.size()){
        (*hasil).push_back(simpanSeq);
    } else{
        for(int i=1;i<=a[panjang];i++){
            simpanSeq.push_back(i);
            bangkitkan(a,simpanSeq,hasil);
            simpanSeq.pop_back();
        }
    }

}
int CountSelisih(vector<int> tab){
    int panjang = tab.size();
    int sum=0;

    for(int i=1;i<panjang;i++){
        sum+=abso(tab[i]-tab[i-1]);
    }
    return sum;
}
void tampilkan(vector<int> b){
    int panjang = b.size() ;
    for(int i = 0;i<panjang;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
void bangkitkan2(vector<int> a,vector<int>simpanSeq, vector<int> *hasil ,int *max){
    int panjang = simpanSeq.size();
    if(panjang==a.size()){
        tampilkan(simpanSeq);
        int csel = CountSelisih(simpanSeq);
        if (csel>*max){
            *hasil = simpanSeq;
            *max = csel;
        }
    } else{
        //for(int i=1;i<=a[panjang];i++){
            simpanSeq.push_back(1);
            bangkitkan2(a,simpanSeq,hasil,max);
            simpanSeq.pop_back();
             simpanSeq.push_back(a[panjang]);
            bangkitkan2(a,simpanSeq,hasil,max);
            simpanSeq.pop_back();       
    }

}





int main(){
    int n;
    cin >>n;
    vector<int>tab;
    vector<int>seq;
    for(int i = 1; i<=n;i++){
        int temp;
        cin>>temp;
        tab.push_back(temp);
    }
    
    /*bangkitkan(tab,seq,&hsl);
    int panjang = hsl.size();
    /*for(int i=0;i<panjang;i++){
        tampilkan(hsl[i]);
    }
    int idx=-1 ,max=0;
    for(int i=0;i<panjang;i++){
        int temp = CountSelisih(hsl[i]);
        if (temp>max){
            idx = i;
            max = temp;
        }
    }*/
    vector< int > hsl;
    int max=0;
    bangkitkan2(tab,seq,&hsl,&max);

    cout<<"Hasil Paling BEsar"<<endl;
    cout<<"maxnya : "<<max<<endl;
    tampilkan(hsl);

    


}