#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int circle(int x1, int y1, int x2, int y2, int r1, int r2)
{
	double r = r1 + r2;
	double dx = x1 - x2;
	double dy = y1 - y2;
	double dist = sqrt(dx * dx + dy * dy);
	double diff = abs(r1 - r2);
	if (dist == r || dist == diff)
	{
		return 1;
	}
	else if (diff < dist && dist < r)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int main() 
{
	int t;
	cin >> t;

	pair<int, int> p1, p2;
	int r1, r2;

	while (t--)
	{
		int out;
		cin >> p1.first >> p1.second >> r1 >> p2.first >> p2.second >> r2;
		if (p1 == p2 && r1 == r2)
		{
			out = -1;
		}
		else
		{
			out = circle(p1.first, p1.second, p2.first, p2.second, r1, r2);
		}

		cout << out << '\n';
	}
}
