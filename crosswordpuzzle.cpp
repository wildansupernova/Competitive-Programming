//https://www.hackerrank.com/challenges/crossword-puzzle/problem
//crossword puzzle

#include <bits/stdc++.h>

using namespace std;

typedef vector<string> ls;

ls pisahkan(string s){
    ls temp;
    int panjang = s.length();
    int now=0;
    string tmp;
    for(int i=0;i<panjang;i++){
        if (s[i]==';'){
            temp.push_back(tmp);
            tmp.clear();
        } else{
            tmp.push_back(s[i]);
        }
    }
            temp.push_back(tmp);
            tmp.clear();
    return temp;
}


typedef struct minusnya{
    bool mendatar;//True jika mendatar, false jika menurun
    int colOrBrs;
    int a;
    int b;
} tempatMinus;
typedef vector<tempatMinus> ltm;
ltm scanDulu(ls tab){
    ltm temp;
    //Scan Mendatar
    for(int i=0;i<10;i++){
        int j=0;

        while(j<10){
            if(tab[i][j]=='-'){
                //Akuisi
                tempatMinus t;
                t.a = j;
                t.colOrBrs = i;
                

            }

        }
    }
}
int main(){


    ls tab;
    for(int i=1;i<=10;i++){
        string tmp;
        cin>>tmp;
        tab.push_back(tmp);
    }
    string s;
    cin>>s;
    ls terpisah;
    terpisah = pisahkan(s);    
}