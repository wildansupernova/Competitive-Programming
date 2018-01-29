//https://practice.geeksforgeeks.org/problems/convert-to-roman-no/1
//Type : Fucntion problems
//Convert to Roman No

#include <bits/stdc++.h>
using namespace std;

void convertToRoman(int n) 
{
    map <char,int> mep;
    mep['I']=1;
    mep['V']=5;
    mep['X']=10;
    mep['L']=50;
    mep['C']=100;
    mep['D']=500;
    mep['M']=1000;
    if(n>=1000){
        int bagi = n/1000;
        for(int i=1;i<=bagi;i++){
            cout<<"M";
        }
        n=n%1000;
    }

    if(n>=900){
        cout<<"CM";
        n=n%900;
    }
    if(n>=600){
        cout<<"D";
        n-=500;
        int bagi = n/100;
        for(int i=1;i<=bagi;i++){
            cout<<"C";
        }
        n=n%100;
    }
    if(n>=500){
        cout<<"D";
        n-=500;
    }
    if(n>=400){
        cout<<"CD";
        n=n%400;
    }
    if(n>=100){
        int bagi = n/100;
        for(int i=1;i<=bagi;i++){
            cout<<"C";
        }
        n=n%100;
    }
    if(n>=90){
        n-=90;
        cout<<"XC";
    }
    if(n>=60){
        cout<<"L";
        n-=50;
        int bagi = n/10;
        n=n%10;
        for(int i=1;i<=bagi;i++){
            cout<<"X";
        }
    }
    if(n>=50){
        cout<<"L";
        n-=50;
    }
    if(n>=40){
        cout<<"XL";
        n-=40;
    }
    if(n>=10){
        int bagi=n/10;
        n=n%10;
        for(int i=1;i<=bagi;i++){
            cout<<"X";
        }
    }
    if(n==9){
        cout<<"IX";
    }
    if(n==8){
        cout<<"VIII";
    }
    if(n==7){
        cout<<"VII";
    }
    if(n==6){
        cout<<"VI";
    }
    if(n==5){
        cout<<"V";
    }
    if(n==4){
        cout<<"IV";
    }
    if(n==3){
        cout<<"III";
    }
    if(n==2){
        cout<<"II";
    }
    if(n==1){
        cout<<"I";
    }
}



int main(){
    int n;
    cin>>n;
    convertToRoman(n);
    cout<<endl;
}