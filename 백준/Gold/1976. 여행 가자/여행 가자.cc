#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
vector<int> parent;
vector<int> ranks;

void initialize(int n) {
	parent.resize(n + 1);
	ranks.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void union_sets(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		if (ranks[a] < ranks[b]) {
			swap(a, b);
		}
		parent[b] = a;
		if (ranks[a] == ranks[b]) {
			ranks[a]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	initialize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int c;
			cin >> c;
			if (c == 1)
			{
				union_sets(i+1, j+1);
			}
		}
	}
	int p;
	int check;
	for (int i = 0; i < m; i++)
	{
		cin >> p;
		if (i == 0)
		{
			check = find(p);
		}
		else
		{
			if (check != find(p))
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}
