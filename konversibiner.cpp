#include <bits/stdc++.h>

using namespace std;

//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/17/problems/70/
//Konversi Biner

string konversiBiner(int x){
    if(x==0){
        return "";
    } else{
        if(x%2==0){
            return  konversiBiner(x/2) + "0";
        } else{
            return konversiBiner(x/2) + "1";
        }
    }
}

string perantara(int x){
    if(x==0)
        return "0";
    else 
        return konversiBiner(x);

}


int main(){
    int x;
    cin>>x;
    cout<< perantara(x)<<endl;
}