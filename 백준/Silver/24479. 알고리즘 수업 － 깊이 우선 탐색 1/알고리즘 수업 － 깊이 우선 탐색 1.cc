#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[100001];
vector<bool> visited(100001, false);
int result[100001];
int cnt = 0;

void dfs(int r) {
	if (visited[r] == true) {
		return;
	}

	visited[r] = true;
	cnt++;
	result[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r;
	
	cin>>n>>m>>r;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n; i++) {
		cout << result[i]<<'\n';
	}

}
