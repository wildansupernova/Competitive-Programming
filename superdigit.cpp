#include <bits/stdc++.h>

using namespace std;

string digitToString(int n){
    string y;
    if(n==0){
        return "0";
    } else{
        while(n>0){
            y.push_back(n%10+'0');
            n/=10;
        }

    }

    reverse(y.begin(),y.end());
    return y;
}

int superDigit(string n) {
    // Complete this function
    int pjg = n.length();
    if(pjg==1){
        return n[0]-'0';
    } else{
        int sum=0;
        for(int i =0;i<pjg;i++){
            sum+=n[i]-'0';
        }
        return superDigit(digitToString(sum));
    }


}

int main() {
    string n;
    int k;
    cin >> n >> k;
    string temp="";
    for(int i=1;i<=k;i++){
        temp+=n;
    }
    //cout<<n<<endl;
    int result = superDigit(temp);
    cout << result << endl;
    return 0;
}
