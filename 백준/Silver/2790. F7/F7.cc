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
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<>());
	int lim = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] + i + 1 > lim)
		{
			lim = arr[i] + i + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] + n >= lim) cnt++;
	}
	cout << cnt++;
}