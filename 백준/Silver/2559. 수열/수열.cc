#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> temp;
int a;
int mx =INT32_MIN;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		temp.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		if (i + k <= n)
		{
			for (int j = 0; j < k; j++)
			{
				sum += temp[i + j];
			}
		}
		else break;
		
		mx = max(sum, mx);
	}
	cout << mx;
}
