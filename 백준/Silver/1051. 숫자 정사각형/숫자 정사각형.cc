#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> quad;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	quad.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			quad[i][j] = c - '0';
		}
	}
	for (int size = min(n, m) - 1; size >= 0; size--) 
	{
		for (int i = 0; i + size < n; i++) 
		{
			for (int j = 0; j + size < m; j++) 
			{
				int val = quad[i][j];
				if (quad[i + size][j] == val && quad[i][j + size] == val &&
					quad[i + size][j + size] == val) 
				{
					cout << (size + 1) * (size + 1);
					return 0;
				}
			}
		}
	}
	cout << 1;
}
