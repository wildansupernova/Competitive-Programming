
#include <bits/stdc++.h>

using namespace std;

int chrToInt(char a){
    return a-'0';
}

char intToChr(int a){
    return '0'+a;
}
vector<char> maximumNumber(int m, int n,  int s){
    //angka 9
    vector<char> temp;
    int idx = s/9;

    for(int i=1;i<=idx;i++){
        temp.push_back('9');
    }
    s=s%9;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 8
    idx= s/8;
    for(int i=1;i<=idx;i++){
        temp.push_back('8');
    }
    s=s%8;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 7
    idx= s/7;
    for(int i=1;i<=idx;i++){
        temp.push_back('7');
    }
    s=s%7;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 6
    idx= s/6;
    for(int i=1;i<=idx;i++){
        temp.push_back('6');
    }
    s=s%6;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 5
    idx= s/5;
    for(int i=1;i<=idx;i++){
        temp.push_back('5');
    }
    s=s%5;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 8
    idx= s/4;
    for(int i=1;i<=idx;i++){
        temp.push_back('4');
    }
    s=s%4;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 8
    idx= s/3;
    for(int i=1;i<=idx;i++){
        temp.push_back('3');
    }
    s=s%3;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 8
    idx= s/2;
    for(int i=1;i<=idx;i++){
        temp.push_back('2');
    }
    s=s%2;
    if(temp.size()==m && s==0){
        return temp;
    }
    //angka 8
    idx= s/1;
    for(int i=1;i<=idx;i++){
        temp.push_back('1');
    }
    s=s%1;
    if(temp.size()==m && s==0){
        return temp;
    }

    if(s==0 && temp.size()<m && temp.size() !=0){
        while(temp.size()<m){
            temp.push_back('0');
        }
        return temp;
    }
}

vector<char> minimumNumber(int m, int n,  int s){
    vector<char> temp = maximumNumber(m,n,s);
    //cout<<"Asdas"<<endl;
    reverse(temp.begin(),temp.end());
    if(temp.size()!=0){
        if(temp[0]=='0'){
            temp[0]='1';
            for(int i=1;i<temp.size();i++){
                if(temp[i]!='0'){
                    temp[i] = intToChr(chrToInt(temp[i])-1);
                    break;
                }
            }
        }
    }
    return temp;
}

int main(){



    int t;
    cin>>t;
    while(t){
        int d,s;
        cin>>s>>d;
        vector<char> temp = minimumNumber(d,d,s);
        //cout<<temp.size();

        if(temp.size()!=d){
            cout<<-1;
        } else{
            for(int i=0;i<temp.size();i++){
                cout<<temp[i];
            }
        }
        cout<<endl;
        t--;
    }
}