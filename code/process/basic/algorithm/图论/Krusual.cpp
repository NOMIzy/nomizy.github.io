#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }


};

vector<Edge> kruskalMST(int numVertices, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(numVertices);
    vector<Edge> mst;

    for (const Edge& edge : edges) {
        if (uf.find(edge.src) != uf.find(edge.dest)) {
            uf.unite(edge.src, edge.dest);
            mst.push_back(edge);
        }
    }
    return mst;
}

int main() {
    int numVertices = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    vector<Edge> mst = kruskalMST(numVertices, edges);

    cout << "Edges in the MST:\n";
    for (const Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << ": " << edge.weight << "\n";
    }

}
