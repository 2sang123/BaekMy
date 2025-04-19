#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> lis(n, 1);
	vector<int> lds(n, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	for (int i = n-2; i >= 0; i--)
	{
		for (int j = n-1; j > i; j--)
		{
			if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
			{
				lds[i] = lds[j] + 1;
			}
		}
	}

	int out = 0;
	for (int i = 0; i < n; i++)
	{
		out = max(out, lis[i] + lds[i]);
	}
	cout << out-1;
}
