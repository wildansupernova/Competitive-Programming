#include <bits/stdc++.h>

using namespace std;

int candies(int n, vector <int> arr) {
    // Complete this function
    int panjang = arr.size();
    vector <int> tab (panjang,1);

    //Move Forward
    for(int i=0;i<panjang-1;i++){
        if(arr[i+1]>arr[i]){
            tab[i+1]=tab[i]+1;
        } 
    }
    int sum=0;
    /*for(int i=0;i<panjang;i++){
        //cout<<tab[i]<<" ";
        //sum+=tab[i-1]+1;
    }
    cout<<endl;*/
    //Move Backward

    for(int i=panjang-1;i>0;i--){
        if(arr[i-1]>arr[i]){
            if (tab[i-1]==tab[i]){
                tab[i-1]=tab[i]+1;
            }
            
        } 
    }
    sum=0;
    for(int i=0;i<panjang;i++){
        //cout<<tab[i]<<" ";
        sum+=tab[i];
    }
    //cout<<endl;
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = candies(n, arr);
    cout << result << endl;
    return 0;
}
