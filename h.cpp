#include <bits/stdc++.h>

using namespace std;


long long abso(long long x){
    if (x<0){
        return 0-x;
    }
    return x;
}

long long minimumAbsoluteDifference(long long n, vector <long long> arr) {
    long long min=3000000000;
    sort(arr.begin(),arr.end());
    
    for(long long i =0;i<n-1;i++){
        if(arr[i+1]-arr[i]<min){
            min= arr[i+1]-arr[i];
        }
    }

    return min;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for(long long arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long long result = minimumAbsoluteDifference(n, arr);
    cout << result << endl;
    return 0;
}
