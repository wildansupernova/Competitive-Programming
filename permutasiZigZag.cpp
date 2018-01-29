//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/18/problems/73/
//Permutasi Zig-Zag



#include <bits/stdc++.h>

using namespace std;

int chrToInt(char a){
    return a-'0';
}
char intToChr(int a){
    return '0'+a;
}
bool isDipakai[10];
void printAll(string s, int n){
    if(s.length()==n){
        cout<<s<<endl;
    } else{
        if(s.length()<2){
            for(int i=1;i<=n;i++){
                if(!isDipakai[i]){
                    isDipakai[i]=true;
                    string temp=s;
                    temp.push_back(intToChr(i));
                    printAll(temp,n);
                    isDipakai[i]=false;
                }
            }
        }else{
            int panjang = s.length();
            int before1 = chrToInt(s[panjang-1]);
            int before2 = chrToInt(s[panjang-2]);
            if(before1>before2){
                for(int i=1;i<before1;i++){
                    if(!isDipakai[i]){
                        isDipakai[i]=true;
                        string temp =s;
                        temp.push_back(intToChr(i));
                        printAll(temp,n);
                        isDipakai[i]=false;
                    }

                }
            } else if(before1<before2){
                for(int i = before1+1;i<=n;i++){
                    if(!isDipakai[i]){
                        isDipakai[i]=true;
                        string temp=s;
                        temp.push_back(intToChr(i));
                        printAll(temp,n);
                        isDipakai[i]=false;
                    }
                }
            }
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=9;i++){
        isDipakai[i]=false;
    }
    printAll("",n);
}