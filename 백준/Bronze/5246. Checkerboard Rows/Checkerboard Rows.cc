#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		vector<vector<int>> vec(8, vector<int>(8));
		for (int i = 0; i < a; i++)
		{
			int x, y;
			cin >> x >> y;
			vec[x-1][y-1]++;
		}
		int cnt = 0;
		for (int i = 0; i < 8; i++)
		{
			int c = 0;
			for (int j = 0; j < 8; j++)
			{
				if (vec[j][i] > 0)
				{
					c++;
				}
			}
			cnt = max( cnt, c );
		}
		cout << cnt << '\n';
	}
}
