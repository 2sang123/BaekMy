#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	cin >> n;
	vector<int> dp(100005, 1e9);
	dp[0] = 0;
	for (int i = 2; i <= n; i++) 
	{
		if (i >= 2 && dp[i - 2] != 1e9)
			dp[i] = min(dp[i], dp[i - 2] + 1);
		if (i >= 5 && dp[i - 5] != 1e9)
			dp[i] = min(dp[i], dp[i - 5] + 1);
	}
	if (dp[n] == 1e9)
	{
		cout << -1;
	}
	else cout << dp[n];
}
