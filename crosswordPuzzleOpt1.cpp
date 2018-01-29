#include <bits/stdc++.h>
using namespace std;
#include <chrono>

typedef struct {
    bool isHorizontal; 
    int x; 
	int y; 
	int len; 
} tempat; 
bool banding(tempat a,tempat b){
    //return a.len<b.len;
    if(a.len!=b.len)
        return a.len<b.len;
    else
        if(a.x!=b.x) 
            return a.x<b.x;
        return a.y<b.y;
}
bool banding2(string a,string b){
    return a.length()>a.length();
}
bool isFitHorizontal(string word, vector<string> puzzle,int i, int j, int n){
    int panjangKata = word.length();
    int panjangSpot = 0;
    for(int idx=j;idx<n;idx++)
        if(puzzle[i][idx]!='#')
            panjangSpot++;
        else
            break;
    if(panjangSpot!=panjangKata)
        return false;
    else
        for(int idx = 0;idx<panjangKata;idx++)
            if(puzzle[i][idx+j]!='-' && puzzle[i][idx+j]!=word[idx])
                return false;
        return true;
    
}
bool isFitVertical(string word, vector<string> puzzle,int i, int j, int n){
    int panjangKata = word.length();
    int panjangSpot = 0;
    for(int idx=i;idx<n;idx++)
        if(puzzle[idx][j]!='#')
            panjangSpot++;
        else
            break;
    if(panjangSpot!=panjangKata)
        return false;
    else
        for(int idx = 0;idx<panjangKata;idx++)
            if(puzzle[idx+i][j]!='-' && puzzle[idx+i][j]!=word[idx])
                return false;
        return true;
}

void fillHorizontal(string word, vector<string> &puzzle,int i, int j){
    //IS: Sudah dilakukan pengecekan apakah sudah fit ke horizontal atau belum
    // kalau belum jangan pake ini.
    int panjangKata = word.length();
    for(int idx=0;idx<panjangKata;idx++)
        puzzle[i][idx+j] = word[idx];
}

void fillVertical(string word, vector<string> &puzzle,int i, int j){
    //IS: Sudah dilakukan pengecekan apakah sudah fit ke horizontal atau belum
    // kalau belum jangan pake ini.
    int panjangKata = word.length();
    for(int idx=0;idx<panjangKata;idx++)
        puzzle[idx+i][j] = word[idx];
}

void printAll(vector<string> temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<endl;
    }
}

vector<string> parsingWords(string s){
    vector<string> hasil;
    int n = s.length();
    string temp;
    for(int i=0;i<n;i++){
        if(s[i]!=';'){
            temp.push_back(s[i]);
        } else{
            hasil.push_back(temp);
            temp = "";
        }
    }
    if(temp.length()!=0)
        hasil.push_back(temp);
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
bool solve(vector<string> puzzle,vector<string> kata,vector<tempat> tempats,int n,vector<string> &hasil,int idx){
    //printAll(puzzle);
    //cout<<endl;
    if(kata.empty()){
        hasil = puzzle;
        return true;
    } else{
        
        for(int itr = 0;itr<kata.size();itr++){
            vector<string> puzzleTemp = puzzle;
            vector<string> kataTemp = kata;
            kataTemp.erase(kataTemp.begin()+itr);
            if(tempats[idx-1].isHorizontal){
                if(isFitHorizontal(kata[itr],puzzleTemp,tempats[idx-1].x,tempats[idx-1].y,n)){
                    fillHorizontal(kata[itr],puzzleTemp,tempats[idx-1].x,tempats[idx-1].y);
                    if(solve(puzzleTemp,kataTemp,tempats,n,hasil,idx-1)){
                        return true;
                    }
                }
            } else{
                if(isFitVertical(kata[itr],puzzleTemp,tempats[idx-1].x,tempats[idx-1].y,n)){
                    fillVertical(kata[itr],puzzleTemp,tempats[idx-1].x,tempats[idx-1].y);
                    if(solve(puzzleTemp,kataTemp,tempats,n,hasil,idx-1)){
                        return true;
                    }
                }
            }
        }
        return false;
    } 
}

bool banding3(vector<tempat> a,vector<tempat> b){
    return a.size()>b.size();
}
vector<tempat> hasilOptimasi(vector<tempat> tempats){
    vector<tempat> temp;
    int n =tempats.size(); 
    if(n!=0){
        vector< vector<tempat> > opt;
        vector<tempat> tempOpt;
        tempOpt.push_back(tempats[0]);
        for(int i=1;i<n;i++){
            if(tempats[i].len!=tempats[i-1].len){
                opt.push_back(tempOpt);
                tempOpt.clear();
            } 
            tempOpt.push_back(tempats[i]);
        }
        sort(opt.begin(),opt.end(),banding3);
        int ntemp = opt.size();
        for(int i=0;i<ntemp;i++){
            int panjang = opt[i].size();
            for(int j=0;j<panjang;j++){
                temp.push_back(opt[i][j]);
            }
        }
    }
    return temp;
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
    vector<string> kata = parsingWords(words);
    //Optimasi - Silakan ingin dikomen atau tidak
    sort(tempats.begin(),tempats.end(),banding);
    sort(kata.begin(),kata.end(),banding2);
    tempats = hasilOptimasi(tempats);
    //
    vector<string> hasil ;
    auto t1 = std::chrono::high_resolution_clock::now();
    solve(temp,kata,tempats,n,hasil,tempats.size());
    auto t2 = std::chrono::high_resolution_clock::now();
    cout<<"Selesai dalam " <<std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<<" milliseconds\n";
    printAll(hasil);
}