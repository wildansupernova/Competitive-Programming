#include <bits/stdc++.h>
using namespace std;
#include <chrono>
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

vector<string> solvePuzzle(vector<string> puzzle, unordered_set<string> words,int n){
   
    if(words.empty()){
        return puzzle;
    } else{
         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(puzzle[i][j]!='#'){
                    
                    unordered_set<string>::iterator itr;
                    for(itr = words.begin();itr != words.end();itr++){
                        string temp = *itr;
                        
                        unordered_set<string> copyWords = words;
                        copyWords.erase(temp);

                        if(isFitVertical(temp,puzzle,i,j,n)){
                            
                            vector<string> puzzleTemp = puzzle;
                            fillVertical(temp, puzzleTemp,i,j);
                            printAll(puzzleTemp);
                            cout<<endl<<endl;
                            puzzleTemp = solvePuzzle(puzzleTemp,copyWords,n);
                            if(puzzleTemp.size()!=0){
                                return puzzleTemp;
                            }
                        }
                        if(isFitHorizontal(temp,puzzle,i,j,n)){
                            vector<string> puzzleTemp = puzzle;
                            fillHorizontal(temp, puzzleTemp,i,j);
                            puzzleTemp = solvePuzzle(puzzleTemp,copyWords,n);
                            printAll(puzzleTemp);
                            if(puzzleTemp.size()!=0){
                                return puzzleTemp;
                            }
                        }
                    }
                }
            }
        }
        vector<string> kosong;
        return kosong;
    }
}
int main(){
    
    int n;
    cin>>n;
    vector<string> temp(n,"");
    for(int i=0;i<n;i++){
        cin>>temp[i];

    }
    string words;
    cin>>words;
    unordered_set<string> kata = parsingWords(words);
    auto t1 = std::chrono::high_resolution_clock::now();
    vector<string> hasil = solvePuzzle(temp,kata,n);
    auto t2 = std::chrono::high_resolution_clock::now();
    cout<<endl;
    cout<<std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<<" ms\n";
    printAll(hasil);
}