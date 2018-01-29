//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/16/problems/63/
//Kualitas Baju

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> arr;
    cin >>n;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());
    int panjang = arr.size();

    if(panjang % 2 ==1){
        //Jika Ganjil
        float hasil = (float) arr[panjang/2];
        printf("%.1f\n",hasil);
    } else{
        //Jika genap
        float pembagi =2;
        float hasil = (arr[(panjang/2)-1]+arr[(panjang/2)])/pembagi;
        printf("%.1f\n",hasil);
    }

    

}