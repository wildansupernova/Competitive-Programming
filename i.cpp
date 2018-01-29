#include <bits/stdc++.h>

//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/14/problems/54/
//Operasi String
using namespace std;



int main(){
    string s1,s2,s3,s4;
    int p1,p2,p3,p4;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    cin>>s4;
    p1=s1.length();
    p2=s2.length();
    p3=s3.length();
    p4=s4.length();
    int cari = s1.find(s2);
    s1.erase(cari,p2);
    string baru = "";
    cari = s1.find(s3);
    baru = s1.substr(0,cari+p3)+s4+s1.substr(cari+p3);
    cout<<baru<<endl;
    //cout<<s1<<endl;

}