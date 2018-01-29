#include <bits/stdc++.h>
using namespace std;
//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/14/problems/56/
//Gaya Penulisan Variabel

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



int main(){
    string s1;
    cin >>s1;
    int panjang = s1.length();
    string temp;
    temp.push_back(s1[0]);
    for(int i = 1;i<panjang;i++){
        if(s1[i]=='_'){
            i++;
            temp.push_back(upper(s1[i]));
        } else if (!islower(s1[i])){
            temp.push_back('_');
            temp.push_back(lower(s1[i]));
            
        } else{
            temp.push_back(s1[i]);
        }
    }
    cout<<temp<<endl;

}