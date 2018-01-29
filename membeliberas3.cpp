//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/16/problems/64/
//Membeli Beras



#include <bits/stdc++.h>

using namespace std;

typedef struct hrg{
    double perkilo;
    long long jumlahkilo;
} nilai;



bool compare(nilai a,nilai b){
    if(a.perkilo>=b.perkilo){
        return true;
    } else{
        return false;
    }
}



void sortBubble(vector<nilai> *ar){
    long long panjang =(*ar).size();


    for(long long i=0;i<panjang-1;i++){
        for(long long j=0;j<panjang-i-1;j++){
            if(((*ar)[j].perkilo/(*ar)[j].jumlahkilo)<((*ar)[j+1].perkilo/(*ar)[j+1].jumlahkilo)){
                nilai temp;
                temp.perkilo = (*ar)[j].perkilo;
                temp.jumlahkilo = (*ar)[j].jumlahkilo;
                (*ar)[j].perkilo = (*ar)[j+1].perkilo;
                (*ar)[j].jumlahkilo =(*ar)[j+1].jumlahkilo ;
                (*ar)[j+1].perkilo = temp.perkilo;
                (*ar)[j+1].jumlahkilo = temp.jumlahkilo;

            }
        }
    }
}
int main(){
    long long n,x;
    cin>>n>>x;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];

    }

    vector<nilai> tab;
    for(long long i=0;i<n;i++){
        nilai temp;
        double hrga;
        cin>>hrga;
        temp.jumlahkilo = arr[i];
        temp.perkilo = hrga;
        tab.push_back(temp);
    }
    long long i=0;
    double uang=0;
    //sort(tab.begin(),tab.end(),compare);
    sortBubble(&tab);
    while(x>0 && i<n){
        if(tab[i].jumlahkilo>x){
            uang+= (tab[i].perkilo/tab[i].jumlahkilo)*x;
            x=0;
        } else{
            uang+= tab[i].perkilo;
            x=x-tab[i].jumlahkilo;
        }

        
        i++;
    }
    printf("%.5f\n",uang);
}