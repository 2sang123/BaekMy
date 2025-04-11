#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;
int n, m;
int b;
vector<vector<int>> arr;


int main() {
    
    cin >> n >> m >> b;
	int defb = b;
	arr.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int time = 1e9;
	int height = -1;
	for (int h = 0; h < 257; h++)
	{
		int digCnt = 0;
		int putCnt = 0;
		b = defb;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int diff = arr[i][j] - h;

				if (diff > 0)
				{
					digCnt += diff * 2;
					b += diff;
				}
				else if (diff < 0)
				{
					putCnt += -diff;
					b -= -diff;
				}
			}
		}
		int total = digCnt + putCnt;
		if ((time > total||(total==time&&h>height)) && b>=0)
		{
			time = digCnt + putCnt;
			height = max(h, height);
		}
	}
	cout << time << ' ' << height;
}
