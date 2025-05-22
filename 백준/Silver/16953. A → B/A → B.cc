#include <iostream>
#include <unordered_map>
#include <queue>
#include<limits>
using namespace std;

int a, b;

unordered_map<int, bool> visited;
unordered_map<int, int> moves;
void bfs()
{
	queue<int> q;
	q.push(b);
	visited[b] = true;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		
		if (node > a)
		{
			if (node % 10 == 1)
			{
				int cut = node / 10;
				if (cut >= a && !visited[cut])
				{
					visited[cut] = true;
					moves[cut] = moves[node] + 1;
					q.push(cut);
				}
			}
			
			if (node % 2 == 0)
			{
				int half = node / 2;
				if (half >= a &&!visited[half])
				{
					visited[half] = true;
					moves[half] = moves[node] + 1;
					q.push(half);
				}
			}
		}
		else if (node == a)
		{
			visited[a] = true;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;
	visited[a] = false;
	bfs();
	if (visited[a])
		cout << moves[a] + 1;
	else
		cout << -1;
}
