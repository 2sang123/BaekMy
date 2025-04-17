#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<int> graph[10001];
bool visited[10001] = { false };

int dmove(int num)
{
	if (num * 2 >= 10000) return (num * 2) % 10000;
	return num * 2;	
}

int smove(int num)
{
	if (num == 0) return 9999;
	return num - 1;
}

int lmove(int num)
{
	return (num % 1000) * 10 + num / 1000;
}

int rmove(int num)
{
	return (num % 10) * 1000 + num / 10;
}

string bfs(int start, int target)
{
	fill(visited, visited + 10000, false);
	queue<pair<int,string>> q;
	q.push({ start,"" });
	visited[start] = true;
	while (!q.empty())
	{
		int node = q.front().first;
		string cmd = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int in;
			char moves;
			switch (i)
			{
			case 0:
				in = dmove(node);
				moves = 'D';
				break;
			case 1:
				in = smove(node);
				moves = 'S';
				break;
			case 2:
				in = lmove(node);
				moves = 'L';
				break;
			case 3:
				in = rmove(node);
				moves = 'R';
				break;
			}
			if (!visited[in])
			{
				visited[in] = true;
				string nexts = cmd + moves;
				if (in == target)
				{
					return nexts;
				}
				q.push({ in, nexts });
			}

		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		string move = bfs(n, m);
		cout << move << '\n';
	}
}
