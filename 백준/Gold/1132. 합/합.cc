#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector<ll> alpha(10);
vector<bool> nzero(10, false);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		nzero[s[0] - 'A'] = true;
		long long num =1;
		for (int j = s.size()-1; j >=0 ; j--)
		{
			alpha[s[j] - 'A'] += num;
			num *= 10;
		}
	}
	bool f = false;
	for (int i = 0; i < 10; i++)
	{
		if (!alpha[i])
		{
			f = true;
		}
	}
	if (!f)
	{
		ll midx = 1e18;
		int idx;
		for (int i = 0; i < 10; i++)
		{
			if (!nzero[i] && alpha[i] < midx)
			{
				midx = alpha[i];
				idx = i;
			}
		}
		alpha[idx] = 0;
	}
	sort(alpha.begin(), alpha.end(), greater<>());
	ll out = 0;
	int j = 9;
	for (int i = 0; i < 10; i++)
	{
		out += alpha[i] * j;
		j--;
	}
	cout << out;
}
