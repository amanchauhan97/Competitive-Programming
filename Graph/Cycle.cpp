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
    bool DetectCycle()
    {
        vector<bool> visited(v,false);
        queue<pair<int,int> > q;
        visited[0] = true;
        q.push(make_pair(0,-1));
        while(!q.empty())
        {
            pair<int,int> t = q.front();
            q.pop();
            for(auto itr : adj[t.first])
            {
                if(itr == t.second)
                  continue;
                if(!visited[itr])
                {
                    visited[itr] = true;
                    q.push(make_pair(itr,t.first));
                }
                else
                  return true;
            }
        }
        return false;
    }
};

int main()
{
    
}
