#include <bits/stdc++.h>
using namespace std;

int abso(int temp){
    if (temp<0){
        return 0-temp;
    } 
    return temp;
}

int selisih(int a,int b){
    return abso(a-b);
}

int maximm(vector<int> a,vector<int> simpanSeq,int x,int *memo){
    int len  = a.size();
    if (x<len-1){
        for(int i=1;i<=a[x];i++){
            simpanSeq.push_back(i);
            maximm(a,simpanSeq,x+1,memo);
            simpanSeq.pop_back();
        }
    } else{
        int panjang = simpanSeq.size();
        for(int i=0;i<panjang;i++){
            cout<<simpanSeq[i]<<" ";
        }
        cout<<endl;
    }

    
}




int main(){
    //vector<int> a;
    //generate(a,1);

    int n;
    cin>>n;
    vector<int> tab;
    vector<int> seq;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        tab.push_back(temp);

    }

    int memo[n];
    for(int i=0;i<n;i++){
        memo[i]=-1;
    }
    cout<<maximm(tab,seq,0,memo)<<endl<<"yiha";
    for(int i=0;i<n;i++){
        cout<< memo[i]<<" ";
    }
    cout<<endl;
    /*int t;
    cin>>t;
    int daftarsolusi[t];
    for(int i=0;i<t;i++){
        int n;
        cin >>n;
        
        vector<int> tab;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            tab.push_back(temp);
        }

    }

    for(int i=0;i<t;i++){
        cout<<daftarsolusi[i]<<endl;
    }*/
}