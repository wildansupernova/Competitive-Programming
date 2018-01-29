//https://www.hackerrank.com/challenges/pangrams/problem
//Pangrams
#include <bits/stdc++.h>

using namespace std;
bool islower(char a){
    if(a>='a' && a<='z'){
        return true;
    } else{
        return false;
    }
}
bool isupper(char a){
    if(a>='A' && a<='Z'){
        return true;
    } else{
        return false;
    }
}
bool isSymbol(char a ){
    if(isupper(a)||islower(a)){
        return false;
    } else{
        return true;
    }
}

int main(){
    string s;
    getline(cin,s);
    int panjang = s.length();
    bool memo[26];
    memset(memo,false,sizeof(memo));
    for(int i=0;i<panjang;i++){
        if(!isSymbol(s[i])){
            int karakter;
            if(isupper(s[i])){
                karakter = s[i]-'A';
            } else{
                karakter = s[i]-'a';
            }
            memo[karakter] = true;
        }
    }

    //cek apakah semuany true;

    bool yasemua=true;
    for(int i=0;i<26;i++){
        if(!memo[i]){
            yasemua=false;
            break;
        }
    }

    if(yasemua){
        cout<<"pangram";
    } else{
        cout<<"not pangram";
    }
    cout<<endl;
}