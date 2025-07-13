#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long mod = 1000000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	// [수의 길이] [마지막 자릿수] [지금까지 사용한 숫자들의 집합] 
	vector<vector<vector<long long>>> dp(101, vector<vector<long long>>(10, vector<long long>(1024, 0)));
	for (int i = 1; i <= 9; i++) // 길이가 1인수는 1~9만 가능
	{
		dp[1][i][1 << i] = 1;
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int d = 0; d <= 9 ; d++)
		{
			for (int b = 0; b < 1024; b++)
			{
				// d의 앞 자리는 d -1 과 d+1 가능
				if (d > 0)
				{
					dp[i][d][b | (1<<d)] += (dp[i - 1][d - 1][b])%mod;
				}
				if (d < 9)
				{
					dp[i][d][b | (1 << d)] += (dp[i - 1][d + 1][b])%mod;
				}
			}
		}
	}

	long long res = 0;
	// 길이가 n이고, bitmask가 1023인 것만 골라서 합
	for (int i = 0; i <= 9; i++)
	{
		res = (res + dp[n][i][1023]) % mod;
	}
	cout << res;
}
