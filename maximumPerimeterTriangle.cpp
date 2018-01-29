#include <bits/stdc++.h>
using namespace std;
//https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
//Maximum Perimeter Triangle

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int max3(int a,int b,int    c){
    return max(a,max(b,c));
}
vector <int> maximumPerimeterTriangle(vector <int> l) {
    // Complete this function
    int size = l.size();
    sort(l.begin(),l.end());
    vector<int> temp;
    bool selesai=false;
    for(int i=size-1;i>=2 && !selesai;i--){
        for(int j=size-2;j>=1 && !selesai ;j--){
            for(int k=size-3;k>=0 && !selesai;k--){
                if((2*max3(l[i],l[j],l[k]))<l[i]+l[j]+l[k]){
                    temp.push_back(l[k]);
                    temp.push_back(l[j]);
                    temp.push_back(l[i]);
                    selesai=true;
                }
            }
        }
    }
    return temp;
}


int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for(int l_i = 0; l_i < n; l_i++){
       cin >> l[l_i];
    }
    vector <int> result = maximumPerimeterTriangle(l);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }

    if(result.size()==0){
        cout<<-1;
    }
    cout << endl;


    return 0;
}
