#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<vector<vector<bool>>> visited;
vector<vector<bool>> blocked;
vector<vector<vector<int>>> dist;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0,-1,1 };


void bfs(int x, int y)
{
	queue<tuple<int, int, bool>> q;
	q.push({ x, y,0 });
	visited[x][y][0] = true;
	dist[x][y][0] = 1;
	while (!q.empty())
	{
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		bool crash = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m )
			{
				if (blocked[nx][ny])
				{
					{
						if (!crash && !visited[nx][ny][1])
						{
							q.push({ nx,ny,true });
							visited[nx][ny][1] = true;
							dist[nx][ny][1] = dist[cx][cy][0] + 1;
						}
					}
				}
				else
				{
					if (!visited[nx][ny][crash]) {
						q.push({ nx, ny, crash });
						visited[nx][ny][crash] = true;
						dist[nx][ny][crash] = dist[cx][cy][crash] + 1;
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.assign(n, vector<vector<int>>(m,vector<int>(2,-1)));
	visited.assign(n, vector<vector<bool>>(m,vector<bool>(2,false)));
	blocked.assign(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '1')
				blocked[i][j] = true;
		}
	}
	bfs(0, 0);
	int dist1 = dist[n - 1][m - 1][0];
	int dist2 = dist[n - 1][m - 1][1];
	if (dist1 >= 0 &&  dist2 >= 0)
	{
		cout << min(dist1, dist2);
	}
	else if (dist1 <= -1 && dist2 <= -1)
	{
		cout << -1;
	}
	else
	{
		cout << max(dist1, dist2);
	}
}
