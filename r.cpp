//http://codeforces.com/problemset/problem/599/A
//Patrick and Shopping


#include <bits/stdc++.h>
using namespace std;

int min(int a,int b){
    if(a<=b){
        return a;
    }
    return b;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int jalan1=a+a+b+b,jalan2=a+c+b,jalan3=a+a+b+c+a;
    int jalan4= a+c+c+a;
    int jalan5=b+b+a+a;
    int jalan6=b+b+a+c+b;
    int jalan7=b+c+a;
    int jalan8=b+c+c+b;
    int minimum = min(jalan8,min(jalan7,min(jalan6,min(jalan5,min(jalan4,min(jalan3,min(jalan1,jalan2)))))));
    cout<<minimum;
    cout<<endl;


}