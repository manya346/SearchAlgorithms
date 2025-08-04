#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void sortAdjLists() {
        for (auto& nei : adj) {
            sort(nei.begin(), nei.end());
        }
    }
};

void bms(Graph& g, int curr, int goal, vector<bool>& visited, vector<int>& path) {
    visited[curr] = true;
    path.push_back(curr);

    if (curr == goal) {
        cout << "Path found: ";
        for (int node : path) cout << node << " ";
        cout << endl;
    } else {
        for (int nei : g.adj[curr]) {
            if (!visited[nei]) {
                bms(g, nei, goal, visited, path);
            }
        }
    }

    visited[curr] = false;
    path.pop_back();
}

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 5);

    g.sortAdjLists();

    int start = 0, goal = 5;
    vector<bool> visited(V, false);
    vector<int> path;

    cout << "Lexicographic British Museum Search from " << start << " to " << goal << "...\n";
    bms(g, start, goal, visited, path);

    return 0;
}
