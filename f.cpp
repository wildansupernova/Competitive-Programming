#include <bits/stdc++.h>
using namespace std;
//https://www.hackerrank.com/challenges/gridland-metro/problem
//Gridland Metro Problem


typedef struct tup{
    long long r,a,b;
} taple;


typedef struct rentangs{
    long long a,b;
} rentang;

typedef vector<rentang> rentangcollection;
bool cmpfunc(taple a,taple b){
    return a.r<b.r;
}
bool cmprentangmengecil(rentang a,rentang b){
    return a.a>b.a;
}

void overlapInterval(rentangcollection *a){
    sort((*a).begin(),(*a).end(),cmprentangmengecil);
    long long panjangawal = (*a).size();
    stack<rentang> temp;
    temp.push((*a).back());
    (*a).pop_back();
    for(long long i=1;i<panjangawal;i++){
        rentang top = temp.top();

        if (top.b<(*a).back().a){
            temp.push((*a).back());
        } else{
            if(top.b < (*a).back().b){
                top.b = (*a).back().b;
                temp.pop();
                temp.push(top);
            }
        }
        (*a).pop_back();
    }
    while(!temp.empty()){
        (*a).push_back(temp.top());
        temp.pop();
    }

}


long long totalPetakRentang(rentangcollection a){
    //IS sudah dilakukan pembenaran Overlapping

    long long sum=0,panjang = a.size();

    for(long long i = 0;i<panjang;i++){
        sum+=a[i].b-a[i].a+1;
    }
    return sum;
}
int main(){

    long long n,m,k;

    cin >>n>>m>>k;

    long long jumlahpetak = n*m;

    map<long long,rentangcollection> mep;
    map<long long,rentangcollection> ::iterator itr;
    for(long long i=1;i<=k;i++){
        rentang tempr;
        long long row;
        cin>>row>>tempr.a>>tempr.b;
        mep[row].push_back(tempr);
    }

    for(itr = mep.begin();itr != mep.end();itr++){
        long long kunci = itr ->first;
        rentangcollection koleksinya = itr ->second;
        overlapInterval(&koleksinya);
        jumlahpetak -= totalPetakRentang(koleksinya);

    }
    long long jumlahlamppost = jumlahpetak;
    cout<<jumlahlamppost<<endl;


    
}