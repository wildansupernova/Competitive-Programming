//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
//Letter Combinations of a Phone Number
#include <bits/stdc++.h>
using namespace std;

void rekursif(string digit,int idx,vector<string> mapping, vector<string> &hasil,string temp){
    if(idx!=0){
        int angka = digit[idx-1]-'0';
        string letter = mapping[angka];
        int n = letter.length();
        for(int i=0;i<n;i++){
            string pass = temp;
            pass.push_back(letter[i]);
            rekursif(digit,idx-1,mapping,hasil,pass);
        }
    } else{
        hasil.push_back(temp);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> hasil;
    string pass = digits;
    reverse(pass.begin(),pass.end());
    rekursif(pass,pass.length(),mapping,hasil,"");
    return hasil;
}

int main(){
    string temp;
    cin>>temp;
    vector<string> hasil = letterCombinations(temp);
    for(int i=0;i<hasil.size();i++){
        cout<<hasil[i]<<endl;
    }


}