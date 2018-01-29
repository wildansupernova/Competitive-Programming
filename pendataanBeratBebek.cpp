//Pendataan Berat Bebek
//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/15/problems/60/


#include <bits/stdc++.h>

using namespace std;
int depan(int arr[], int atas , int bawah , int x){
    if (bawah>=atas){
        int mid = (atas+bawah)/2;

        if(mid==0 && arr[mid]>x)
            return mid;
        if(arr[mid]>x && arr[mid-1]<=x)
            return mid;
        if(arr[mid]<=x)
            return depan(arr,mid+1,bawah,x);
        else   
            return depan(arr,atas,mid-1,x);
    }
    return -1;
}


int belakang(int arr[], int atas , int bawah , int y,int n){
    if (bawah>=atas){
        int mid = (atas+bawah)/2;

        if(mid==n-1 && arr[mid]<=y)
            return mid;
        if(arr[mid]<=y && arr[mid+1]>y)
            return mid;
        if(arr[mid]>y)
            return belakang(arr,atas,mid-1,y,n);
        else    
            return belakang(arr,mid+1,bawah,y,n);
    }
    return -1;
}
int hasilCari(int arr[],int n,int x,int y){
    int awal = depan(arr,0,n-1,x);
    if(awal==-1)
        return 0;
    int akhir = belakang(arr,0,n-1,y,n);

    if(akhir==-1)
        return 0;
    
    return akhir-awal+1;
}



int  main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    //cout<<belakang(arr,0,n-1,6,n)<<endl;
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",hasilCari(arr,n,x,y));
    }



}