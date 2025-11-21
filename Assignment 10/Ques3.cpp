#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v])
            if (!visited[u])
                DFSUtil(u, visited);
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    return 0;
}
