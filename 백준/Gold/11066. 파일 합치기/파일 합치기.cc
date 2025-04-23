#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int n;
int dp[501][501];
int sums[501];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		
		sums[0] = arr[0];
		
		for (int i = 1; i < n; i++)
		{
			sums[i] = sums[i - 1] + arr[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= n-i; j++)
			{
				int en = i + j - 1;
				dp[j][en] = 1e9;
				
				for (int k = j; k < en; k++)
				{
					int cost = dp[j][k] + dp[k + 1][en];
					int sum = 0;
					if (j > 0)
					{
						sum = sums[en] - sums[j - 1];
					}
					else sum = sums[en];
					dp[j][en] = min(dp[j][en], cost+sum);
				}
			}
		}

		cout << dp[0][n - 1]<<'\n';
	}

}
