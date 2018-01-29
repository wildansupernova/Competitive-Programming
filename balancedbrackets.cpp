#include <bits/stdc++.h>
using namespace std;
//https://www.hackerrank.com/challenges/ctci-balanced-brackets/problem
//Stacks: Balanced Brackets
int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        vector<char> tab;
        tab.push_back('K');
        string s;
        cin>>s;
        //bool yes = true;
        for(int j=0;j<s.length();j++){

            if(s[j]=='(' || s[j]=='['|| s[j]=='{'){
                tab.push_back(s[j]);
            } else{
                if(s[j]==')'){
                    if(tab.back()=='('){
                        tab.pop_back();
                    } else{
                        tab.push_back(s[j]);
                    }
                }
                if(s[j]=='}'){
                    if(tab.back()=='{'){
                        tab.pop_back();
                    } else{
                        tab.push_back(s[j]);
                    }
                }
                if(s[j]==']'){
                    if(tab.back()=='['){
                        tab.pop_back();
                    } else{
                        tab.push_back(s[j]);
                    }
                }                
            }

            

        }
            if(tab.size() ==1){
                cout<<"YES";
            }else{
                cout<<"NO";
            }
            cout<<endl;
            tab.clear();
            

    }


}