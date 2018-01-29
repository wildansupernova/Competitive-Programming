//http://codeforces.com/problemset/problem/492/B
//B. Vanya and Lanterns

#include <bits/stdc++.h>

using namespace std;

double max (double a, double b){
    if(a>b)
        return a;
    return b;    
}


int main(){


    int n,l;
    cin>>n>>l;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    double selisih = -1;
    for(int i=0;i<n-1;i++){
        if(i==0){
            if(arr[i]!=0){
                double hasil = arr[i]-0;
                selisih = hasil;
            }

        } 
        if(i==n-2){
            if(arr[i+1]!=l){
                double hasil = l-arr[i+1];
                if(hasil>selisih){
                    selisih=hasil;
                }

            }

        }
            double bagi=2;
            double hasil = (arr[i+1]-arr[i])/bagi;
            if(hasil>selisih){
                selisih= hasil;
            }
        
    }

    if(n==1){
        selisih= max(arr[0]-0,l-arr[0]);
    }
    printf("%.10f\n",selisih);
}