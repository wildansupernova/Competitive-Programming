//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//	Detect cycle in an undirected graph (Function Problem)
#include <bits/stdc++.h>

using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};

Graph::Graph(int V){
    list<int> baru;
    //cout<<V<<endl;
    this->adj = &baru;
    this->V = V;
}

void Graph::addEdge(int v, int w){
    cout<<"hasi;"<<endl;
    //cout<<v<<" "<<w<<endl;
    (*(this->adj)).push_back(v);
    (*(this->adj)).push_back(w);
}
bool cekCyclic(unordered_map<int,vector<int> > graph,int parent,int nodeNow,vector<bool> & isVisited){
    
    if(isVisited[nodeNow]){
            return true;
    }

    if(parent==-1){
        isVisited[nodeNow]=true;
        for(auto c : graph[nodeNow]){
            if(cekCyclic(graph,nodeNow,c,isVisited)){
                return true;
            }
        }
        return false;
    } else{

        isVisited[nodeNow]=true;
        for(auto c : graph[nodeNow]){
            if(c!=parent){
                if(cekCyclic(graph,nodeNow,c,isVisited)){
                    return true;
                }
            }
        }
        return false;      
    }
}

bool Graph :: isCyclic()
{
//Your code here
    //list<int> *temp  = (this->adj);
    list<int>::iterator itr; 
    unordered_map<int,vector<int> >graph;
    int now = -1;
    
    for(itr = (*(this->adj)).begin();itr!=(*(this->adj)).end();++itr){
        if(now==-1){
            now = *itr;
            
        } else{
            graph[*itr].push_back(now);
            graph[now].push_back(*itr);
            now=-1;
        }
    }
    vector<bool> isVisited(this->V,false);
    return cekCyclic(graph,-1,0,isVisited);

}


int main(){
    int n,m;
    cin>>n>>m;
    
    Graph mantap(n);
    
    for(int i=0;i<m;i++){
        int v,w;
        cin>>v>>w;
        mantap.addEdge(v,w);
    }
    //cout<<"hasil"<<endl;
    cout<<mantap.isCyclic()<<endl;

}