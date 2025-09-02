#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
int n, m;
vector<int> graph[10002];
vector<bool> visit(10002, false);
vector<int> outs;
int bfs(int s)
{
	queue<int> q;
	q.push(s);
	visit[s] = true;
	int d = 1;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int next : graph[node])
		{
			if (visit[next] == false)
			{
				visit[next] = true;
				q.push(next);
				d++;
			}
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[v].push_back(u);
	}
	int a = 0;
	for (int i = 1; i <= n; i++)
	{
		int b = bfs(i);
		visit.assign(10002, false);
		if (b == a)
		{
			outs.push_back(i);
		}
		else if(b>a)
		{
			a = b;
			outs.clear();
			outs.push_back(i);
		}
		
	}
	for (auto out : outs)
	{
		cout << out << ' ';
	}
}
