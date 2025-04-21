#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, c;

bool canInstall(vector<ll> &v, ll con)
{
	ll cnt = 1;
	ll x = v.front();

	for (ll i = 1; i < n; i++)
	{
		if (v[i] - x >= con)
		{
			cnt++;
			x = v[i];
		}
	}

	return cnt >= c;
}

void binary(vector<ll> &h)
{
	ll left = 0;
	ll right = h.back() - h.front();

	ll len = 1;
	while (left <= right)
	{
		ll mid = left + (right - left) / 2;
		bool poss = canInstall(h, mid);
		if (poss)
		{
			len = max(len, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << len;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	vector<ll> home(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> home[i];
	}
	sort(home.begin(), home.end());
	binary(home);
}
