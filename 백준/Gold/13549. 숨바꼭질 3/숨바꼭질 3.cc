#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e9;
vector<int> dist;
void bfs(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({ 0,s });
    while (!pq.empty())
    {
        int cur = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (cur > dist[u]) continue;
        int fmove = u + 1;
        int bmove = u - 1;
        int warps = u * 2;
        vector<pair<int, int>> move = { {fmove,1},{bmove,1},{warps,0} };
        for (auto [moves, w] : move)
        {
            if (moves >=0 && moves <= 100000)
            {
                int v = moves;
                int cost = w;
                if (dist[v] > cur+cost)
                {
                    dist[v] = cur + cost;
                    pq.push({ dist[v], v });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    dist.assign(100005, INF);
    bfs(n);
    cout << dist[m];
}
