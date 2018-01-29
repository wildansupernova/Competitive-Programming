#include <bits/stdc++.h>

using namespace std;

void cek (vector<int> &a){
    for(int i=0;i<=10;i++){
        a.push_back(i);
    }
}
int main(){
    vector<int> ce;
    cek(ce);
    for(int i=0;i<ce.size();i++){
        cout<<ce[i]<<endl;
    }
}