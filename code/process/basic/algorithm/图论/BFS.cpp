#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void bfs(const std::unordered_map<char, std::vector<char>>& graph, char start) {
    std::set<char> visited;
    std::queue<char> queue;
    queue.push(start);

    while (!queue.empty()) {
        char node = queue.front();
        queue.pop();

        if (visited.find(node) == visited.end()) {
            std::cout << node << " ";
            visited.insert(node);

            for (char neighbor : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                }
            }
        }
    }
}

void bfs_node2node(const std::unordered_map<char, std::vector<char>>& graph, char start,char end,unordered_map<char, char>& path_record) {
    std::set<char> visited;
    std::queue<char> queue;
    queue.push(start);

    char former='#';//初始化空前继节点
    int find_flag=1;

    while (!queue.empty() && find_flag ) {
        char node = queue.front();
        queue.pop();

        if (visited.find(node) == visited.end()) {
            
            visited.insert(node);
            path_record[node]=former;
            if(node==end){
                find_flag=0;
            }

            for (char neighbor : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                }
            }
        }
        former=node;
    }
    if(find_flag==0){
        cout<<"path "<<start<<" to "<<end<<endl;
        vector<char> rpath;
        rpath.push_back(end);
        char former_node=path_record[end];
        while(former_node!='#'){
            rpath.push_back(former_node);
            former_node=path_record[former_node];
        }
        for(auto it=rpath.rbegin();it!=rpath.rend();it++){
            cout<<*it<<" ";
        }
    }else{
        cout<<"no path from "<<start<<" to "<<end<<endl;
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
    std::unordered_map<char, char> path_record = {
        {'A',' '},
        {'B', ' '},
        {'C', ' '},
        {'D', ' '},
        {'E', ' '},
        {'F', ' '}
    };

    std::cout << "BFS starting from node A: ";
    bfs(graph, 'A');
    std::cout << std::endl;

    bfs_node2node(graph,'A','B',path_record);

    return 0;
}
