#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<int> graph[101];
bool visited[101] = { false };

int bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int roll = 0;
	while (!q.empty())
	{
		int size = q.size();
		
		for (int i = 0; i < size; i++)
		{
			int node = q.front();
			q.pop();
			for (int i = 1; i <= 6; i++)
			{
				int nextP = node + i;
				if (nextP<=100 && !visited[nextP])
				{
					visited[nextP] = true;
					if (!graph[nextP].empty())
					{
						if (!visited[graph[nextP][0]])
						{
							visited[graph[nextP][0]] = true;
							q.push(graph[nextP][0]);
						}
					}
					else
					{
						q.push(nextP);
					}
				}
				if (nextP >= 100)
				{
					return roll + 1;
				}
			}
		}
		roll++;
	}
	return roll;
}

int main() 
{
    cin >> n >> m;
    
	for (int i = 0; i < n+m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	int rolls = bfs();
	cout << rolls;
}
