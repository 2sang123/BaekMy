#include <iostream>
#include <cmath>
using namespace std;

int x, y, w, h, p;

bool squre(int tx, int ty)
{
	if (tx >= x && tx <= x + w && ty >= y && ty <= y + h)
	{
		return true;
	}
	return false;
}

bool halfcir1(int tx, int ty)
{
	int rad = pow(h / 2,2);
	if (pow(tx-x,2)+pow(ty-(y+(h/2)),2) <= rad)
	{
		return true;
	}
	return false;
}

bool halfcir2(int tx, int ty)
{
	int rad = pow(h / 2, 2);
	if (pow(tx - (x+w), 2) + pow(ty - (y + (h / 2)), 2) <= rad)
	{
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> w >> h >> x >> y >> p;
	int cnt = 0;
	for (int i = 0; i < p; i++)
	{
		int cx, cy;
		cin >> cx >> cy;
		if (squre(cx, cy) || halfcir1(cx, cy) || halfcir2(cx,cy))
		{
			cnt++;
		}
	}
	cout << cnt;
}
