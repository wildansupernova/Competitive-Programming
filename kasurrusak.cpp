//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/17/problems/69/
//Kasur Rusak

#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(string s, int low, int high){

    if(s.length()==1)
        return true;
    if(high<low){
        return true; 
    }

    if(s[low]!=s[high])
        return false;
    
    if(s[low]==s[high])
        return isPalindrome(s,low+1,high-1);

}


int main(){

    string s;
    cin>>s;
    if(isPalindrome(s,0,s.length()-1)){
        cout<<"YA"<<endl;
    } else{
        cout<<"BUKAN"<<endl;
    }
    
}