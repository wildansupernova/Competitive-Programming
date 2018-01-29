#include <bits/stdc++.h>
//https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
//Hackerland Radio Transmitters
using namespace std;

void tandain( map <int , bool> *m,int k, int key){
    int rangeatas = key+k;
    int rangebawah = key-k;
    for(int i = rangebawah;i<=rangeatas;i++){
        (*m)[i] =true;
    }
}

int main(){
    int n,k;
    vector <int> v;


    cin >> n>>k;

    for(int i = 1;i<=n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    map <int , bool> m;
    for(int i=0;i<v.size();i++){
        m[v[i]] = false;
    }
    int max = v[v.size()-1];
    int min  = v[0];
    int counter=0;
    int i = 0;
    while( i<= max){
        if (m.find(i)!=m.end()){
            if (!m[i]){
                int seharusnya =  i+k;
                bool ketemu=false;
                while(!ketemu){
                    if(m.find(seharusnya)!=m.end()){
                        tandain(&m,k,seharusnya);
                        counter++;
                        ketemu=true;
                    }
                    seharusnya--;
                }
            }
        }
        i++;
    }
    cout<<counter<<endl;

}
