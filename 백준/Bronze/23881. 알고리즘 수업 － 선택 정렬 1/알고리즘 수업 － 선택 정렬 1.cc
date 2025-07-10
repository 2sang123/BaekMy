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
	int a1, a2 = 0;
	
	for (int i = n-1; i > 0; i--)
	{
		int b = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] > arr[b])
			{
				b = j;
			}
		}
		if (b != i)
		{
			cnt++;
			if (cnt == k)
			{
				cout << arr[i] << ' ' << arr[b];
				return 0;
			}
			swap(arr[i], arr[b]);
		}
	}
	cout << -1;
}