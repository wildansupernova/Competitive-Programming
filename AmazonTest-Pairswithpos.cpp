//https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values/0
	
//Pairs with Positive Negative values

#include <bits/stdc++.h>

using namespace std;

int abso(int a){
    if(a<0){
        return 0-a;
    }
    return a;
}

bool compare(int a, int b){
    if(abso(a)<abso(b)){
        return true;
    } else{
        return false;
    }
}
int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> tab;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            tab.push_back(temp);

        }
        sort(tab.begin(), tab.end(),compare);
        int counter=0;
        for(int i=0;i<n-1;i++){
            if(abso(tab[i])==abso(tab[i+1])){
                if(tab[i]<0 &&tab[i+1]>=0){
                    cout<<tab[i]<<" "<<tab[i+1]<<" ";
                    counter++;
                } else if (tab[i]>=0 &&tab[i+1]<0){
                    cout<<tab[i+1]<<" "<<tab[i]<<" ";
                    counter++;
                }
            }
            
        }

        if(counter==0){
            cout<<0;
        }

        cout<<endl;

    }

}