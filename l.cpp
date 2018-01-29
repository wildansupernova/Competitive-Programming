//https://www.hackerrank.com/challenges/marcs-cakewalk/problem
//Marc's Cakewalk

#include <bits/stdc++.h>

using namespace std;
bool comparatordec(long  a,long  b){
    return a>b;
}
long power(long  x, long y)
{
    long long temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);       
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
long rumus(long j , long cal){
    return power(2,j)*cal;
}
int  main(){
    long n;
    cin >> n;
    vector<long> calories(n);
    for(long calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    sort(calories.begin(),calories.end(),comparatordec);
    long sum=0;
    int panjang = calories.size();
    for(int i = 0;i<panjang;i++){  
        sum+=rumus(i,calories[i]);
    }

    cout<<sum<<endl;
    // your code goes here
    return 0;
}
