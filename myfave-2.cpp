#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int min=10000000;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i]%11 == 0 ){
            if(A[i]<min){
                min=A[i];
            }
        }
    }
    return min;
}

int solution1(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int counter1=0;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i]==0){
            counter1++;
        }
    }
    int counter0=0;

    for(int i=0;i<n;i++){
        if(A[i]==1){
            counter0++;
        }
    }

    if(counter0<=counter1)
        return counter0;
    else 
        return counter1;
}

int main(){

}