#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int s, int n, vector<vector<pair<int, int>>>& graph)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[s] = 0;
    pq.push({ 0, s }); // {거리, 노드}

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curr_dist > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int cost = edge.second;

            if (curr_dist + cost < dist[v]) {
                dist[v] = curr_dist + cost;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v,w });
    }
    int s, en;
    cin >> s >> en;
    vector<int> dist = dijkstra(s, n, graph);
    cout << dist[en];
}
