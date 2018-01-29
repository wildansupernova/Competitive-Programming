//https://practice.geeksforgeeks.org/problems/find-the-median/0
//	Find the median




#include <bits/stdc++.h>
using namespace std;



int main(){

    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int> temp(n,0);
        for(int i =0;i<n;i++){
            cin>>temp[i];
        }

        sort(temp.begin(),temp.end());

        if(n%2==0){
            //Genap
            cout<<(temp[n/2]+temp[(n/2)-1])/2;
        } else{
            //Ganjil
            cout<<temp[n/2];
        }
        cout<<endl;
        
        t--;
    }

}