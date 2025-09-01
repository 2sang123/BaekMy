#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<int,int>> vec(n);
	vector<int> rank(n,1);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec[i].first > vec[j].first && vec[i].second > vec[j].second)
			{
				rank[j]++;
			}
		}
	}

	for (auto a : rank)
	{
		cout << a << ' ';
	}
}
