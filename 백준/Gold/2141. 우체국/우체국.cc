#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<int, int>> arr(n);
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}
	sort(arr.begin(), arr.end());
	long long target = 0;
	for (int i = 0; i < n; i++)
	{
		target += arr[i].second;
		if (target >= (sum+1) / 2)
		{
			cout << arr[i].first;
			return 0;
		}
	}
}
