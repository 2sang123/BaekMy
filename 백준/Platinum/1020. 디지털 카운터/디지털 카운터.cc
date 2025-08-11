#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;
#define ll long long
const int FLAG[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
vector<vector<ll>> dp;
vector<int> number;
ll num;
int n;

ll p10(int k)
{
	ll res = 1;
	for (int i = 0; i < k; i++) res *= 10;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	num = stoll(s);
	n = s.size();
	number.resize(n);

	for (int i = 0; i < n; i++)
	{
		number[i] = s[i] - '0';
	}
	int max_len = n + 5;
	dp.assign(max_len + 1, vector <ll>((max_len * 7) + 1, LLONG_MAX));
	
	for (int i = 0; i < 10; i++)
	{
		dp[1][FLAG[i]] = min(dp[1][FLAG[i]], (ll)i);
	}
	
	for (int k = 2; k <= n; k++)
	{
		for (int i = 2; i < 8; i++)
		{
			int start = (k - 1) * 2;
			int end = (k - 1) * 7 + 1;
			for (int j = start; j < end; j++)
			{
				if (dp[k - 1][j] == LLONG_MAX) continue;
				if (dp[1][i] == LLONG_MAX) continue;
				
				dp[k][i + j] = min(dp[k][i + j], dp[k - 1][j] + p10(k - 1) * dp[1][i]);
			}
		}
	}
	ll res = LLONG_MAX;
	int units = number[n - 1];
	for (int i = 0; i < 10; i++)
	{
		if (FLAG[units] == FLAG[i] && units != i)
		{
			if (i > units)
			{
				res = min(res, (ll)(i - units));
			}
			else
			{
				res = min(res, p10(n) + i - units);
			}
		}
	}
	
	int cnt = FLAG[number[n - 1]];
	
	for (int i = 2; i <= n; i++)
	{
		ll digit = num % p10(i);
		cnt += FLAG[number[n - i]];
		
		for (int j = 0; j < 10; j++)
		{
			if (cnt - FLAG[j] >= 0)
			{
				ll ps = p10(i - 1) * j;
				ll target = dp[i - 1][cnt - FLAG[j]];

				if (digit != ps + target && target != LLONG_MAX)
				{
					ll val = ps + target - digit;
					if (val <= 0)
					{
						val += p10(n);
					}
					res = min(res, val);
				}
			}
		}
	}
	if (res == LLONG_MAX) 
	{
		res = p10(n);
	}
	cout << res;
}
