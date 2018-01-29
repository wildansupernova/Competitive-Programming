
#include <bits/stdc++.h>

using namespace std;


int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++){
        if(s2[i]<s1[i]){
            cout<<s2[i]-'a'+'z'-s1[i]<<" ";
        } else{
            cout<<s2[i]-s1[i]<<" ";
        }
    }

    cout<<endl;
}