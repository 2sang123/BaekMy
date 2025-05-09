#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> graph;
vector<int> color;
bool isBia = false;
void dfs(int r, int c)
{
	color[r] = c;

	for (int next : graph[r])
	{
		if (color[next] == 0)
		{
			dfs(next, -c);
		}
		else if (color[next] == color[r])
		{
			isBia = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	while (n--)
	{
		int V, e;
		isBia = true;
		cin >> V >> e;
		graph.assign(V+1, vector<int>());
		color.assign(V+1, 0);

		for (int i = 0; i < e; i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <=V ; i++)
		{
			if (color[i] == 0)
			{
				dfs(i, 1);
			}
		}

		if (isBia) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
