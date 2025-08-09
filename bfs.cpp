#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> bfs(vector<vector<int>> &adj){
    int V = adj.size();
    int s = 0;
    
    for (int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<int> res;
    vector<int> level(V, -1);
    queue<int> q;
    
    level[s] = 0;
    q.push(s);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        
        for(int x : adj[curr]){
            if(level[x] == -1){
                level[x] = level[curr] +1;
                q.push(x);
            }
        }
    }
    return {res, level};
}

int main() {
    int V = 5;
    vector<pair<int,int>> edges = {
        {0,1},
        {0,2}, 
        {1,3},
        {2,3},
        {3,4}  
    };
    vector<vector<int>> adj(V);
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    auto [ans, levels] = bfs(adj);
    cout << "BFS order: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\nLevels:\n";
    for (int i = 0; i < levels.size(); i++) {
        cout << "Node " << i << ": Level " << levels[i] << "\n";
    }
    return 0;
}
