#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int test = n;
	vector<int> arr(10);
	while (test > 0)
	{
		int num = test % 10;
		test /= 10;
		arr[num]++;
	}
	int out = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (i == 6 || i == 9)
		{
			int p = arr[6] + arr[9];
			if (p % 2 == 0)
			{
				out = max((p/ 2), out);
			}
			else
			{
				out = max((p / 2) + 1, out);
			}			
		}
		else
			out = max(arr[i], out);
	}
	cout << out;
}
