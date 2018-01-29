//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/15/problems/57/
//Kupon Berhadiah

#include <bits/stdc++.h>

using namespace std;


int abso(int temp){
    if (temp<0){
        return 0-temp;
    } 
    return temp;
}



int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];

    for(int i=0;i<n;i++){
        int temp;
        cin>>arr[i];
    }
    int minnya = 1000000;
    int idx=0;

    for(int i=0;i<n;i++){
        int selisih = abso(arr[i]-x);
        if(selisih<minnya){
            idx=i;
            minnya = selisih;
        } else if(selisih==minnya){
            if(arr[i]<arr[idx]){
                idx=i;
            }
        }
    }

    cout<<arr[idx]<<endl;

}