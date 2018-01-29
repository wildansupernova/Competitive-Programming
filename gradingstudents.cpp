//Grading Students
//https://www.hackerrank.com/challenges/grading/problem


#include <bits/stdc++.h>
using namespace std;


int rounding(int c){
    int next5 =c+ 5-(c%5);
    if(next5-c <3){
        return next5;
    } else{
        return c;
    }
}

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp<38){
            cout<<temp<<endl;
        } else{
            cout<<rounding(temp)<<endl;
        }

    }
    
}