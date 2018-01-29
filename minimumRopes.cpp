//	Minimum Cost of ropes
#include <bits/stdc++.h>

using namespace std;



bool comparee(int a,int b){
    if(a>b){
        return true;
    }

    return false;
}


int hasil(vector<int> yeah){
    sort(yeah.begin(),yeah.end(),comparee);
    int total = 0;
    while(yeah.size()!=1){
        int a = yeah.back();
        yeah.pop_back();
        int b = yeah.back();
        yeah.pop_back();
        int has = a+b;
        total+=has;
        yeah.push_back(has);
        sort(yeah.begin(),yeah.end(),comparee);

    }
    return total;
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int> temp;

        for(int i=0;i<n;i++){
            int tem;
            cin>>tem;
            temp.push_back(tem);
        }
        cout<<hasil(temp)<<endl;
        

        t--;
    }
}



