#include <bits/stdc++.h>

using namespace std;

int kardus(int a, int b){
    if(a>b){
        return 1+kardus(a-1,b);
    } else if(a<b){
        return 1+kardus(a,b-1);
    } else{
        return a+b;
    }
}

int ekor(int a, int b, int t){
    if(b==0){
        return t;
    } else{
        return ekor(a,b-1,t*a);
    }
}

void majumundur(string str,int i){
    if(str.length()-1==i){
        cout<<str[i];
    } else{
        cout<<str[i];
        majumundur(str,i+1);
        cout<<str[i];
    }
}
int ping(int a);
int pong(int a);
int ping(int a)
{
    if (a == 0)  {
        return 0;
    } else {
        return 1 + pong(a - 1);
    }
}

int pong(int a)
{
    if (a == 0)  {
        return 0;
    }else {
        return  2 + ping(a - 1);
    }
}


string wolo(string s)
{
    string t;
    if ( s.length() == 0){
        return "";
    }else {
        t = s;
        //delete(t, 1, 1);
        t.erase(0,1);
        return wolo(t) + s[0];
    }

}

int jdd(int x){
    if(x==0){
        return 0;
    } else{
        return jdd(x/100) + (x%100);
    }
}
int janji(int p, int q,int t){
    if(p==q){
        return t;
    } else if(t%2==1){
        return 2+janji(p+1,q,t+1);
    } else{
        return 2+ janji(p,q-1,t+1);
    }
}
int main(){
    cout<<janji(10,8,0)<<endl;
}