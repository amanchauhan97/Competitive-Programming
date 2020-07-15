#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    list<int> *adj;
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFSUntill(int src,vector<int> &visited)
    {
        if(visited[src])
          return;
        visited[src] = true;
        cout << src << " -> ";
        for(auto itr : adj[src])
        {
            if(!visited[itr])
              DFSUntill(itr,visited);
        }
    }
    void DFS(int src)
    {
        vector<int> visited(v,false);
        DFSUntill(src,visited);
    }
};

int main()
{
    int v,e;
    cout << "Enter vertex and edges : ";
    cin >> v >> e;
    Graph g(v);
    int src,dest;
    for(int i=0;i<e;i++)
    {
        cin >> src >> dest ;
        g.addEdge(src,dest);
    }
    g.DFS(0);
}
