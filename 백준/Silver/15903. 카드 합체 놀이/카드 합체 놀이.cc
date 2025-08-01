#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
#define ll long long
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		pq.push(a);
	}
	for (int i = 0; i < m; i++)
	{
		ll a1 = pq.top();
		pq.pop();
		ll a2 = pq.top();
		pq.pop();
		pq.push(a1 + a2);
		pq.push(a1 + a2);
	}
	
	ll sum = 0;
	int s = pq.size();
	for (int i = 0; i < s; i++)
	{
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}
