#include <bits/stdc++.h>
using namespace std;
#include <chrono>

typedef struct {
    bool isHorizontal; 
    int x; 
	int y; 
	int len; 
} tempat; 

bool isFitHorizontal(string word, vector<string> puzzle,int i, int j, int n){
    int panjangKata = word.length();
    int panjangSpot = 0;
    for(int idx=j;idx<n;idx++){
        if(puzzle[i][idx]!='#'){
            panjangSpot++;
        } else{
            break;
        }
    }
    if(panjangSpot!=panjangKata){
        return false;

    } else{
        for(int idx = 0;idx<panjangKata;idx++){
            if(puzzle[i][idx+j]=='-'){

            } else if(puzzle[i][idx+j]==word[idx]){

            } else{
                return false;
            }
        }
        return true;
    }
}

bool isFitVertical(string word, vector<string> puzzle,int i, int j, int n){
    int panjangKata = word.length();
    int panjangSpot = 0;
    for(int idx=i;idx<n;idx++){
        if(puzzle[idx][j]!='#'){
            panjangSpot++;
        } else{
            break;
        }
    }
    if(panjangSpot!=panjangKata){
        return false;

    } else{
        for(int idx = 0;idx<panjangKata;idx++){
            if(puzzle[idx+i][j]=='-'){

            } else if(puzzle[idx+i][j]==word[idx]){

            } else{
                return false;
            }
        }
        return true;
    }
}

void fillHorizontal(string word, vector<string> &puzzle,int i, int j){
    //IS: Sudah dilakukan pengecekan apakah sudah fit ke horizontal atau belum
    // kalau belum jangan pake ini.
    int panjangKata = word.length();
    for(int idx=0;idx<panjangKata;idx++){
        puzzle[i][idx+j] = word[idx];
    }    
}

void fillVertical(string word, vector<string> &puzzle,int i, int j){
    //IS: Sudah dilakukan pengecekan apakah sudah fit ke horizontal atau belum
    // kalau belum jangan pake ini.
    int panjangKata = word.length();
    for(int idx=0;idx<panjangKata;idx++){
        puzzle[idx+i][j] = word[idx];
    }    
}

void printAll(vector<string> temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<endl;
    }
}

unordered_set<string> parsingWords(string s){
    unordered_set<string> hasil;
    int n = s.length();
    string temp;
    for(int i=0;i<n;i++){
        if(s[i]!=';'){
            temp.push_back(s[i]);
        } else{
            hasil.insert(temp);
            temp = "";
        }
    }
    if(temp.length()!=0){
        hasil.insert(temp);
    }
    return hasil;

}


void cariTempatHorizontal(vector<string> puzzle , vector<tempat> &tempats,int n){
    for(int i=0;i<n;i++){
        int mulai = 0;
        int panjang = 0;
        for(int j=0;j<n;j++){
            
            if(puzzle[i][j]=='-'){
                if(panjang==0){
                    mulai = j;
                    panjang++;
                } else{
                    panjang++;
                }
            } else{
                if(panjang>1){
                    tempat  temp;
                    temp.x = i;
                    temp.y = mulai;
                    temp.len = panjang;
                    temp.isHorizontal = true;
                    tempats.push_back(temp);
                } 
                panjang=0;
                mulai=0;
            }
        }
        if(panjang>1){
            tempat  temp;
            temp.x = i;
            temp.y = mulai;
            temp.len = panjang;
            temp.isHorizontal = true;
            tempats.push_back(temp);
        }        
    }
}

void cariTempatVertical(vector<string> puzzle , vector<tempat> &tempats,int n){
    for(int i=0;i<n;i++){
        int mulai = 0;
        int panjang = 0;
        for(int j=0;j<n;j++){
            
            if(puzzle[j][i]=='-'){
                if(panjang==0){
                    mulai = j;
                    panjang++;
                } else{
                    panjang++;
                }
            } else{
                if(panjang>1){
                    tempat  temp;
                    temp.x = mulai;
                    temp.y = i;
                    temp.len = panjang;
                    temp.isHorizontal = false;
                    tempats.push_back(temp);
                } 
                panjang=0;
                mulai=0;
            }
        }
        if(panjang>1){
            tempat  temp;
            temp.x = mulai;
            temp.y = i;
            temp.len = panjang;
            temp.isHorizontal = false;
            tempats.push_back(temp);
        }        
    }
}
bool solve(vector<string> puzzle,unordered_set<string> kata,vector<tempat> tempats,int n,vector<string> &hasil,int idx){
    printAll(puzzle);
    cout<<endl;
    if(idx==0 && kata.empty()){
        hasil = puzzle;
        return true;
    } else{
        unordered_set<string> ::iterator itr;
        for(itr = kata.begin();itr!=kata.end();itr++){
            vector<string> puzzleTemp = puzzle;
            unordered_set<string> kataTemp = kata;
            kataTemp.erase(*itr);
            if(tempats[idx-1].isHorizontal){
                if(isFitHorizontal(*itr,puzzleTemp,tempats[idx-1].x,tempats[idx-1].y,n)){
                    fillHorizontal(*itr,puzzleTemp,tempats[idx-1].x,tempats[idx-1].y);
                    if(solve(puzzleTemp,kataTemp,tempats,n,hasil,idx-1)){
                        return true;
                    }
                }
            } else{
                if(isFitVertical(*itr,puzzleTemp,tempats[idx-1].x,tempats[idx-1].y,n)){
                    fillVertical(*itr,puzzleTemp,tempats[idx-1].x,tempats[idx-1].y);
                    if(solve(puzzleTemp,kataTemp,tempats,n,hasil,idx-1)){
                        return true;
                    }
                }
            }
        }
        return false;
    } 
}
int main(){
    
    int n;
    cin>>n;
    vector<string> temp(n,"");
    for(int i=0;i<n;i++){
        cin>>temp[i];

    }

    vector<tempat> tempats;
    //Cari Horizontal
    cariTempatHorizontal(temp,tempats,n);
    cariTempatVertical(temp,tempats,n);

   
    string words;
    cin>>words;
    unordered_set<string> kata = parsingWords(words);
    vector<string> hasil ;
    solve(temp,kata,tempats,n,hasil,tempats.size());
    printAll(hasil);
}