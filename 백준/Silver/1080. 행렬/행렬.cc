#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int reNum(int num)
{
	if (num == 1) return 0;
	else if (num == 0) return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
		
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<int>> target(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			cin >> a;
			arr[i][j] = a - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			cin >> a;
			target[i][j] = a - '0';
		}
	}
	int cnt = 0;
	if ((n < 3 || m < 3) && arr !=target)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i <= n-3; i++)
	{
		for (int j = 0; j <= m-3; j++)
		{
			if (arr[i][j] != target[i][j])
			{
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						arr[i + k][j + l] = reNum(arr[i + k][j + l]);
					}
				}
				cnt++;
			}
		}
	}
	if (arr == target)
	{
		cout << cnt;
	}
	else cout << -1;
}