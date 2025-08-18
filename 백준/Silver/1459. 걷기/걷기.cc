#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long x, y;
long long w, s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> w >> s;
	if (w > s)
	{
		if ((max(x, y)-min(x,y)) % 2 == 0)
		{
			cout << max(x, y) * s;
		}
		else
		{
			cout << ((max(x, y)-1) * s)+w;
		}
		return 0;
	}
	else if (w * 2 > s)
	{
		if (x == y)
		{
			cout << x * s;
			return 0;
		}
		else
		{
			long long sload = min(x, y) * s;
			long long wload = (max(x, y) - min(x, y)) * w;
			cout << sload + wload;
			return 0;
		}

	}
	else
	{
		cout << (x + y) * w;
	}
}
