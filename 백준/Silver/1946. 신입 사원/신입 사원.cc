#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--)
	{
		vector<pair<int, int>> member;
		int n;
		int cnt = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int test1, test2;
			cin >> test1 >> test2;
			member.push_back({ test1, test2 });
		}
		sort(member.begin(), member.end());
		int cutline = member.front().second;
		for (auto& m : member)
		{
			if (m.second < cutline)
			{
				cnt++;
				cutline = m.second;
			}
		}
		cout << cnt << '\n';
	}
}
