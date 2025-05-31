#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int v;
bool visited[100005] = { false, };
vector<pair<int, int>> graph[100005];
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
	
	cin >> v;

	for (int i = 0; i < v; i++)
	{
		int u = 0;
		int p=0, dist = 0;
		cin >> u;
		while (p != -1)
		{
			cin >> p;
			if (p == -1) break;
			cin >> dist;
			graph[u].push_back({p,dist});
		}
	}
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	max_dist = 0;
	dfs(far, 0);
	cout << max_dist;
}
