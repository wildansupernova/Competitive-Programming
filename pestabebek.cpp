//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/16/problems/62/
//Pesta Bebek


#include <bits/stdc++.h>

using namespace std;

bool compare(string s1, string s2){
    int p1= s1.length();
    int p2= s2.length();
    if(s1==s2){
        return true;
    } else{
        if(p1>p2){
            for(int i =0;i<p2;i++){
                if(s1[i]>s2[i])
                    return false;
                else if(s1[i]<s2[i])
                    return true;               
            }
            return false;
        } else if(p1<p2){
            for(int i =0;i<p1;i++){
                if(s1[i]>s2[i])
                    return false;
                else if(s1[i]<s2[i])
                    return true;               
            }
            return true;            
        } else{
            for(int i =0;i<p1;i++){
                if(s1[i]>s2[i])
                    return false;
                else if(s1[i]<s2[i])
                    return true;               
            }            
        }
    }
    
}

int insertSort(vector<string> *arr,string masukan){
    //Mengeluarkan letak masukan setelah sort 
    (*arr).push_back(masukan);
    int n=(*arr).size();
    if(n==1){
        return 1;
    } else{
        bool selesai=false;
        while(n!=1 && !selesai){
            if(!compare((*arr)[n-2],(*arr)[n-1])){
                string temp;
                temp = (*arr)[n-2];
                (*arr)[n-2] = (*arr)[n-1];
                (*arr)[n-1] = temp;
                n--;
            } else{
                return n;
                selesai=true;
                break;
            }
        }
        return n;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<string> arr;
    vector<int> jawab;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        arr.push_back(temp);
    }

    vector<string> masuk;
    for(int i=0;i<arr.size();i++){
        int hasil = insertSort(&masuk,arr[i]);
        cout<<hasil<<endl;
    }

}
