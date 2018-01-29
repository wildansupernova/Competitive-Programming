
#include <bits/stdc++.h>

using namespace std;


bool isUpper (char a){
    return a>='A' && a<='Z';
}

bool isLower (char a){
    return a>='a' && a<='z';
}

bool isSpecialChar(char a){
    return !isUpper(a) && !isLower(a);
}

string decrypt(string encrypted_message) {

    int length = encrypted_message.length();
    string temp="";
    int  key[7] = {8,2,5,1,2,2,0};
    int keyNow = 0;
    for(int i=0;i<length;i++){
        if(isUpper(encrypted_message[i])){
            int num = encrypted_message[i] - 'A';
            num+=26;
            num-=key[keyNow];
            num%=26;
            keyNow++;
            keyNow%=7;            
            temp.push_back(num+'A');
        } else if(isLower(encrypted_message[i])) {
            int num = encrypted_message[i] - 'a';
            num+=26;
            num-=key[keyNow];
            num%=26;
            keyNow++;
            keyNow%=7;
            temp.push_back(num+'a');
        } else{
            temp.push_back(encrypted_message[i]);
        }

    }

    return temp;
}



int main(){
    string enc;
    getline(cin,enc);
    cout<<decrypt(enc)<<endl;

}



