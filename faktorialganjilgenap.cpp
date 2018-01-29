//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/17/problems/67/
//Faktorial Ganjil-Genap

#include <bits/stdc++.h>

using namespace std;

int f(int x){
    if(x%2==0){
        return x/2;
    }
    return x;
}

int fakGjGn(int x){
    if(x==1){
        return 1;
    } else{
        return f(x)*fakGjGn(x-1);
    }
}
int main(){
    int x;
    cin>>x;
    cout<<fakGjGn(x)<<endl;
}

