#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(n));
	vector<vector<ll>> sums(n+1, vector<ll>(n+1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + arr[i][j];

		}
	}

	int sx, sy, ex, ey;
	for (int i = 0; i < m; i++)
	{
		cin >> sx >> sy >> ex >> ey;
		cout << sums[ex][ey] - sums[sx - 1][ey] - sums[ex][sy - 1] + sums[sx - 1][sy - 1] << '\n';
	}
}
