#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v, e;

struct Edge {
    int u, v, w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int find(int x, vector<int>& parent) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x], parent);
}

bool merge(int a, int b, vector<int>& parent) {
    a = find(a, parent); 
    b = find(b, parent);
    if (a == b) return false;
    parent[b] = a;
    return true;
}
int maxCost = 0;
int kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    vector<int> parent(V + 1); 
    for (int i = 1; i <= V; i++) parent[i] = i;

    int totalCost = 0;

    for (Edge e : edges) {
        if (merge(e.u, e.v, parent)) {
            totalCost += e.w;
            maxCost = max(e.w, maxCost);
        }
    }

    return totalCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge d = { a, b, c };
        edges.push_back(d);
    }
    cout << kruskal(v, edges) - maxCost;
}
