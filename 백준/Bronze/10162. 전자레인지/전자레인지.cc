#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int t;

tuple<int,int,int> buttons(int a, int b, int c, int time)
{
	if (time >= 300)
	{
		return buttons(a + 1, b, c, time - 300);
	}
	else if (time < 300 && time >= 60)
	{
		return buttons(a, b + 1, c, time - 60);
	}
	else if (time >= 10 && time < 60)
	{
		return buttons(a, b, c + 1, time - 10);
	}
	return { a, b,c };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	if (t % 10 > 0)
	{
		cout << -1;
	}
	else
	{
		auto [a,b,c] = buttons(0, 0, 0, t);
		cout << a << ' ' << b << ' ' << c << ' ';
	}
}
