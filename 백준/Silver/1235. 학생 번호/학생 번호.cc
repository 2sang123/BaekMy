#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int n;
int check(vector<string> sarr)
{
	set<string> sss;
	int lim = sarr[0].size() - 1;
	int ans = 0;
	while (sss.size() != n)
	{
		if (sss.size() == n) break;
		for (int i = 0; i < n; i++)
		{
			string in;
			for (int j = sarr[0].size() - 1; j >= lim; j--)
			{
				in += sarr[i][j];
				ans = in.size();
			}
			sss.insert(in);
		}
		if (sss.size() == n)
		{
			return ans;
		}
		else
		{
			sss.clear();
			lim--;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<string> sarr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> sarr[i];
	}
	cout << check(sarr);
}
