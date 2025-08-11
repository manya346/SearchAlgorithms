#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm> 

void dfs(const std::map<char, std::vector<char>>& graph, char node, std::set<char>& visited, std::vector<char>& path) {
    
    visited.insert(node);
    path.push_back(node);

    auto newnode = graph.find(node);
    if (newnode != graph.end()) {
        std::vector<char> nei = newnode->second;

        std::sort(nei.begin(), nei.end());

        for (char n : nei) {
            
            if (visited.find(n) == visited.end()) {
                dfs(graph, n, visited, path);
            }
        }
    }
}

int main() {
    std::map<char, std::vector<char>> sample_graph = {
        {'A', {'D', 'B'}},
        {'B', {'C', 'E'}},
        {'C', {'F'}},
        {'D', {'A', 'E'}},
        {'E', {'F'}},
        {'F', {}}
    };

    char start_node = 'A';
    std::set<char> visited;
    std::vector<char> path;

    dfs(sample_graph, start_node, visited, path);

    std::cout << "Traversal Path ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << (i == path.size() - 1 ? "" : ", ");
    }

    return 0;
}