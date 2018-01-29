//Expression
//http://codeforces.com/problemset/problem/479/A

#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}

int main(){
    int a,b,c;

    cin>>a>>b>>c;

    int jalan1= a*b*c;
    int jalan2 = (a*b)+c;
    int jalan3 = a*(b+c);
    int jalan4 = a+(b*c);
    int jalan5 = (a+b)*c;
    int jalan6 = a+b+c;

    cout<<max(jalan6,max(jalan5,max(jalan4,max(jalan3,max(jalan1,jalan2)))));
    cout<<endl;
}