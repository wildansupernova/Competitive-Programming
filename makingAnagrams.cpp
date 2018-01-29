#include <bits/stdc++.h>
using namespace std;



int main(){

    int a[26],b[26];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++){
        a[s1[i]-'a']++;
    }
    for(int i=0;i<s2.length();i++){
        b[s2[i]-'a']++;
    }
    int sum=0;
    for(int i=0;i<26;i++){
        if(a[i]>b[i]){
            sum+=a[i]-b[i];
        } else{
            if(a[i]<b[i]){
                sum+=b[i]-a[i];
            }
        }
    }    
    cout<<sum<<endl;
}