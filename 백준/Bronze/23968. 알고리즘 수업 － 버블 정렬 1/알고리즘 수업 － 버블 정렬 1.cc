#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int cnt = 0;
	
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				cnt++;
				if (cnt == k)
				{
					cout << arr[j+1] << ' ' << arr[j];
					return 0;
				}
				swap(arr[j], arr[j+1]);
			}
		}
	}
	cout << -1;
}