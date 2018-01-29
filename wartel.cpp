//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/15/problems/59/
//Wartel


#include <bits/stdc++.h>

using namespace std;



int main(){


    int n,q;
    cin>>n>>q;
    map<string,string> tab;
    for(int i=0;i<n;i++){
        string s;
        string nomor;
        cin>>s>>nomor;

        tab[s] = nomor;
    }

    for(int i=0;i<q;i++){
        string nama;
        cin>>nama;
        map<string,string>::iterator itr;
        itr = tab.find(nama);
        if(itr==tab.end()){
            cout<<"NIHIL"<<endl;
        } else{
            cout<<itr->second<<endl;
        }
    }

}