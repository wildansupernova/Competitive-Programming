
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */

int countDiff(string a, string b){
    int length = a.length();
    int c =0;
    for(int i=0;i<length;i++){
        if(a[i]!=b[i]){
            c++;
        }
    }
    return c;
}

unordered_map<string,bool> makeSetBank(vector<string> bank){
    unordered_map<string,bool> temp;
    int length = bank.size();
    for(int i=0;i<length;i++){
        //temp.insert({bank[i],false});
        temp[bank[i]] =false;
    }

    return temp;

}

vector<string> listOneMutation(string c){
    string letter="ACTG";
    vector<string> temp;
    for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
            if(c[i]!=letter[j]){
                string temp2 = c;
                temp2[i] = letter[j];
                temp.push_back(temp2);
            }
        }
    }
    return temp;
}
int findMutationDistance(string start, string end, vector < string > bank) {
    if(start==end) return 0;
    if(start.length() != 8 || end.length() != 8 ) return -1;
    if(bank.empty()) return -1;
    if(find(bank.begin(),bank.end(),end)==bank.end()) return -1;
    int bankLength = bank.size();
    //Initiation
    unordered_map<string,bool> bankMap = makeSetBank(bank);
    queue<pair<string,int>> bfs;

    bfs.push({start,0});
    while(!bfs.empty()){
        string temp1 = bfs.front().first;
        int dist = bfs.front().second;
        bfs.pop();
        if(temp1==end){
            return dist;
        }
        vector<string> listPossibleMutate = listOneMutation(temp1);
        int lengthPossible = listPossibleMutate.size();
        for(int i=0;i<lengthPossible;i++){
            unordered_map<string,bool> ::iterator itr = bankMap.find(listPossibleMutate[i]);
            if(itr!=bankMap.end()){
                if(!itr->second){
                    itr->second =true;
                    bfs.push({listPossibleMutate[i],dist+1});
                }

            }
        }
    }
    return -1;
}