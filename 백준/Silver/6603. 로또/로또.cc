#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	while (cin>>n)
	{
		if (n == 0) return 0;
		vector<int> arr(n);
		vector<int> mask(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		fill(mask.begin(), mask.begin() + 6, 1);
		do
		{
			for (int i = 0; i < n; i++)
			{
				if (mask[i]) cout << arr[i] << " ";
			}
			cout << '\n';
		} while (prev_permutation(mask.begin(), mask.end()));
		cout << '\n';
	}
}
