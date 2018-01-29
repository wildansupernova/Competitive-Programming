//http://codeforces.com/problemset/problem/489/C
//Given Length and Sum of Digits


#include <bits/stdc++.h>

using namespace std;

string isi = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
string a[105][901];
int chrToInt(char a){
    return a-'0';
}

char intToChr(int a){
    return '0'+a;
}


string minimumNumber(int m, int n,  int s){
    if(s==0 && n==0)
        return "";
    if(s>0 && n==0)
        return isi;
    //Untuk char 0
    if(m!=n){
        string temp = minimumNumber(m,n-1,s);
        if(!(temp.length()>n-1)){
            return "0"+temp;
        } 
    }
    string temp;
    //Untuk char 1
    if((s-1)>=0){
        temp = minimumNumber(m,n-1,s-1);
        if(!(temp.length()>n-1)){
            return "1"+temp; 
        }
    }
    
    //Untuk char 2
    if((s-2)>=0){
        temp = minimumNumber(m,n-1,s-2);
        if(!(temp.length()>n-1)){
            return "2"+temp; 
        }
    }
    //Untuk char 3
    if((s-3)>=0){
        temp = minimumNumber(m,n-1,s-3);
        if(!(temp.length()>n-1)){
            return "3"+temp; 
        }
    }
    //Untuk char 4
    if((s-4)>=0){
        temp = minimumNumber(m,n-1,s-4);
        if(!(temp.length()>n-1)){
            return "4"+temp; 
        }
    }
    //Untuk char 5
    if((s-5)>=0){
        temp = minimumNumber(m,n-1,s-5);
        if(!(temp.length()>n-1)){
            return "5"+temp; 
        }
    }
    //Untuk char 6
    if((s-6)>=0){
        temp = minimumNumber(m,n-1,s-6);
        if(!(temp.length()>n-1)){
            return "6"+temp; 
        }
    }
    //Untuk char 7
    if((s-7)>=0){
        temp = minimumNumber(m,n-1,s-7);
        if(!(temp.length()>n-1)){
            return "7"+temp; 
        }
    }
    //Untuk char 8
    if((s-8)>=0){
        temp = minimumNumber(m,n-1,s-8);
        if(!(temp.length()>n-1)){
            return "8"+temp; 
        }
    }
    //Untuk char 9
    if((s-9)>=0){
        temp = minimumNumber(m,n-1,s-9);
        if(!(temp.length()>n-1)){
            return "9"+temp; 
        }
        
    }
    
    return isi;
}

string maximumNumber(int m, int n,  int s){
    if(s==0 && n==0)
        return "";
    if(s>0 && n==0)
        return isi;

    string temp;
    //Untuk char 9
    if((s-9)>=0){
        temp = maximumNumber(m,n-1,s-9);
        if(!(temp.length()>n-1)){
            return "9"+temp; 
        }
        
    }
    //Untuk char 8
    if((s-8)>=0){
        temp = maximumNumber(m,n-1,s-8);
        if(!(temp.length()>n-1)){
            return "8"+temp; 
        }
    }
    //Untuk char 7
    if((s-7)>=0){
        temp = maximumNumber(m,n-1,s-7);
        if(!(temp.length()>n-1)){
            return "7"+temp; 
        }
    }   
    //Untuk char 6
    if((s-6)>=0){
        temp = maximumNumber(m,n-1,s-6);
        if(!(temp.length()>n-1)){
            return "6"+temp; 
        }
    } 
    //Untuk char 5
    if((s-5)>=0){
        temp = maximumNumber(m,n-1,s-5);
        if(!(temp.length()>n-1)){
            return "5"+temp; 
        }
    }
    //Untuk char 4
    if((s-4)>=0){
        temp = maximumNumber(m,n-1,s-4);
        if(!(temp.length()>n-1)){
            return "4"+temp; 
        }
    }
    //Untuk char 3
    if((s-3)>=0){
        temp = maximumNumber(m,n-1,s-3);
        if(!(temp.length()>n-1)){
            return "3"+temp; 
        }
    }
    
    //Untuk char 2
    if((s-2)>=0){
        temp = maximumNumber(m,n-1,s-2);
        if(!(temp.length()>n-1)){
            return "2"+temp; 
        }
    }
    //Untuk char 1
    if((s-1)>=0){
        temp = maximumNumber(m,n-1,s-1);
        if(!(temp.length()>n-1)){
            return "1"+temp; 
        }
    }
    //Untuk char 0
    if(m!=n){
        string temp = maximumNumber(m,n-1,s);
        if(!(temp.length()>n-1)){
            return "0"+temp;
        } 
    }
    return isi;
}

int main(){
    int n,s;
    cin>>n>>s;
    string min = minimumNumber(n,n,s);
    string max = maximumNumber(n,n,s);
    if(n==1 && s==0){
        cout<<0<<" "<<0<<endl;
    } else{
        if(min.length()!=n && max.length()!=n){
            cout<<-1<<" "<<-1<<endl;
        } else {
            cout<<min<<" "<<max<<endl;
        }
    }

}