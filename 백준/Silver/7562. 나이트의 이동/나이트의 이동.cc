#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int bfs(int x, int y, int tx, int ty)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	graph[x][y] = 0;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++)
		{
			int mx = cx + dx[i];
			int my = cy + dy[i];
			
			if (mx >= 0 && mx < n && my<n && my >= 0)
			{
				if (!visited[mx][my])
				{
					graph[mx][my] = graph[cx][cy] + 1;
					if (mx == tx && my == ty)
					{
						return graph[mx][my];
					}
					visited[mx][my] = true;
					q.push({ mx,my });
				}
			}
		}
	}
	return graph[tx][ty];
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		graph.assign(n, vector<int>(n));
		visited.assign(n, vector<bool>(n, false));
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == c && b == d)
		{
			cout << 0 << '\n';
		}
		else cout << bfs(a, b, c, d) << '\n';
	}
}
