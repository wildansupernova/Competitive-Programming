#include <bits/stdc++.h>

using namespace std;

bool compare(string s1, string s2){
    int p1= s1.length();
    int p2= s2.length();

    if(p1<p2){
        return true;
    } else if(p1>p2){
        return false;
    } else{

        for(int i=0;i<p1;i++){
            if(s1[i]>s2[i])
                return false;
            else if(s1[i]<s2[i])
                return true;
        }
        return true;


    }
    
}

int main(){

    int n;
    cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),compare);
    for(int i =0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}