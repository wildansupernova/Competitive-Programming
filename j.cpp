#include <bits/stdc++.h>

//Bahasa Dengklek
//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/14/problems/55/
using namespace std;

char upper(char inp){
    //Is kondisinya kecil
    return inp-'a'+'A';
}
char lower(char inp){
    //Is kondisinya kecil
    return inp-'A'+'a';
}

bool islower(char a){
    if (a>='a' && a<='z')
        return true;
    else{
        return false;
    }
}
string chgCase(string inp){
    int panjang = inp.length();
    string temp;
    for(int i=0;i<panjang;i++){
        if (islower(inp[i])){
            temp.push_back(upper(inp[i]));
        } else{
            temp.push_back(lower(inp[i]));
        }
    }
    return temp;
}
int main(){
    string s;

    cin>>s;
    cout<<chgCase(s)<<endl;
}