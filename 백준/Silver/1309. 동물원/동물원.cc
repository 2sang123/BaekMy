#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	vector<long long> dp(100005);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <=n; i++)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i - 2])%9901;
	}
	cout << dp[n];
}
