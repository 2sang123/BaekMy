#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> graph[100005];
vector<bool> visited(100005,false);
vector<int> arr;
void dfs(int s, int dep)
{
    if (visited[s] == true)
    {
        return;
    }
    visited[s] = true;
    arr[s] = dep;
    for (int i = 0; i < graph[s].size(); i++)
    {
        dfs(graph[s][i],dep+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin >> n >> m >> s;
    arr.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(s,0);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << '\n';
    }
}
