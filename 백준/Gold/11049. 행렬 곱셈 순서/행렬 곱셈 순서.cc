#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int n;
int dp[501][501];
int p[501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		if (i == 0) p[0] = arr[i].first;
		p[i + 1] = arr[i].second;
	}

	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			dp[i][j] = 1e9;
			for (int k = i; k < j; k++) {
				int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}
	cout << dp[1][n] << '\n';
}
