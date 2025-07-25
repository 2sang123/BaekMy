#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int check(vector<string> s)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			if (i + 1 < s.size())
			{
				if (s[i][j] != s[i + 1][j])
				{
					cnt++;
					break;
				}
			}
			else break;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	vector<string> sarr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> sarr[i];
	}
	sort(sarr.begin(), sarr.end());
	int c = check(sarr);
	cout << c+1;
}
