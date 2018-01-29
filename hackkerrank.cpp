#include <bits/stdc++.h>

using namespace std;

bool isContainHackerrank(string s){
    vector<char> b;
    char temp[10] = {'h', 'a', 'c', 'k', 'e', 'r', 'r', 'a', 'n', 'k'};
    int now = 0;
    int counthack=0;
    int panjang = s.length();
    for(int i = 0 ;i<panjang;i++){
        if (temp[now]==s[i]){
            counthack++;
            now++;
        }
    }

    if(counthack==10){
        return true;
    } else{
        return false;
    }
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // your code goes here
        if(isContainHackerrank(s)){
            cout<<"YES";
        } else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}
