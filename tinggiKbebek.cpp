#include <bits/stdc++.h>

using namespace std;

void sortBubble(int arr[],int n){

    for(long long i=0;i<n-1;i++){
        for(long long j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sortBubble(arr,n);
    /*for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } */   

    cout<<arr[k-1]<<endl;
}