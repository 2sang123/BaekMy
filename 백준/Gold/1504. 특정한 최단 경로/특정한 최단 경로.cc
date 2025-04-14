#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e8;

vector<int> dijkstra(int s, int n, vector<vector<pair<int,int>>>& graph)
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

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }
    int a, b;
    cin >> a >> b;
    vector<int> dist = dijkstra(1, n, graph);
    vector<int> dist1 = dijkstra(a, n, graph);
    vector<int> dist2 = dijkstra(b, n, graph);

    int path1 = dist[a] + dist1[b] + dist2[n];
    int path2 = dist[b] + dist2[a] + dist1[n];
    int out = min(path1, path2);
    if (out >= INF) cout << -1;
    else cout << out;
}
