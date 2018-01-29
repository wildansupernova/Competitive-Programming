//	Minimum Platforms
//https://practice.geeksforgeeks.org/problems/minimum-platforms/0

#include <bits/stdc++.h>

using namespace std;


void tambahin(int arr[], int a ,int b){
    for(int i=a;i<=b;i++){
        arr[i]++;
    }
}

int abso(int a){
    if(a<0)
        return a*(-1);
    return a;
}
int hasil(int n,vector<int> arri , vector<int> depart){

    sort(arri.begin(),arri.end());
    sort(depart.begin(),depart.end());
    /*for(int i=0;i<n;i++){
        cout<<arri[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<depart[i]<<" ";
    }*/
    int now=0;
    int nowmax=0;
    int i = 0;
    int j=0;
    int jumlah = n+n;
    while(jumlah){
        if(i<n && j<n){
            if(arri[i]<depart[j]){
                //cout<<now<<"sdfd";
                now++;
                i++;
                //cout<<now;
                if(abso(now)>nowmax){
                    nowmax=abso(now);
                }
            } else{
                now--;
                j++;
                if(abso(now)>nowmax){
                    nowmax=abso(now);
                }
            }
        } 
        jumlah--;
    }
    return nowmax;
    
}

int main(){

    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int> arrival;
        vector<int> depart;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arrival.push_back(temp);
        }
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(temp<arrival[i]){
                temp+=2400;
            }
            depart.push_back(temp);
        }
        cout<<hasil(n,arrival,depart)<<endl;
        t--;
    }

}

