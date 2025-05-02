#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<int> weight;
bool visited[31][15001];
bool possible[15001];

void dfs(int idx, int sum) {
	if (visited[idx][sum]) return;
	visited[idx][sum] = true;
	possible[sum] = true;

	if (idx == n) 
	{
		return;
	}

	dfs(idx + 1, sum);                       
	dfs(idx + 1, sum + weight[idx]);         
	dfs(idx + 1, abs(sum - weight[idx]));    
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	weight.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	dfs(0, 0);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		if (t > 15000) cout << "N ";
		else if (possible[t])
			cout << "Y ";
		else
			cout << "N ";
	}
}
