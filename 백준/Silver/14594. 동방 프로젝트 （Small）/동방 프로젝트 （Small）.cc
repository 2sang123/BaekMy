#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<bool> rooms(n, false);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = x-1; j < y-1; j++)
		{
			rooms[j] = true;
		}
	}
	int cnt = 0;
	for (auto a : rooms)
	{
		if (!a) cnt++;
	}
	cout << cnt;
}
