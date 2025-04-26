#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, m;
ll binary()
{
	ll start = 0;
	ll end = n * n;
	ll mid = start + (end - start) / 2;
	ll answer = 0;
	while (start <= end)
	{
		ll cnt = 0;
		mid = start + (end - start) / 2;
		for (ll i = 1; i <= n; i++)
		{
			cnt += min((ll)(mid / i), n);
		}
		if (cnt >= m)
		{
			answer = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return answer;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cout << binary();
}
