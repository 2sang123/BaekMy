#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPal(vector<int>& vec, int s, int e)
{
	int left = s;
	int right = e;
	while (left < right)
	{
		if (vec[left] != vec[right]) return false;
		++left;
		--right;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int ques;
	cin >> n;
	vector<int> arr(n);
	vector<vector<int>> pals(n, vector<int>(n,-1));
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		pals[i][i] = 1;
	}
	cin >> ques;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			int e = j + i - 1;
			if (arr[j] == arr[e])
			{
				if (i == 2 || pals[j + 1][e - 1] == 1)
				{
					pals[j][e] = 1;
				}
			}
		}
	}

	for (int i = 0; i < ques; i++)
	{
		int s, e;
		cin >> s >> e;
		if (pals[s - 1][e - 1] == -1)
		{
			pals[s - 1][e - 1] = isPal(arr, s - 1, e - 1);
		}
		cout << pals[s - 1][e - 1] << '\n';
	}
}
