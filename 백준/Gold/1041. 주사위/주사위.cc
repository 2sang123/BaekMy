#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll n;

ll twos(vector<int> dice)
{
	ll m = 1e9;
	for (int j = 0; j < 6; ++j) {
		for (int i = j + 1; i < 6; ++i) {
			// 두 면이 서로 마주 보지 않는 경우에만 합을 계산
			if (j + i != 5) 
			{
				m = min(m, (ll)dice[j] + dice[i]);
			}
		}
	}
	return m;
}

ll threes(vector<int> dice)
{
	ll m = 1e9;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			for (int k = j+1; k < 6; k++)
			{
				if (i + j != 5 && i + k != 5 && j + k != 5)
				{
					m = min(m, (ll)dice[i] + dice[j] + dice[k]);
				}
			}
		}
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int> dice(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> dice[i];
	}
	ll ans = 0;
	if (n == 1)
	{
		ll sum = 0;
		for (int i = 0; i < 6; i++)
		{
			sum += dice[i];
		}
		ans = sum - *max_element(dice.begin(), dice.end());
		cout << ans;
		return 0;
	}
	ll twoside = twos(dice);
	ll threeside = threes(dice);
	if (n == 2)
	{
		ans = twoside * 4 + threeside * 4;
		cout << ans;
		return 0;
	}
	ll oneside = *min_element(dice.begin(), dice.end());
	if (n > 2)
	{
		ll ei = n - 1;
		ll fi = n - 2;
		ans = threeside * 4 + (twoside * (4 * (ei*2-1))) + (oneside * ((4 + (5 * fi)) * fi));
		cout << ans;
	}
}
