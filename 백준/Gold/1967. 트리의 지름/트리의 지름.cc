#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
bool visited[10005] = { false, };
vector<pair<int, int>> graph[10005];
int cnt = 0;
int max_dist = 0;
int far = 0;
void dfs(int cur, int d)
{
	if (visited[cur]) return;
	if (d > max_dist)
	{
		max_dist = d;
		far = cur;
	}

	visited[cur] = true;
	for (auto [next, dist] : graph[cur])
	{
		if (!visited[next])
		{
			dfs(next, d + dist);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	max_dist = 0;
	dfs(far, 0);
	cout << max_dist;
}
