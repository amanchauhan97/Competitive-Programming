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
    }
    bool CycleUntill(int src,vector<bool> &visited,vector<bool> &inStack)
    {
        if(visited[src] == false)
        {
            visited[src] = true;
            inStack[src] = true;
            for(auto itr : adj[src])
            {
                if(!visited[itr] && CycleUntill(itr,visited,inStack))
                  return true;
                else if(inStack[itr])
                  return true;
            }
        }
        inStack[src] = false;
        return false;
    }
    bool Cycle()
    {
        vector<bool> visited(v,false);
        vector<bool> inStack(v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
              if(CycleUntill(i,visited,inStack))
                return true;
        }
        return false;
    }
};

int main()
{
    int v,e;
    cout << "Enter vertex and edges : ";
    cin >> v >> e;
    Graph g(v);
    int s,d;
    for(int i=0;i<e;i++)
    {
        cin >> s >> d;
        g.addEdge(s,d);
    }
    if(g.Cycle())
      cout << "Cycle exists in directed graph" << endl;
    else
      cout << "Cycle does not exist in directed graph" << endl;
}
