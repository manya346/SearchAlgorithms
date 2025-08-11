#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj = {
        {1, 2},      
        {0, 2, 3},   
        {0, 4},     
        {1, 4},      
        {2, 3}    
    };

    vector<bool> visited(V, false);
    bfs(0, adj, visited);

    fill(visited.begin(), visited.end(), false); 
    cout << "DFS: ";
    dfs(0, adj, visited);
    cout << endl;

    return 0;
}
