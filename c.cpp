#include <bits/stdc++.h>

using namespace std;


bool comparestr(string s1, string s2){
    int panjang1 = s1.length(), panjang2 = s2.length();

    if (panjang1<panjang2){
        return true;
    } else if  (panjang1>panjang2){
        return false;
    } else{
            //cout<< s1<<":"<<s2<<":"<<panjang1<<":"<<panjang2<<endl;
        return (s1.compare(s2)<0);
    }

}
int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    // your code goes here
    sort(unsorted.begin(), unsorted.end(),comparestr);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cout<<unsorted[unsorted_i]<<endl;
    }
    return 0;
}
