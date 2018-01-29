//http://codeforces.com/problemset/problem/455/A
//Boredom
#include <bits/stdc++.h>
using namespace std;


typedef long long int gede;
vector<gede> tab(100001,0);
vector<gede> memo(100001,-1);
gede fungsinya(gede n){

    if (n==0) return 0;
    if (n==1) return tab[1];

    if(memo[n]!=-1){
        return memo[n];
    }
    memo[n] = max(fungsinya(n-1),fungsinya(n-2)+n*tab[n]);
    return  memo[n];



}


int main(){


    int n;
    cin>>n;
    int maxnya=0;

    for(int i=1;i<=n;i++){
        int temp ;
        cin>>temp;
        tab[temp]++;
        maxnya= max(maxnya,temp);
    }

    cout<<fungsinya(maxnya);

    cout<<endl;


}