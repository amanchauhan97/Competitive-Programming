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
    void TopologicalSortUntill(int src,vector<bool> &visited,stack<int> &st)
    {
        visited[src] = true;
        for(auto itr : adj[src])
        {
            if(!visited[itr])
              TopologicalSortUntill(itr , visited, st);
        }
        st.push(src);
    }
    void TopologicalSort()
    {
        vector<bool> visited(v,false);
        stack<int> st;
        for(int i=0;i<v;i++)
          if(!visited[i])
            TopologicalSortUntill(i,visited,st);
        while(!st.empty())
        {
            cout << st.top() << " -> ";
            st.pop();
        }
    }
};

int main()
{
    int v,e,s,d;
    cout << "Enter number of vertex and edged : ";
    cin >> v >> e;
    Graph g(v);
    for(int i=0;i<e;i++)
    {
        cin >> s >> d;
        g.addEdge(s,d);
    }
    g.TopologicalSort();
}
