#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll func(long long x)
{
	ll res = 0;
	for (int i = 0; i < 61; i++)
	{
		ll cycle = 1LL << (i + 1);
		ll once = 1LL << i;
		ll fcycle = (x + 1) / cycle;
		ll remain = (x + 1) % cycle;
		res += fcycle * once;
		if (remain > once)
		{
			res += remain - once;
		}
	}
	return res;
}

long long a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;
	cout << func(b) - func(a - 1);
	
}