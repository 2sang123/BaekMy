#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int n;

double grad(int t, int th, int m, int mh)
{
	return (double)(th - mh) / (t - m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	vector<int> heights(n);
	int max_see = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> heights[i];
	}

	for (int i = 0; i < n; i++)
	{
		int h = heights[i];
		double lgrad = 1e9, rgrad = -1e9;
		int see = 0;
		for (int left = i-1; left >= 0; left--)
		{
			double tgrad = grad(left + 1, heights[left], i+1, h);
			if (tgrad < lgrad)
			{
				lgrad = tgrad;
				see++;
			}
		}

		for (int right = i+1; right < n; right++)
		{
			double tgrad = grad(right + 1, heights[right], i+1, h);
			if (tgrad > rgrad)
			{
				rgrad = tgrad;
				see++;
			}
		}
		max_see = max(see, max_see);
	}

	cout << max_see;
}