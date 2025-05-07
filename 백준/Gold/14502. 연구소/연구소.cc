#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int>> virus;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int bfs(vector<pair<int, int>> p)
{
	vector<vector<int>> cgraph = graph;
	queue<pair<int, int>> q;
	for (int i = 0; i < p.size(); i++)
	{
		q.push(p[i]);
		visited[p[i].first][p[i].second] = true;
	}

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && cgraph[nx][ny]!=1 && !visited[nx][ny])
			{
				cgraph[nx][ny] = 2;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	int area = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cgraph[i][j]==0) area++;
		}
	}
	return area;
}
int out = -1;
void walls(int cnt, int start)
{
	if (cnt ==  3)
	{
		out = max(bfs(virus), out);
		visited.assign(n, vector<bool>(m, false));
		return;
	}
	for (int i = start; i < n * m; i++)
	{
		int x = i / m;
		int y = i % m;
		if (graph[x][y] == 0)
		{
			graph[x][y] = 1;
			walls(cnt + 1, i + 1);
			graph[x][y] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	graph.resize(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
			{
				virus.push_back({ i, j });
			}
		}
	}

	walls(0, 0);
	cout << out;
}
