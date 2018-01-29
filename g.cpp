#include <bits/stdc++.h>
using namespace std;


//Equal
//https://www.hackerrank.com/challenges/equal/problem
void tambahdenganXEx1(vector<int> *tab , int x , int nth ){
    //IS tambah semua dengan x kecuali satu elemen nth, nthnya dari 0
    if (x!=0){
        int panjang = (*tab).size();
            for(int i=0;i<panjang;i++){
                if (i!=nth){
                    (*tab)[i]+=x;
                }
            }
    }
    
}
bool isallsame(vector<int> *tab){
    bool same =true;

    int panjang =(*tab).size();
    int skrg = (*tab)[0];
    for(int i = 0 ;i<panjang;i++){
        if((*tab)[i]!=skrg){
            same =false;
        }
    }
    return same;
}

int countStep(int selisih){
    int sum=0;
    int temp = selisih;

    sum += temp/5;
    temp-= (temp/5)*5;
    sum += temp/2;
    temp-= (temp/2)*2;
    sum += temp/1;
    temp-= (temp/1)*1;    
    return sum;
}
int abso(int c){
    if (c<0){
        c=0-c;
    }
    return c;
}
int main(){

    vector<int> daftarsolusi;
    int k;
    cin >>k;
    int memoSelisih[1500];
    memset(memoSelisih,-1,sizeof(memoSelisih));
    for(int i=1;i<=k;i++){
            int n;
            int min =100000000;
            vector<int> tab;
            cin>>n;
            for(int i =1;i<=n;i++){
                int temp;
                cin>>temp;
                tab.push_back(temp);
                if (temp<min){
                    min =temp;
                }
            }
            int counts=0;
            ////Memproses Nya disini
            //daftar
            int collecCount[5];
            int panjang = tab.size();
            for(int i=0;i<5;i++){
                int tempC=0;
                for(int j=0;j<panjang;j++){
                    tempC+=countStep(tab[j]-(min-i));
                }   
                collecCount[i] = tempC;
            }
            
            int minimum = collecCount[0];
            for(int i=0;i<5;i++){
                if (collecCount[i]<minimum){
                    minimum= collecCount[i];
                }
            }
            counts= minimum;
            ///////////////

            daftarsolusi.push_back(counts);
            tab.clear();
    }

    for(int i=0;i<daftarsolusi.size();i++){
        cout<<daftarsolusi[i]<<endl;
    }


    
    

}




/*

int main(){
int main(){

    vector<int> daftarsolusi;
    int k;
    cin >>k;
    for(int i=1;i<=k;i++){
            int n;
            vector<int> tab;
            cin>>n;
            for(int i =1;i<=n;i++){
                int temp;
                cin>>temp;
                tab.push_back(temp);

            }

            sort(tab.begin(),tab.end());
            int count=0;
            int panjang = tab.size();
            vector<int> ::iterator upper;
            int batas = tab[0];
                count +=batas / 5;
                batas -= (batas/5) *5;
                count +=batas / 2;
                batas -= (batas/2) *2;       
                count +=batas / 1;
             batas = tab[0];
            tambahdenganXEx1(&tab,batas,0);
            int countt=0;
            upper = upper_bound(tab.begin(),tab.end(),batas);
            while(upper!=tab.end() ){
                int indeks = upper - tab.begin();
                int valbef=   tab[indeks -1];
                //cout<<indeks;
                int rentang = tab[indeks]-valbef;
                int rentangtemp = rentang;
                count +=rentangtemp / 5;
                rentangtemp -= (rentangtemp/5) *5;
                count +=rentangtemp / 2;
                rentangtemp -= (rentangtemp/2) *2;       
                count +=rentangtemp / 1;
                rentangtemp -= (rentangtemp/1) *1;
                tambahdenganXEx1(&tab,rentang,indeks);
                batas = tab[indeks];
                upper = upper_bound(tab.begin(),tab.end(),batas);
                //countt++;
            }
            daftarsolusi.push_back(count);
            tab.clear();
    }


    for(int i = 0;i<daftarsolusi.size();i++){
        cout<<daftarsolusi[i]<<endl;
    }


    

}
*/