//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/16/problems/64/
//Membeli Beras



#include <bits/stdc++.h>

using namespace std;

typedef struct hrg{
    float perkilo;
    int jumlahkilo;
} nilai;



bool compare(nilai a,nilai b){
    if(a.perkilo>=b.perkilo){
        return true;
    } else{
        return false;
    }
}



void sortBubble(vector<nilai> *ar){
    int panjang =(*ar).size();


    for(int i=0;i<panjang-1;i++){
        for(int j=0;j<panjang-i-1;j++){
            if((*ar)[j].perkilo<(*ar)[j+1].perkilo){
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
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    vector<nilai> tab;
    for(int i=0;i<n;i++){
        nilai temp;
        float hrga;
        scanf("%f",&hrga);
        temp.jumlahkilo = arr[i];
        temp.perkilo = hrga/ arr[i];
        tab.push_back(temp);
    }
    int i=0;
    float uang=0;
    //sort(tab.begin(),tab.end(),compare);
    sortBubble(&tab);
    while(x>0 && i<n){
        if(tab[i].jumlahkilo>=x){
            uang+= x*tab[i].perkilo;
            x=0;
        } else{
            uang+= tab[i].perkilo*tab[i].jumlahkilo;
            x=x-tab[i].jumlahkilo;
        }

        
        i++;
    }
    printf("%.5f\n",uang);
}