#include <bits/stdc++.h>
using namespace std;

//http://codeforces.com/problemset/problem/556/A
//Case of the Zeros and Ones
int main(){
    stack<int> hasil;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        int temp= s[i]-'0';
        if(hasil.empty()){
            hasil.push(temp);
        }   else{
            if ( (temp==0 && hasil.top() == 1) ||(temp==1 && hasil.top() == 0)){
                hasil.pop();
            } else{
                hasil.push(temp);
            }


        }
    }
    cout<<hasil.size()<<endl;    
}