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
    void BFS(int src)
    {
        vector<bool> visited(v,false);
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            cout << t << " -> ";
            for(auto itr : adj[t])
            {
                if(!visited[itr])
                {
                    q.push(itr);
                    visited[itr] = true;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int v,e,src,dest;
    cout << "Enter vertex and edges : ";
    cin >> v >> e;
    Graph g(v);
    for(int i=0;i<e;i++)
    {
      cin >> src >> dest;
      g.addEdge(src,dest);
    }
    g.BFS(0);
}
