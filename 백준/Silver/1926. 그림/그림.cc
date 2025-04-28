#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
int cnt, big = 0;
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	int area = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && graph[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				area++;
				q.push({ nx,ny });
			}
		}
	}
	big = max(area, big);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	graph.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m,false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 1 && !visited[i][j])
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n' << big;
}
