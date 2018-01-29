//https://practice.geeksforgeeks.org/problems/meta-strings/0/?ref=self
//Meta Strings
#include <bits/stdc++.h>

using namespace std;


bool isMeta(string s1, string s2){
    int p1 = s1.length();
    int p2 = s2.length();
    if(p1!=p2){
        return false;
    } else if(p1==1 || p2 ==1){
        return false;
    } else{
        int count = 0;
        int pertama,kedua;
        for(int i=0;i<p1;i++){
            if(s1[i]!=s2[i]){
                if(count==0){
                    count++;
                    pertama = i;
                } else if(count==1){
                    count++;
                    kedua = i;
                } else{
                    count++;
                    break;
                }
            }
        }
        if(count!=2){
            return false;
        } else{
            if(s1[pertama]==s2[kedua] && s1[kedua]==s2[pertama]){
                return true;
            } else{

                return false;
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t){
        string s1,s2;
        cin>>s1>>s2;

        cout<<isMeta(s1,s2)<<endl;

        t--;
    }
}