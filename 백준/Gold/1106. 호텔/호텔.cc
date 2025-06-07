#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int c, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c >> n;
	vector<int> promote(n + 1);
	vector<int> guest(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> promote[i] >> guest[i];
	}
	vector<int> dp(100001, 0);
	for (int i = 0; i < n; i++) 
	{
		for (int j = promote[i]; j <= 100001; j++) 
		{
			dp[j] = max(dp[j], dp[j - promote[i]] + guest[i]);
		}
	}
	for (int i = 0; i < 100001; i++)
	{
		if (dp[i] >= c)
		{
			cout << i;
			break;
		}
	}
}
