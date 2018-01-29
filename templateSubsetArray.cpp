#include <bits/stdc++.h>

using namespace std;

/*Template Untuk membuat subset dari segala kemungkinan dari array*/

bool isjmlsubsetsama(string s, int dimintaberapa){
    int count = 0 ;
    int panjang = s.length();
    for(int i=0;i<panjang;i++){
        if (s[i]=='1'){
            count++;
        }
    }
    return count==dimintaberapa;
}
void generateSubWithRestrict(vector<string> *a,string temp , int dimintaBerapaSubset, int panjang){
    int panjangtemp =  temp.length();
    if (panjangtemp == panjang){
        if (isjmlsubsetsama(temp,dimintaBerapaSubset)){
            (*a).push_back(temp);
        }
    } else{
        string temp0 = temp ,temp1 =temp;
        temp0.push_back('0');
        temp1.push_back('1');
        generateSub(a,temp0,dimintaBerapaSubset,panjang);
        generateSub(a,temp1,dimintaBerapaSubset,panjang);
    }
}

void generateSubAll(vector <string> *a , string temp , int panjang){
    int panjangtemp =  temp.length();
    if (panjangtemp == panjang){
    
            (*a).push_back(temp);
        
    } else{
        string temp0 = temp ,temp1 =temp;
        temp0.push_back('0');
        temp1.push_back('1');
        generateSub(a,temp0,panjang);
        generateSub(a,temp1,panjang);
    }
}
bool isSama(string kemungkinan, vector<int> arrtujuan, int angkatujuan){
    int panjang = kemungkinan.length();

    int times=1;
    for(int i=0;i<panjang;i++){
        if(kemungkinan[i]=='1'){
            times*=arrtujuan[i];

        }
    }

    return angkatujuan == times;
}


void printangka(string kemungkinan, vector<int> arrtujuan){
    for(int i=0;i<kemungkinan.length();i++){
        if(kemungkinan[i]=='1'){
            cout<< arrtujuan[i]<<" ";

        }

    }
    cout<<endl;

}
void printsamadengankali(vector<string> kemungkinan,vector<int> arrtujuan,int angkatujuan){
    int panjangangka = (kemungkinan[0]).length();
    int panjangkemungkinan = kemungkinan.size();

    for(int i=0;i<panjangkemungkinan;i++){
        if(isSama(kemungkinan[i],arrtujuan,angkatujuan)){
            printangka(kemungkinan[i],arrtujuan);
        }
    }

}


int main(){

}

