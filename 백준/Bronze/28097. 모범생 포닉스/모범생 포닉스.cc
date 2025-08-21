#include <iostream>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int day = 0, time = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		time += a;
		if (i != n - 1) time += 8;
		while (time >= 24)
		{
			day++;
			time -= 24;
		}
	}
	cout << day << ' ' << time;
}
