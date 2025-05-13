#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
void zerobase(vector<long long> arr)
{
	int start = 0;
	int end = arr.size() - 1;
	long long pmax = 30000000000;
	int checkf = 0;
	int checkb = 0;
	while (start < end)
	{
		long long out = arr[start] + arr[end];

		if (abs(out) < abs(pmax))
		{
			pmax = out;
			checkf = start;
			checkb = end;
		}

		if (out < 0)
		{
			start++;
		}
		else if (out > 0)
		{
			end--;
		}
		else
		{
			break;
		}
	}
	cout << arr[checkf] << ' ' << arr[checkb];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<long long> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	zerobase(vec);

}
