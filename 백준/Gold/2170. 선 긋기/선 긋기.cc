#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>
using namespace std;
#define ll long long
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	pair <ll, ll> p;
	vector<pair<ll, ll>> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> p.first >> p.second;
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end());
	ll start = vec[0].first;
	ll end = vec[0].second;
	ll len = 0;
	for (int i = 0; i < n; i++)
	{
		if (end > vec[i].first&& end<=vec[i].second)
		{
			end = vec[i].second;
		}
		else if (end <= vec[i].first)
		{
			len += end - start;
			start = vec[i].first;
			end = vec[i].second;
		}
	}
	len += end - start;
	cout << len;
}
