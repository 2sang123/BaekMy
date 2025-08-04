#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int> lines(n+1);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		lines[a] = i;
	}
	vector<int> lis;
	int m_len = 1;
	int c_len = 1;
	for (int i = 2; i <= n; i++)
	{
		if (lines[i] > lines[i - 1])
		{
			c_len++;
		}
		else
		{
			c_len = 1;
		}
		m_len = max(m_len, c_len);
	}
	cout << n - m_len;
}
