#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
vector<int> graph[501];
vector<bool> visit(501, false);
int ans = 0;
void bfs(int s)
{
	queue<pair<int,int>> q;
	q.push({s, 0});
	visit[s] = true;
	int cnt = 0;
	while (!q.empty())
	{
		auto [node, depth] = q.front();
		q.pop();
		if (depth == 2) continue;
		for (int next : graph[node])
		{
			if (visit[next] == false)
			{
				ans++;
				visit[next] = true;
				q.push({ next, depth + 1 });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int p, q;
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}
	bfs(1);
	cout << ans;
}
