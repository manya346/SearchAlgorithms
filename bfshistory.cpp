#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue> 

void bfs(const std::map<char, std::vector<char>>& graph, char start_node, std::set<char>& visited, std::vector<char>& path) {
    std::queue<char> q;

    visited.insert(start_node);
    q.push(start_node);

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        path.push_back(node);

        auto find_node = graph.find(node);
        if (find_node != graph.end()) {
            std::vector<char> neighbors = find_node->second;

            std::sort(neighbors.begin(), neighbors.end());

            for (char neighbor : neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
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

    bfs(sample_graph, start_node, visited, path);

    std::cout << "BFS Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}