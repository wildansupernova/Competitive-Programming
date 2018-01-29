//http://codeforces.com/problemset/problem/550/A
//Two Substring

#include <bits/stdc++.h>
using namespace std;



int main(){
    string s;
    cin>>s;

    int cari1;
    int cari2;
    cari1 = s.find("BA");
    cari2 = s.find("AB");
      int panjang = s.length();
    if( (cari1==string::npos )|| (cari2==string::npos) || panjang<4){
        cout<<"NO"<<endl;
    } else{

            bool ada1=false;
            for(int i=0;i<panjang-1;i++){
                char window1 = s[i];
                char window2 = s[i+1];
                if(window2=='B' && window1=='A'){
                    if(i>cari1+1){
                        ada1=true;
                        break;
                    }
                }
            }
      
            bool ada2=false;
            for(int i=0;i<panjang-1;i++){
                char window1 = s[i];
                char window2 = s[i+1];
                if(window2=='A' && window1=='B'){
                    if(i>cari2+1){
                        ada2=true;
                        break;
                    }
                }
            }           
            if(ada1|| ada2){
                cout<<"YES";
            } else {cout<<"NO";}
            cout<<endl;
    }

}