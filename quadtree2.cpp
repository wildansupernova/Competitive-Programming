//https://training.ia-toki.org/training/curriculums/1/courses/1/chapters/18/problems/76/
//Quadtree 2
#include <bits/stdc++.h>
using namespace std;

int tab[129][129];

int maxnya(int a, int b){
    if(a>=b)
        return a;
    return b;
}

int dekati(int a){
    int awal=1;
    while(awal<a){
        awal*=2;
    }
    return awal;
}
int validkan(int r, int c){
    int didekati = maxnya(r,c);
    int hasildekati = dekati(didekati);
    return hasildekati;
}
void satukan(string s, int x, int y,int sisi){
    if(s.length()==0){
        for(int i=x;i<sisi+x;i++){
            for(int j=y;j<sisi+y;j++){
                tab[i][j]=1;
            }
        }
    } else{
        char belakang = s[s.length()-1];
        string temp = s.substr(0,s.size()-1);
        int bagidua = sisi/2;
        if(belakang == '0'){
            satukan(temp,x,y,bagidua);
        } else if(belakang == '1'){
            satukan(temp,x,y+bagidua,bagidua);
        } else if(belakang == '2'){
            satukan(temp,x+bagidua,y,bagidua);
        } else{
            satukan(temp,x+bagidua,y+bagidua,bagidua);
        }
    }
}
int main(){
    //Inisiasi
    for(int i=0;i<=128;i++){  
        for(int j=0;j<=128;j++){
            tab[i][j]=0;
        }
    }

    int t;
    cin>>t;
    vector<string> arr;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    int r,c;
    cin>>r>>c;
    int sisi = validkan(r,c);
    for(int i=0;i<t;i++){
        string temp = arr[i];
        reverse(temp.begin(),temp.end());
        //temp.pop_back();
        temp = temp.substr(0,temp.size()-1);
        satukan(temp,1,1,sisi);
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(j==c){
                cout<<tab[i][j];
            } else{
                cout<<tab[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}