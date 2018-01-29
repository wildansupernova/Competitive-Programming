//http://codeforces.com/contest/914/problem/A
//Perfect Squares


#include <bits/stdc++.h>
using namespace std;

int main(){
    

    int n;
    cin>>n;
    int hasil=INT_MIN;
    vector<bool> temp(1000000+1,false);
    for(int i=0;i<=1000;i++){
        temp[i*i]=true;
    }
    while(n){
        int c;
        cin>>c;
        if(c>=0){
            if(!temp[c]){
                if(c>hasil){
                    hasil=c;
                }
            }
        } else{
            if(c>hasil){
                hasil =c;
            }
        }
        n--;
    }

    cout<<hasil<<endl;
}