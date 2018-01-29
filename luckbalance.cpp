//Luck Balance
//https://www.hackerrank.com/challenges/luck-balance/problem


#include <bits/stdc++.h>

using namespace std;


bool comparator(int a, int b){
    return a>b;
}

int luckBalance(int k, vector <int  > contests) {
    sort(contests.begin(),contests.end(),comparator);
    int total = 0;
    for(int i=0;i<contests.size();i++){
        if(i<k){
            total+=contests[i];
        } else{
            total-=contests[i];
        }
        
    }   
    
    return total;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> penting;
    int totalTdkPenting=0;
    for(int contests_i = 0;contests_i < n;contests_i++){
        int temp1,kepentingan;
        cin>>temp1>>kepentingan;
        if(kepentingan){
            penting.push_back(temp1);
        } else{
            totalTdkPenting+=temp1;
        }
    }
    int result = luckBalance(k, penting) + totalTdkPenting;
    cout << result << endl;
    return 0;
}
