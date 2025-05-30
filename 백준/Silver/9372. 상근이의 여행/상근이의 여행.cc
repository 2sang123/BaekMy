#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin >> t;
	while (t--)
	{
		vector<vector<int>> edges(1001, vector<int>(1001, 0));
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
		}
		cout << n - 1 << '\n';
	}
}
