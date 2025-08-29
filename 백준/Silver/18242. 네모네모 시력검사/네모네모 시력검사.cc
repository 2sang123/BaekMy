#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	bool check = false;
	pair<int, int> p;
	int len = 0;
	int flen = 0;
	for (int i = 0; i < n; i++)
	{
		len = 0;
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '#')
			{
				arr[i][j] = 1;
				len++;
				if (!check)
				{
					p = { i, j };
					check = true;
				}
			}
		}
		flen = max(flen, len);
	}
	string word = "RIGHT";
	for (int i = p.first; i < p.first+flen; i++)
	{
		for (int j = p.second; j < p.second+flen; j++)
		{
			if (arr[i][j]!=1)
			{
				if (i == p.first && j!=p.second)
				{
					word = "UP";
					break;
				}
				else if (i != p.first && j == p.second)
				{
					word = "LEFT";
					break;
				}
				else if (i == p.first + flen - 1 && j!=p.second+flen-1)
				{
					word = "DOWN";
					break;
				}
			}
		}
	}
	cout << word;
}
