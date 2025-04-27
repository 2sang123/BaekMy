#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> dp;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int dfs(int cx, int cy)
{
	if (cx == n - 1 && cy == m - 1) return 1;
	if (dp[cx][cy] != -1) return dp[cx][cy];
	dp[cx][cy] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + cx;
		int ny = dy[i] + cy;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[cx][cy] >graph[nx][ny])
		{
			dp[cx][cy] += dfs(nx, ny);
		}
	}
	return dp[cx][cy];
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	graph.assign(n, vector<int>(m));
	dp.assign(n, vector<int>(m,-1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}
	cout << dfs(0, 0);
}
