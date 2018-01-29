#include <bits/stdc++.h>

using namespace std;



int main(){
    string s;
    cin>>s;
    int panjang = s.length();
    int count = 0;
    for(int i=0;i<=panjang-3;i=i+3){
        string temp;   
        temp.push_back(s[i]);
        temp.push_back(s[i+1]);
        temp.push_back(s[i+2]);

        if(temp!="SOS"){
            if (temp[0]!='S'){
                count++;
            }
            if (temp[1]!='O'){
                count++;
            }
            if (temp[2]!='S'){
                count++;
            }
        }
        temp.clear();
    }
    cout<<count<<endl;
}