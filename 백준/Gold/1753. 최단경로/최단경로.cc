#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

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
    int n, m, start;
    cin >> n >> m>>start;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v,w });
    }
    vector<int> dist = dijkstra(start, n, graph);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}
