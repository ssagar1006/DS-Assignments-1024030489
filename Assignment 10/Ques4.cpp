#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

struct Graph
{
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) : V(V), E(E) {}
    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
    }

    int find(vector<int> &parent, int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    void unite(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void KruskalMST()
    {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b)
             { return a.w < b.w; });

        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        vector<Edge> result;

        for (auto e : edges)
        {
            int x = find(parent, e.u);
            int y = find(parent, e.v);
            if (x != y)
            {
                result.push_back(e);
                unite(parent, rank, x, y);
            }
        }

        cout << "Edges in MST:\n";
        for (auto e : result)
            cout << e.u << " - " << e.v << " : " << e.w << endl;
    }
};

int main()
{
    Graph g(4, 5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.KruskalMST();
    return 0;
}
