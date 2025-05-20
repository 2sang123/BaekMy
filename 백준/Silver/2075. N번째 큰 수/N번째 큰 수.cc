#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	priority_queue<int, vector<int>, greater<>> qu;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			qu.push(num);
			if (qu.size() > n) qu.pop();
		}
	}
	cout << qu.top();
}
