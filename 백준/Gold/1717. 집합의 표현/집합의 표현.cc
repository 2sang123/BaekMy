#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_set>
#include<string>
#include <set>
using namespace std;

int n,m;
int check, a, b;

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

	for (int i = 0; i < m; i++)
	{
		cin >> check >> a >> b;
		if (check == 0)
		{
			union_sets(a, b);
		}
		if (check == 1)
		{
			if (find(a)==find(b))
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
		}
	}
}
