#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
    int V;
    vector<list<int>> adjList;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V)
    {
        this->V = V;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
    }

    void printAdjList()
    {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }

    void printAdjMatrix()
    {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void degree(int v)
    {
        cout << "Out-degree of " << v << ": " << adjList[v].size() << endl;
        int indeg = 0;
        for (int i = 0; i < V; i++)
            for (int x : adjList[i])
                if (x == v)
                    indeg++;
        cout << "In-degree of " << v << ": " << indeg << endl;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAdjList();
    g.printAdjMatrix();
    g.degree(1);

    return 0;
}
