#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> apps;
vector<int> downs;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	apps.resize(n);
	downs.resize(n);
	vector<int> dp(10001, 0);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> apps[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> downs[i];
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 10000; j >= downs[i]; j--) 
		{
			dp[j] = max(dp[j], dp[j - downs[i]] + apps[i]);
		}
	}

	for (int cost = 0; cost <= 10000; cost++) 
	{
		if (dp[cost] >= m) 
		{
			cout << cost;
			break;
		}
	}
}
