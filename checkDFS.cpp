//https://csacademy.com/contest/archive/task/check-dfs/statement/

#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100005;
bool visited [kMaxN];
int order[kMaxN];
int idx;

bool dfs(int now,map<int , unordered_set<int> > &grap, int n){
    if(!visited[now]){
        visited[now]=true;
        if(now==order[idx]){
            idx++;
            if (idx<n){
                unordered_set<int> temp = grap[now];
                while(temp.find(order[idx])!=temp.end()){
                    temp.erase(order[idx]);
                    dfs(order[idx],grap,n);
                }
                unordered_set<int>::iterator itr;
                for( itr=grap[now].begin();itr!=grap[now].end();itr++){
                    dfs(*itr,grap,n);
                }
            }
        } else{
            unordered_set<int>::iterator itr;
            for( itr=grap[now].begin();itr!=grap[now].end();itr++){
                dfs(*itr,grap,n);
            }
        }
    }
}



int main(){
    for(int i=0;i<kMaxN;i++){
        visited[i]=false;
    }
    idx=0;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>order[i];
    }
    map<int , unordered_set<int> > grap;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        grap[a].insert(b);
        grap[b].insert(a);
    }
    dfs(1,grap,n);
    if(idx==n){
        cout<<true<<endl;
    } else{
        cout<<false<<endl;
    }
}