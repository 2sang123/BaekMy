#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int n;

int gcd(int s, int r)
{
	if (r == 0)
	{
		return s;
	}
	return gcd(r, s % r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	map<pair<int, int>, int> points;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		
		int g = gcd(abs(x), abs(y));
		x /= g;
		y /= g;
		points[{x, y}]++;
	}

	auto max_it = points.begin();

	for (auto it = points.begin(); it != points.end(); it++) 
	{
		if (it->second > max_it->second) 
		{
			max_it = it;
		}
	}
	cout << max_it->second;
}