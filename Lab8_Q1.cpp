// Implement BFS algorithm using Adjacency List in the directed graph.
// NAME - YASH DABAS
// CLASS- CSAI-2;
// ROLL NO.- 2021UCA1912
// "I have done this assignment on my own. I have not copied any code from another student or
// any online source. I understand if my code is found similar to somebody else's code, my case can
// be sent to the Disciplinary committee of the institute for appropriate action."


#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class graph{
    public:
    unordered_map<T,list<T>>adj;
    void AddEdge(int u,int v){
        adj[u].push_back(v);
    }
    void BFS(T src){
        unordered_map<T,bool>visited;
        queue<T>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(int nbrs:adj[node]){
                if(!visited[nbrs]){
                    q.push(nbrs);
                    visited[nbrs]=true;
                }
            }
        }
    }
};
int main(){
    graph<int>g;
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);
    g.BFS(0);
    return 0;
}