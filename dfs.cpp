#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res){
    visited[s] = true;
    res.push_back(s);
    for(int i: adj[s]){
        if(visited[i] == false){
            dfs(adj, visited, i, res);
        }
    }
}

vector<int> initialize(vector<vector<int>> &adj){
    for(int i=0; i<adj.size(); i++){
        sort(adj[i].begin(), adj[i].end());
    }
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfs(adj, visited, 0, res);
    return res;
}

void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main() {
	int V = 5;
	vector<vector<int>> adj(V);
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
	for(auto &e: edges){
	    addEdge(adj, e[0], e[1]);
	}
	vector<int> res = initialize(adj);
	for(int i=0; i<V; i++){
	    cout<<res[i]<<" ";
	}


}
