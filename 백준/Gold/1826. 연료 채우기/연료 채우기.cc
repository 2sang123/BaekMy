#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<ll, ll>> gas(n);
	for (int i = 0; i < n; i++)
	{
		cin >> gas[i].first >> gas[i].second;
	}
	int L, P;
	cin >> L >> P;
	sort(gas.begin(), gas.end());
	priority_queue<ll> pq;
	int stp = 0;
	int cur = 0;
	int station = 0;
	while (cur + P < L)
	{
		while (station < n && gas[station].first <= cur + P)
		{
			pq.push(gas[station].second);
			station++;
		}
		if (pq.empty())
		{
			cout << -1;
			return 0;
		}
		P += pq.top();
		pq.pop();
		stp++;
	}
	cout << stp;
}
