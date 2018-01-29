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
string hasilcipher(string s,int k,int n){
    int panjang = n;
    string temp;
    for(int i=0;i<n;i++){
        if(isSymbol(s[i])){
            temp.push_back(s[i]);
        } else{
            if(isupper(s[i])){
                char urutanalphabet = s[i]-'A';
                urutanalphabet+=k;
                urutanalphabet%=26;
                urutanalphabet+='A';
                temp.push_back(urutanalphabet);
            } else{
                char urutanalphabet = s[i]-'a';
                urutanalphabet+=k;
                urutanalphabet%=26;
                urutanalphabet+='a';
                temp.push_back(urutanalphabet);
            }
        }
    }
    return temp;
}   

int main(){

    string s;
    int n;
    cin>>n;
    cin>>s;
    int k;
    cin>>k;
    cout<<hasilcipher(s,k,n)<<endl;
}