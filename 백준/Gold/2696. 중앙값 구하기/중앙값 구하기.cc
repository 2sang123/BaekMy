#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		priority_queue<int> lqu;
		priority_queue<int, vector<int>, greater<int>> hqu;
		vector<int> arr;
		int out = n / 2 + 1;
		for (int i = 1; i <= n; i++)
		{
			int m = 0;
			cin >> m;
			if (lqu.empty() || m <= lqu.top()) {
				lqu.push(m);
			}
			else {
				hqu.push(m);
			}


			if (lqu.size() > hqu.size() + 1) {
				hqu.push(lqu.top());
				lqu.pop();
			}
			else if (hqu.size() > lqu.size()) {
				lqu.push(hqu.top());
				hqu.pop();
			}
			if (i % 2 == 1)
			{
				arr.push_back(lqu.top());
			}		
		}
		cout << out << '\n';
		for (int i = 0; i < arr.size(); i++)
		{
			if (i>0&&i % 10 == 0)
			{
				cout << '\n';
			}
			cout << arr[i]<<' ';
		}
		cout << '\n';
	}
}
