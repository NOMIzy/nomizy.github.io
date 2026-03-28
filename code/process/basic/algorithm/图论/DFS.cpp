#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include<stack>

void dfs(const std::unordered_map<char, std::vector<char>>& graph, char node, std::set<char>& visited) {
    if (visited.find(node) == visited.end()) {
        std::cout << node << " ";
        visited.insert(node);

        for (char neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(graph, neighbor, visited);
            }
        }
    }
}

void dfs_stack(const std::unordered_map<char, std::vector<char>>& graph, char start) {
    std::set<char> visited;
    std::stack<char> stack;
    stack.push(start);

    while (!stack.empty()) {
        char node = stack.top();
        stack.pop();

        if (visited.find(node) == visited.end()) {
            std::cout << node << " ";
            visited.insert(node);

            const std::vector<char>& neighbors = graph.at(node);
            for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    stack.push(*it);
                }
            }
        }
    }
}

int main() {
    std::unordered_map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    std::set<char> visited;
    std::cout << "DFS starting from node A: ";
    dfs(graph, 'A', visited);
    std::cout <<std::endl;
    std::cout<< "DFS starting from node A: ";
    dfs_stack(graph,'A');
    std::cout << std::endl;

    return 0;
}
