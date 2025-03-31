#include <iostream>
#include <vector>
#include <algorithm>

#include <queue>
using namespace std;

int n;
int m;
vector<int> connec[101];
vector<bool> visit(5001, false);
vector<int> dist;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visit[s] = true;
    dist[s] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int next : connec[node])
        {
            if (visit[next] == false)
            {
                dist[next] = dist[node] + 1;
                visit[next] = true;
                q.push(next);

            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dist.assign(n + 1, 1e9);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        
        cin >> u >> v;

        connec[u].push_back(v);
        connec[v].push_back(u);
    }
    
    int d = 100000;
    int out = 0;
    for (int i = 1; i <= n; i++)
    {
        int test = 0;
        bfs(i);
        for (int j = 1; j <= n; j++)
        {
            test += dist[j];
        }
        if (d > test) out = i;
        d = min(d, test);
        visit.assign(5001, false);
        dist.assign(n + 1, 1e9);
    }
    cout << out;
}
