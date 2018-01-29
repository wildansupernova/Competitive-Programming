//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/18/problems/75/
//Quadtree I: Pengodean
#include <bits/stdc++.h>
using namespace std;

int tab[129][129];

int maxnya(int a, int b){
    if(a>=b)
        return a;
    return b;
}

int dekati(int a){
    int awal=1;
    while(awal<a){
        awal*=2;
    }
    return awal;
}
int validkan(int r, int c){
    int didekati = maxnya(r,c);
    int hasildekati = dekati(didekati);
    return hasildekati;
}
void kodekan(string s,int x,int y,int sisi,vector<string> *listkode){
    bool isNolSemua = true;
    bool isSatuSemua = true;
    for(int i=x;i<sisi+x;i++){
        for(int j=y;j<sisi+y;j++){
            if(tab[i][j]==1){
                isNolSemua= false;
            } else{
                isSatuSemua = false;
            }
        }
    }
    if(isNolSemua){
        //cout<<"0"<<s<<endl;
    } else if(isSatuSemua){
        //cout<<"1"<<s<<endl;
        (*listkode).push_back("1"+s);
    } else{
        int bagidua = sisi/2;
        //Kuadaran 0
        kodekan(s+"0",x,y,bagidua,listkode);
        //Kuadaran 1
        kodekan(s+"1",x,y+bagidua,bagidua,listkode);
        //Kuadaran 2
        kodekan(s+"2",x+bagidua,y,bagidua,listkode);
        //Kuadaran 3
        kodekan(s+"3",x+bagidua,y+bagidua,bagidua,listkode);
    }
}
int main(){
    //Inisiasi
    for(int i=0;i<=128;i++){  
        for(int j=0;j<=128;j++){
            tab[i][j]=0;
        }
    }
    int r,c;

    cin>>r>>c;

    //Divalidkan dulu hasilnya
    int sisi = validkan(r,c);
    bool isNolSemua = true;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>tab[i][j];
            if(tab[i][j]==1)
                isNolSemua = false;
        }
    }


    vector<string> tab;
    kodekan("",1,1,sisi,&tab);
    int n = tab.size();
    cout<<n<<endl;
    if(n!=0){
        for(int i=0;i<n;i++){
            cout<<tab[i]<<endl;
        }
    }

    



}