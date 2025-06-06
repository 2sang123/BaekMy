#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int r;
int q;
const int maxx = 100003;
vector<int> graphs[maxx];
vector<int> tree[maxx];
int par[maxx];
int dp[maxx];
void makeTree(int cur, int parent)
{
	par[cur] = parent;
	for (auto next : graphs[cur])
	{
		if (next != parent)
		{
			tree[cur].push_back(next);
			makeTree(next, cur);
		}
	}
}

void countTree(int cur)
{
	dp[cur] = 1;
	for (int node : tree[cur])
	{
		countTree(node);
		dp[cur] += dp[node];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> q;
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		graphs[u].push_back(v);
		graphs[v].push_back(u);
	}
	makeTree(r, -1);
	countTree(r);
	for (int i = 0; i < q; i++)
	{
		int ask = 0;
		cin >> ask;
		cout << dp[ask]<<'\n';
	}
}
